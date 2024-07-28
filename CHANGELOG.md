# Changelog

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
