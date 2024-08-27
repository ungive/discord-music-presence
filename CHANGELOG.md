# Changelog

## 2.2.0

- Added the option to use the album cover image directly from the media player.
  You will now always have a cover image in your status,
  if your media player supplies one.
  - Media players like foobar2000 and MusicBee,
    which play local files, like MP3 and FLAC,
    will show the cover image that is embedded in the music file.
  - Media players like TIDAL, Qobuz or Deezer do not rely on an external service
    like the TIDAL API anymore to have a cover image in the status.
  - Some media players do not report the name of the album the song is from.
    Because of this, in previous versions it was impossible to tell
    which album cover image was the correct one
    and sometimes the Discord status would show the wrong image.
    With this update the status will always show the correct cover image.
  - How this works: A small version of the cover image
    (100x100, less than 50KB) is temporarily uploaded to our own service
    and stored only for the duration that the Discord status is visible.
    This has minimal impact on your internet bandwidth.
    For more information read the
    [documentation](./documentation/cover-images-proxy.md).
  - If this feature is disabled or encounters an error,
    then Music Presence falls back to the old behaviour
    and works exactly like previous versions by using
    an appropriate API service to get a cover image.
  - Music Presence only contacts our service when its enabled in the settings,
    when the Discord status is enabled and music is actively playing
    and being shared in your Discord status.
    When you stop listening,
    Music Presence disconnects after a short idle timeout,
    which can be observed in the application logs.

- The application now installs updates automatically.
  A number of checks are done before an update is actually installed,
  including but not limited to
  cryptographically strong authentication of the source.
  Read below for details.
  - This feature is enabled by default, but can be disabled in the settings.
  - Updates are downloaded from the
    [GitHub release page](https://github.com/ungive/discord-music-presence/releases),
    just like you would to manually update.
  - The following checks are made before any downloaded update is installed:
    - The [integrity](https://en.wikipedia.org/wiki/Data_integrity)
      of the downloaded update's content is verified with a SHA256 checksum.
    - The [authenticity](https://en.wikipedia.org/wiki/Message_authentication)
      of the downloaded update's content is verified
      with an Ed25519 cryptographic signature.
    - The update is only installed when the version is newer
      than the currently running version.
      This check is also authenticated with the same cryptographic signature.
  - The source code of the updater component is open-source:
    [https://github.com/ungive/libupdate](https://github.com/ungive/libupdate)
  - For more information about the security of the updater read the
    [documentation](https://github.com/ungive/discord-music-presence).
  - The update installation does not require elevated administator privileges.
  - Downloaded updates are only applied and executed on program startup.
    Whenever an update is installed,
    you are required to manually restart the application
    or wait until you run Music Presence the next time.
  - If you disable automatic updates,
    any downloaded updates will be deleted immediately.
    So in case an update was installed automatically,
    but you don't want it to be executed,
    you can simply disable the feature
    and remain using the currently installed version.
  - This feature is currently only available to Windows users,
    but Mac will get automatic updates in the future too.
  - There are a lot of features [planned](./ROADMAP.md),
    which is why automatic updates were introduced.
    Automatic updates allow me to make more frequent and smaller releases
    which can be adopted much more quickly than before.
    This feature also saves the manual download step that was necessary before
    and verifies the integrity and authenticity of the downloaded update,
    so you do not have to do it manually.
  - Because of the introduction of this update,
    each release now also has a `sha256sum.txt` and `sha256sum.txt.sig` file,
    which contain the SHA256 checksum and the Ed25519 signature respectively.
    If you want to, you can use these files to verify your download yourself,
    by following the steps
    [here](https://github.com/ungive/discord-music-presence/blob/master/documentation/automatic-updates.md).

- Made various improvements to the tray menu:
  - When clicking a checkbox, the tray menu is not closed anymore.
    That way it should be easier to change multiple settings in one go
    instead of having to reopen the menu every time after changing a setting.
  - Separated settings into two new submenus "Appearance" and "Settings".
    "Appearance" contains all settings
    in regard to what your Discord presence looks like.
    "Settings" contains all other settings.
  - Added controls for which external services are enabled and used.
    You can now enable or disable the use of the TIDAL API and MusicBrainz API.
    These services are used to get cover images,
    additional artists and other song metadata that might be missing.
    If other services are added in the future,
    controls for them will appear here.
    If an API for a specific streaming service is enabled,
    it will generally only be used
    when its respective media player is playing music.
  - Appearance settings for "Playing" and "Listening to" are retained
    when switching between them. You can now switch to one
    without losing your settings for the other.
    Before "Playing" and "Listening to" were reset to the default settings,
    whenever you switched between them.
    This has been fixed.

- Other improvements:
  - Media without an artist is not skipped anymore.
    You can now share songs from e.g. MP3 files that aren't properly tagged.
    Previously media without an artist was skipped by Music Presence.
  - Renamed the setting "Show the song title and artist on separate lines"
    to "Show the song title and artist on a single line".
  - Showing the album name on the third line in the Discord status,
    when using the "Playing" type,
    the title and artist are shown on a single line
    and showing the album name is enabled in the settings.
  - The autostart path is updated when the application starts.
    Previously, if you launched Music Presence
    from a different install location,
    autostart would appear disabled for that installation
    until enabled manually.
    This fixes that.
  - The `--launch` parameter of `launcher.exe` on Windows
    now behaves the same way as the `--launch-if-closed` parameter,
    only launching the application if it is not running already.
  - Added a `--local-launch` parameter to `launcher.exe` on Windows,
    which applies any updates that have been downloaded
    to `%LOCALAPPDATA%\Music Presence` and starts the latest version.
    To clarify, `--launch` only launches the executable that is
    in the same directory as the launcher, while `--local-launch`
    launches any installation in the local app data directory.
  - Moved the update information banner to the bottom of the tray menu.
  - Saving a backup of the settings file if it contains syntax errors,
    such that editing it does not cause it to be completely reset,
    in case any syntax errors are introduced by the user.
  - Removed the setting to enable or Discord invite notifications,
    as that notification is only shown once per installation anyway.

## 2.1.3

- Added the option to use the "Listening" activity type instead of "Playing".
  This option is **disabled by default** and must be enabled explicitly.
  The listening activity type does not show any playback duration though,
  due to Discord seemingly ignoring the timestamp fields at this time.
  The text on the large image is also put on the last line,
  so when using the "on" prefix the text that pops up
  when hovering over the album image will contain "on" as well.
  Closes [#29](https://github.com/ungive/discord-music-presence/issues/29).
- Showing all artists for songs from TIDAL, not just the main artist.
- Added the option to enable/disable the "by" prefix for the artist name.
- Added the option to enable/disable an "on" prefix for the album name.
- Added the option to enable/disable the album name.
- Added the option to enable/disable the playback duration.
- Improvements and bug fixes
  - Logging the version of Music Presence on program startup.
  - Renamed the setting `Show the name of the player after "Playing"` to
    `Show the name of the player instead of "Music"`.

## 2.1.2

- Added the option to show the name of the media player you are using after "Playing",
  so e.g. "Playing TIDAL" or "Playing Amazon Music" as an alternative to "Playing Music".
  Visit the settings to enable this feature!
- Added the option to start Music Presence at login on Windows.
  When you're updating or installing Music Presence for the first time,
  the application will be registered to start at login automatically,
  you do not have to enable this yourself
  - You can disable autostart in the settings menu of the application
    or by opening the task manager and disabling the entry for Music Presence
    under the "Autostart" tab
  - Autostart on Mac will be added in a future update
- Added a launcher executable `launcher.exe` on Windows which aids with the following:
  - Starting Music Presence multiple times will make sure it's only running once
    (if started with the Start Menu shortcut or directly with the launcher executable)
  - The uninstaller makes use of the launcher
    to close all running instances of Music Presence
    before proceeding to uninstall the old version
    and then installing the new version
    (solves [#24](https://github.com/ungive/discord-music-presence/issues/24))
  - The launcher executable takes the following command line arguments:
    - `--launch-if-closed`: Launches Music Presence if it's not running
    - `--launch`: Simply launches Music Presence, without any checks
    - `--close-all`: Closes all instances of Music Presence.
      The launcher exits once all instances of Music Presence have terminated.
    - No arguments: Behaves the same as with `--launch-if-closed` only.
    - You can start the launcher with multiple arguments
      and each of them will be evaluated in the order they were used.
      For instance, to restart Music Presence you can use
      `launcher.exe --close-all --launch`
- Media players
  - Added Windows Media Player on Windows (disabled by default)
    - The reason why it is disabled by default is
      that users might not expect media from the Windows Media Player
      to show up in their status, if they mainly use it to watch video files
  - Added more application identifiers for Apple Music on Windows
- Improvements and bug fixes
  - Added "by" prefix to artist name when title and artist are shown on separate lines,
    so that it's clear which one resembles the artist
  - Using the album artist on Windows, if it is available and the media player
    does not report any artist. Mitigates an issue with Apple Music on Windows
    (see [#20](https://github.com/ungive/discord-music-presence/issues/20))
  - Added product, copyright and version information to the main Windows executable
  - Added `--version` command line flag to print the current version
    - Also closing the application if it's called with any other command line arguments
  - In light of the new autolaunch feature on Windows
    and the possibilty that many users have added Music Presence to `shell:startup`,
    the main executable will exit if it detects that it's already running.
    Otherwise the application might be launched twice with the new update
  - Changed the Windows app icon back to the same one as the tray icon
  - Disabled requests to music APIs while Discord wasn't even connected
  - Fixed presence updates sometimes being wrongfully cancelled

## 2.1.1

- Features
  - Added option to show title and artist on separate lines
- Improvements and bug fixes
  - Fixed a problem with multiple instances of the same media player,
    where songs from those two instances would continuously conflict
    and cause the media observer to detect "changes" even though there are none
  - Fixed never clearing presence when it's queued for clearing too frequently
    (the presence is always cleared after a short delay),
    which happened a lot with the previous bug
  - Only clearing the presence once and not again, if it's already cleared
  - Clearing the presence when a Discord RPC error occurs
  - Fixed a bug with text in the presence that is only one character long,
    which would cause a Discord error and break the presence
- Other
  - Changed my username on GitHub to "ungive" which is reflected in the application

## 2.1.0

- Added release for Mac OS (required version is 11.0 or newer)
- Added some necessary limits and delays to presence updates:
  - An enforced hard limit of 5 presence updates per 20 seconds (as required by Discord):
    https://discord.com/developers/docs/topics/gateway-events#activity-object-example-activity-with-rich-presence
  - A configurable limit of 2 updates per 5000 milliseconds
    (see [#14](https://github.com/ungive/discord-music-presence/issues/14)).
    For information on how to customize this limit see
    [here](https://github.com/ungive/discord-music-presence/issues/14#issuecomment-2117614770).
    If you play around with it, please let me know in the linked issue
    which values work best for you. Thank you!
  - Any update that falls outside of the allowed range
    is delayed until a point in time where this limit would not be violated.
    If many updates are delayed in a row, only the latest one
    will be shown in the Discord presence.
- Other improvements and bug fixes:
  - Added a banner and button to the tray menu
    to inform the user when a new version is available
  - Removed repeated Presence updates in cases where the media didn't change at all
  - Fixed a bug where songs that were being played on repeat
    did not reset their playback position back to 0:00
  - Settings are not saved when the application is closed anymore,
    so that the user can edit the settings file while Music Presence is opened
    and restart the application without the changes being deleted

## 2.0.1

- Media player support:
  - Added more application identifiers for TIDAL on Windows
  - Added MusicBee, Deezer and Apple Music on Windows
- Improvements and bug fixes:
  - Fixed out of sync playback positions or the remaining time showing "0:00".
  - Fixed a bug where sometimes media wouldn't show in the status
    for some media players
    ([#7](https://github.com/ungive/discord-music-presence/issues/7))
  - Improved detection of when the Discord presence should be updated,
    so it's updated only as frequently as needed.
  - Improved caching of music API requests to reduce the number of requests that are made
  - Improved Music API error handling and logging
  - Improved handling of erroneous playback position data from some media players
  - Fixed an issue where media with a duration of 0 seconds would be stuck at "0:00 left"
  - Reduced the number of similar or less meaningful messages in the logs
  - Fixed crash when there is a new version on GitHub
- Added a Windows ZIP archive release, for those who want it

## 2.0.0

- Complete rewrite of the software, featuring substantial changes, including:
  - Media playback is detected for all media players, not just TIDAL,
    which allows the user to use the software with a broader range of players
    and which makes the software more universal.
  - Uses actual system APIs instead of reading and parsing a window title,
    which makes the software a lot more reliable and future-proof.
  - Fine-grained control over which media is shared with Discord,
    by providing explicit controls on a per application basis.
  - New task menu layout with improved controls.
  - Shows an icon in the Discord status
    to indicate which application or streaming service is playing the media.
  - Whenever support for a new media player is added,
    the user does not need to install a new version.
    All necessary information about new media players
    is updated whenever the software is started.
  - For media players other than TIDAL the MusicBrainz API is used.
  - The Discord status now show the exact playback position in real time.
  - The Discord status for TIDAL contains a button
    that allows others to open the song in a browser
    for various popular streaming services.
- While all media on the system is detected,
  only a set of whitelisted players is shared with Discord for the moment.
  The rationale behind this is outlined in [this issue](
    https://github.com/ungive/discord-music-presence/issues/4).
  Users can easily suggest the addition of a new player by:
  - Opening an appropriate issue [here](
      https://github.com/ungive/discord-music-presence/issues/new/choose)
  - Clicking on "My media player is not detected" in the tray menu.
- Now includes a detailed privacy policy that outlines:
  - Which data is collected by the software.
  - Which online services the data is sent to.
  - How the user can control their data.
  - To read the entire privacy policy, see [PRIVACY.md](./PRIVACY.md).
- Released under the name "Music Presence", without using the Discord brand name.
- Licensed under different terms,
  since the software has been rewritten from the ground up.
  See [LICENSE.txt](./LICENSE.txt) for details.
- Currently only works on Windows, but support for Mac and Linux is underway.
- Future plans are outlined in [ROADMAP.md](./ROADMAP.md).
- If you would like to fund the project, see [FUNDING.md](./FUNDING.md).

## 1.4.1

- Showing "Playing Music" in the status by default now,
  instead of "Playing TIDAL".
- Fixed version numbers,
  which caused permanent "new version available notifications",
  even though there is no new version available.
- When a new version is available, show its version number in the notification.
- Updated the Discord Game SDK to version 3.2.1 (from version 2).

## 1.4.0

- Allow the use of a custom Discord application ID.
- Only show the Discord status while a song is playing and at no other time.
- Changes to the appearance of the Discord status.
- These changes were initially part of a pull request:  
  [purpl3F0x/TIDAL-Discord-Rich-Presence-UNOFFICIAL#100](
    https://github.com/purpl3F0x/TIDAL-Discord-Rich-Presence-UNOFFICIAL/pull/100)
