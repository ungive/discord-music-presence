/**
 * @file    main.cc
 * @authors Stavros Avramidis
 */

#ifndef VERSION
#define VERSION "v1.4.0"
#endif

#pragma message("Building version:" VERSION)

/* C++ libs */
#include <atomic>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <locale>
#include <stack>
#include <string>
#include <thread>
/* Qt */
#include <QAction>
#include <QApplication>
#include <QDesktopServices>
#include <QMenu>
#include <QMessageBox>
#include <QtNetwork>
#include <QSystemTrayIcon>
#include <QTimer>
/* local libs*/
#include "httplib.hh"
#include "json.hh"

#define DISCORD_REQUIRE(x) assert(x == DiscordResult_Ok)

#ifdef WIN32
#include "windows_api_hook.hh"
#elif defined(__APPLE__) or defined(__MACH__)
#include "osx_api_hook.hh"
#else
#error "Not supported target"
#endif

#include "discord_game_sdk.h"

// TIDAL logo from the official TIDAL "artist" page: https://tidal.com/browse/artist/6712922
static const std::string TIDAL_LOGO_URL = "https://resources.tidal.com/images/d156d3e0/a5cd/4066/8c36/b13edab7bbcc/750x750.jpg";

#define CURRENT_TIME std::time(nullptr)
#define HIFI_ASSET "hifi"

static long long APPLICATION_ID = 1205619376275980288;
static const int RPC_IDLE_TIMEOUT_SECONDS = 5;

std::atomic<bool> isPresenceActive;
static char *countryCode = nullptr;

static std::string currentStatus;
static std::mutex currentSongMutex;

struct Song {
  enum AudioQualityEnum {
	master, hifi, normal
  };
  std::string title;
  std::string artist;
  std::string album;
  std::string url;
  std::string cover_id;
  char id[10];
  int64_t starttime;
  int64_t runtime;
  uint64_t pausedtime;
  uint64_t repeatCount;
  uint_fast8_t trackNumber;
  uint_fast8_t volumeNumber;
  bool isPaused = false;
  AudioQualityEnum quality;
  bool loaded = false;

  void setQuality(const std::string &q) {
	if (q == "HI_RES") {
	  quality = master;
	} else {
	  quality = hifi;
	}
  }

  inline bool isHighRes() const noexcept { return quality == master; }

  inline int64_t endtime() const noexcept { return runtime ? starttime + runtime + pausedtime : 0; }

  friend std::ostream &operator<<(std::ostream &out, const Song &song) {
	out << song.title << " of " << song.album << " from " << song.artist << "("
		<< song.runtime << ")";
	return out;
  }
};

std::string urlEncode(const std::string &value) {
  std::ostringstream escaped;
  escaped.fill('0');
  escaped << std::hex;

  for (std::string::value_type c : value) {
	if (isalnum((unsigned char)c) || c == '-' || c == '_' || c == '.' ||
		c == '~')
	  escaped << c;
	else {
	  escaped << std::uppercase;
	  escaped << '%' << std::setw(2) << int((unsigned char)c);
	  escaped << std::nouppercase;
	}
  }
  return escaped.str();
}

struct Application {
  struct IDiscordCore *core;
  struct IDiscordUsers *users;
  bool isDiscordOK = false;
};

struct Application app;

static void updateDiscordPresence(const Song &song) {
  if (!app.isDiscordOK) return;

  struct IDiscordActivityManager *manager =
	  app.core->get_activity_manager(app.core);

  if (isPresenceActive && song.loaded && !song.isPaused) {
	struct DiscordActivityTimestamps timestamps{};
	memset(&timestamps, 0, sizeof(timestamps));
	timestamps.start = song.starttime;
	timestamps.end = song.endtime();

	struct DiscordActivity activity{
		DiscordActivityType_Listening
	};
	memset(&activity, 0, sizeof(activity));
	activity.type = DiscordActivityType_Listening;
	activity.application_id = APPLICATION_ID;
	snprintf(activity.details, 128, "%s - %s", song.title.c_str(), song.artist.c_str());
	snprintf(activity.state, 128, ""); // empty, so that the text box isn't taller than the cover image

	struct DiscordActivityAssets assets{};
	memset(&assets, 0, sizeof(assets));
	activity.timestamps = timestamps;

	// Get url of album picture
	auto cover_id_url = song.cover_id;
	std::replace(cover_id_url.begin(), cover_id_url.end(), '-', '/');
	auto cover_url = "https://resources.tidal.com/images/" + cover_id_url + "/1280x1280.jpg";
	std::cout << cover_url << "\n";

	snprintf(assets.large_image, 128, "%s", cover_url.c_str());
	snprintf(assets.large_text, 128, "Album: %s", song.album.c_str());

	snprintf(assets.small_image, 128, "%s", TIDAL_LOGO_URL.c_str());
	snprintf(assets.small_text, 128, "%s", "Streaming on TIDAL");

	if (song.id[0] != '\0') {
	  struct DiscordActivitySecrets secrets{};
	  memset(&secrets, 0, sizeof(secrets));
	  snprintf(secrets.join, 128, "%s", song.id);
	  activity.secrets = secrets;
	}
	activity.assets = assets;

	activity.instance = false;

	manager->update_activity(manager, &activity, nullptr, nullptr);
  } else {
	//        std::clog << "Clearing activity\n";
	// manager->clear_activity(manager, nullptr, nullptr);
	struct DiscordActivity activity {
	  DiscordActivityType_Listening
	};
	memset(&activity, 0, sizeof(activity));
	activity.type = DiscordActivityType_Listening;
	activity.application_id = APPLICATION_ID;
	snprintf(activity.details, 128, "Idle");
	snprintf(activity.state, 128, "");
	struct DiscordActivityAssets assets {};
	memset(&assets, 0, sizeof(assets));
	snprintf(assets.large_image, 128, "%s", TIDAL_LOGO_URL.c_str());
	snprintf(assets.large_text, 128, "%s", "TIDAL");
	activity.assets = assets;
	activity.instance = false;
	manager->update_activity(manager, &activity, nullptr, nullptr);
  }
}

static void discordInit() {
  memset(&app, 0, sizeof(app));

  IDiscordCoreEvents events;
  memset(&events, 0, sizeof(events));

  struct DiscordCreateParams params{};
  DiscordCreateParamsSetDefault(&params);
  params.client_id = APPLICATION_ID;
  params.flags = DiscordCreateFlags_NoRequireDiscord;
  params.events = &events;
  params.event_data = &app;

  auto result = DiscordCreate(DISCORD_VERSION, &params, &app.core);
  if (result == DiscordResult_Ok) {
	app.isDiscordOK = true;
  }

  auto user_manager = &app.core->get_user_manager;

  std::lock_guard<std::mutex> lock(currentSongMutex);
  currentStatus = "Connected to Discord";
}

[[noreturn]] inline void rpcLoop() {
  using json = nlohmann::json;
  using string = std::string;
  httplib::Client cli("api.tidal.com", 80, 3);
  char getSongInfoBuf[1024];
  json j;
  static Song curSong;
  int kill_timeout = 0;

  for (;;) {
	bool kill_discord = false;

	if (isPresenceActive) {
	  std::wstring tmpTrack, tmpArtist;
	  auto localStatus = tidalInfo(tmpTrack, tmpArtist);

	  // If song is playing
	  if (localStatus == playing) {
		// only init if something is playing
		if (!app.isDiscordOK) {
		  discordInit();
		  std::clog << "Discord Initialized\n";
		  if (!app.isDiscordOK) {
			std::this_thread::sleep_for(std::chrono::seconds(2));
			continue;
		  }
		}

		// if new song is playing
		if (rawWstringToString(tmpTrack) != curSong.title || rawWstringToString(tmpArtist) != curSong.artist) {
		  // assign new info to current track
		  curSong.title = rawWstringToString(tmpTrack);
		  curSong.artist = rawWstringToString(tmpArtist);

		  curSong.runtime = 0;
		  curSong.pausedtime = 0;
		  curSong.repeatCount = 0;
		  curSong.setQuality("");
		  curSong.id[0] = '\0';
		  curSong.loaded = true;

		  std::lock_guard<std::mutex> lock(currentSongMutex);
		  currentStatus = "Playing " + curSong.title;

		  // get info form TIDAL api
		  auto search_param = std::string(curSong.title + " - " + curSong.artist.substr(0, curSong.artist.find('&')));

		  sprintf(getSongInfoBuf, "/v1/search?query=%s&limit=50&offset=0&types=TRACKS&countryCode=%s",
				  urlEncode(search_param).c_str(), countryCode ? countryCode : "US");

		  std::clog << "Querying :" << getSongInfoBuf << "\n";

		  httplib::Headers headers = {{"x-tidal-token", "zU4XHVVkc2tDPo4t"}};
		  auto res = cli.Get(getSongInfoBuf, headers);

		  if (res && res->status == 200) {
			try {
			  j = json::parse(res->body);
			  for (auto i = 0u;
				   i < j["tracks"]["totalNumberOfItems"].get<unsigned>(); i++) {
				// convert title from windows and from tidal api to strings,
				// json lib doesn't support wide string so wstrings are pared as
				// strings and have the same convention errors
				auto fetched_str =
					j["tracks"]["items"][i]["title"].get<std::string>();
				auto c_str = rawWstringToString(tmpTrack);

				if (fetched_str == c_str) {
				  if (curSong.runtime == 0 || j["tracks"]["items"][i]["audioQuality"].get<std::string>()
					  == "HI_RES") { // Ignore songs with same name if you have found
					// song
					curSong.setQuality(j["tracks"]["items"][i]["audioQuality"].get<std::string>());
					curSong.trackNumber = j["tracks"]["items"][i]["trackNumber"].get<uint_fast8_t>();
					curSong.volumeNumber = j["tracks"]["items"][i]["volumeNumber"].get<uint_fast8_t>();
					curSong.runtime = j["tracks"]["items"][i]["duration"].get<int64_t>();
					curSong.cover_id = j["tracks"]["items"][i]["album"]["cover"].get<std::string>();
					curSong.album = j["tracks"]["items"][i]["album"]["title"].get<std::string>();
					sprintf(curSong.id, "%u", j["tracks"]["items"][i]["id"].get<unsigned>());

					if (curSong.isHighRes())
					  break; // keep searching for high-res version.
				  }
				}
			  }
			} catch (...) {
			  std::cerr << "Error getting info from api: " << curSong << "\n";
			}
		  } else {
			std::clog << "Did not get results\n";
		  }

#ifdef DEBUG
		  std::clog << curSong.title << "\tFrom: " << curSong.artist << "\n";
#endif

		  // get time just before passing it to RPC handlers
		  curSong.starttime =
			  CURRENT_TIME +
				  2; // add 2 seconds to be more accurate, not a chance
		  updateDiscordPresence(curSong);
		} else {
		  if (curSong.isPaused) {
			curSong.isPaused = false;
			updateDiscordPresence(curSong);

			std::lock_guard<std::mutex> lock(currentSongMutex);
			currentStatus = "Playing " + curSong.title;
		  }
		  if (CURRENT_TIME > curSong.endtime()) {
			curSong.starttime = CURRENT_TIME;
			curSong.pausedtime = 0;
			curSong.repeatCount += 1;
			updateDiscordPresence(curSong);
		  }
		}

	  } else if (localStatus == opened) {
		curSong.pausedtime += 1;
		curSong.isPaused = true;
		updateDiscordPresence(curSong);
		kill_discord = true;

		std::lock_guard<std::mutex> lock(currentSongMutex);
		currentStatus = "Paused " + curSong.title;
	  } else {
		curSong = Song();
		updateDiscordPresence(curSong);
		kill_discord = true;

		std::lock_guard<std::mutex> lock(currentSongMutex);
		currentStatus = "Waiting for Tidal";
	  }
	}

	if (app.isDiscordOK) {
	  if (!isPresenceActive) {
		kill_discord = true;
		curSong = Song();
		updateDiscordPresence(curSong);

		std::lock_guard<std::mutex> lock(currentSongMutex);
		currentStatus = "Disabled";
	  }

	  enum EDiscordResult result = app.core->run_callbacks(app.core);
	  if (result != DiscordResult_Ok) {
		std::clog << "Bad result " << result << "\n";
	  }

	  if (!kill_discord) {
		kill_timeout = 0;
	  }
	  else if (kill_timeout++ >= RPC_IDLE_TIMEOUT_SECONDS) {
		struct IDiscordActivityManager* manager = app.core->get_activity_manager(app.core);
		manager->clear_activity(manager, nullptr, nullptr);
		app.core->destroy(app.core);
		app.core = nullptr;
		app.isDiscordOK = false;
		kill_timeout = 0;
	  }
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}

int main(int argc, char **argv) {

  // allow passing a custom application id (for custom "game" title)
  if (argc == 2) {
	const char* app_id = argv[1];
	try {
	  APPLICATION_ID = std::stoll(app_id);
	}
	catch (std::exception const& ex) {
	  std::cerr << "The first argument must be a Discord application ID." << std::endl;
	  return -1;
	}
  }
  else if (argc > 2) {
	std::cerr << "Too many arguments." << std::endl;
	return -1;
  }

  // get country code for TIDAL api queries
  countryCode = getLocale();
  isPresenceActive = true;

  // Qt main app setup
  QApplication app(argc, argv);
  auto appIcon = QIcon(":assets/icon.ico");
  app.setWindowIcon(appIcon);

  QSystemTrayIcon tray(appIcon, &app);
  QAction titleAction(appIcon, "Discord Music Presence " VERSION, nullptr);
  QObject::connect(&titleAction, &QAction::triggered, [&app]() {
	QDesktopServices::openUrl(QUrl("https://github.com/jonasberge/discord-music-presence/", QUrl::TolerantMode));
  });

  QAction changePresenceStatusAction("Running", nullptr);
  changePresenceStatusAction.setCheckable(true);
  changePresenceStatusAction.setChecked(true);
  QObject::connect(&changePresenceStatusAction, &QAction::triggered,
				   [&changePresenceStatusAction]() {
					 isPresenceActive = !isPresenceActive;
					 changePresenceStatusAction.setText(isPresenceActive ? "Running" : "Disabled (click to re-enable)");
				   });

  QAction quitAction("Exit", nullptr);
  QObject::connect(&quitAction, &QAction::triggered, [&app]() {
	updateDiscordPresence(Song());
	app.quit();
  });

  QAction currentlyPlayingAction("Status: waiting", nullptr);
  currentlyPlayingAction.setDisabled(true);

  QMenu trayMenu("Discord Music Presence", nullptr);

  trayMenu.addAction(&titleAction);
  trayMenu.addAction(&changePresenceStatusAction);
  trayMenu.addAction(&currentlyPlayingAction);
  trayMenu.addAction(&quitAction);

  tray.setContextMenu(&trayMenu);

  tray.show();

  // Check for new App version
  try {

	QNetworkAccessManager *manager = new QNetworkAccessManager();
	QNetworkRequest request;
	QNetworkReply *reply = nullptr;

	QSslConfiguration config = QSslConfiguration::defaultConfiguration();
	config.setProtocol(QSsl::TlsV1_2);
	request.setSslConfiguration(config);
	request.setUrl(QUrl("https://api.github.com/repos/jonasberge/discord-music-presence/releases/latest"));
	request.setHeader(QNetworkRequest::ServerHeader, "application/json");

	reply = manager->get(request);
	QEventLoop loop;
	QObject::connect(reply, &QIODevice::readyRead, &loop, &QEventLoop::quit);
	loop.exec();
	nlohmann::json j;
	j = nlohmann::json::parse(reply->readAll().toStdString());

	if (auto version_string = j["tag_name"].get<std::string>(); true || version_string > (VERSION)) {
	  tray.showMessage("Discord Music Presence", ("New version available: " + version_string + "\nClick to download.").c_str());
	  QObject::connect(&tray, &QSystemTrayIcon::messageClicked, &app, []() {
		QDesktopServices::openUrl(QUrl("https://github.com/jonasberge/discord-music-presence/releases/latest",
									   QUrl::TolerantMode));
	  });
	}

  } catch (...) {
	//
  }

#if defined(__APPLE__) or defined(__MACH__)
  if (!macPerms())
  {
	std::cerr << "No Screen Recording Perms \n";
  }
#endif

  QTimer timer(&app);
  QObject::connect(&timer, &QTimer::timeout, &app, [&currentlyPlayingAction]() {
	std::lock_guard<std::mutex> lock(currentSongMutex);
	currentlyPlayingAction.setText("Status: " + QString(currentStatus.c_str()));
  });
  timer.start(1000);

  QObject::connect(&app, &QApplication::aboutToQuit,
				   [&timer]() { timer.stop(); });

  // discordInit();
  // std::clog << "Discord Initialized\n";

  // RPC loop call
  std::thread t1(rpcLoop);
  t1.detach();

  return app.exec();
}
