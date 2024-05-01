# Changelog

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
    https://github.com/jonasberge/discord-music-presence/issues/4).
  Users can easily suggest the addition of a new player by:
  - Opening an appropriate issue [here](
      https://github.com/jonasberge/discord-music-presence/issues/new/choose)
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
