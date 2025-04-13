# Changelog

## 2.3.0

- This updates comes with a lot of changes to the source code of the app
  that drastically improve maintainability and extensibility for the future.
  The app now processes media in a structured and modular way
  which allows detected media to be prepared for multiple uses cases,
  not just a Discord status.
  Previously a Discord status was the only feature in mind,
  now it is possible to very easily add more ways to handle media,
  which lays the foundation for future developments!
  - I will be working on last.fm scrobbling next, stay tuned!
    The progress is tracked in
    [#53](https://github.com/ungive/discord-music-presence/issues/53)
  - For more information about these changes see the related GitHub issue:
    [#84](https://github.com/ungive/discord-music-presence/issues/84)
  - For a roadmap of features I am planning to work on in the future,
    click [here](https://roadmap.musicpresence.app)
- Great news for macOS users:
  Music Presence now works again with macOS 15.4 and newer!
  Although it is compatible with far less players
  due to the changes Apple has introduced with version 15.4 of macOS.
  - On devices that use macOS 15.4 or newer,
    Music Presence now only works with Apple Music and Spotify.
    In a future update TIDAL and possibly YouTube Music will work as well.
    Music Presence still works like before with macOS versions older than 15.4.
  - Automation of these media players is mandatory for this
    and needs to be granted when prompted.
    You will get the automation prompt automatically
    once you start any of these two media players
    while Music Presence is running.
    Denying automation will disable the player
    until it is manually granted in the system settings.
    This fixes [#165](https://github.com/ungive/discord-music-presence/issues/165)
  - Support for TIDAL is tracked in this issue:
    [#211](https://github.com/ungive/discord-music-presence/issues/211)
  - Support for YouTube Music is tracked in this issue:
    [#211](https://github.com/ungive/discord-music-presence/issues/212)
- Bug fixes and improvements
  - Integrated the Spotify API for Spotify,
    which adds additional artists of a song
    and a "Listen to this song" button to your status.
    [#166](https://github.com/ungive/discord-music-presence/issues/166)
  - Integrated the iTunes API for Apple Music,
    which adds a "Listen to this song" button to your status
    and adds a progress bar to your status for some users
    where the Apple Music app does not report the song duration.
    Closes [#159](https://github.com/ungive/discord-music-presence/issues/159)
    and [#166](https://github.com/ungive/discord-music-presence/issues/166)
  - Fixed integration of the TIDAL API.
    TIDAL now shows all artists and animated album covers again.
    Fixes [#150](https://github.com/ungive/discord-music-presence/issues/150)
  - Fixed occassional incorrect matches with search results from music APIs
    where a song would be selected that only partially matches
    with the actual song title
  - Applications are now ordered alphabetically in the tray menu
  - Fixed cover images showing a question mark when the proxy client disconnects
    instead of attempting to reconnect or using a fallback image
  - Fixed Player menu to not show disabled players anymore,
    to always show the player that is currently active
    and to update when a player is disabled.
    When no player is enabled, the player that had the latest media changes
    is shown in the Player menu
  - Fixed a rare crash on Windows when the SMTC library would
    return empty values for certain media properties
  - Fixed improper handling of irrecoverable SMTC errors on Windows.
    Media detection is now restarted whenever such an error occurs,
    e.g. "The RPC server is unavailable" or "The remote procedure call failed"
  - Fixed not handling the media with the most recent metadata updates.
    Detected media is tagged with a timestamp,
    which is now only updated when there are metadata updates.
  - The song duration is now rounded to the nearest second
    instead of being floored.
  - Removed the MusicBrainz API as it does not serve much purpose,
    it often does not yield any search results
    and it is rather slow.
    I recommend to properly tag your local files
    or use a media player that reports all song metadata,
    not just partial data.
    If you have a use case for it, feel free to
    [open an issue](https://github.com/ungive/discord-music-presence/issues)
- Languages
  - Added Finish / Suomi &nbsp;—&nbsp; Thank you [ekimeister](https://github.com/ekimeister)
  - Added Romanian / Română &nbsp;—&nbsp; Thank you [Liviu](https://github.com/liviu-hariton)
  - Added Czech / Čeština &nbsp;—&nbsp; Thank you [Ondřej Kučera](https://github.com/kucendro)
- Media players
  - Added (Windows):
    ampcast, Emby, JioSaavn, Mini Radio Player, Moosync, MPC-HC,
    PotPlayer, Roon, Saturn (Deezer), Sonixd, Supersonic, Tauon and Wora
  - Added (Mac): Doppler, Moosync, Plex, re:AMP, Roon and VLC &mdash;
    These only work with versions of macOS prior to 15.4
  - Better support for existing players with added player identifiers
    - Windows: foobar2000, iTunes, Podurama, Spotube, WACUP, Yandex Music
    - Mac (prior to macOS 15.4): Dopamine, Pocket Casts
  - Miscellaneous
    - iTunes can now be displayed as "Apple Music"

## 2.2.8

- Added alternative placeholder images for the case
  when there is no cover image available.
  In the "Settings" menu
  you can now choose between the media player logo (the default),
  a music note, a physical CD, the playback status (playing/paused symbol)
  and the Music Presence logo
- Third-party clients for streaming services
  now have an option in the "Player" menu
  to display the player as the streaming service itself
  but without the logo/branding for that streaming service
  - Spotube can now be displayed as "Spotify"
  - Cider can now be displayed as "Apple Music"
  - Any future supported third-party client will have this option too
- Updated the internal list of media players to version 3
  which is a big improvement over the previous version
  that makes maintaining known media players much easier and efficient
  and opens up new possibilities for features in the future
  - Source: https://github.com/music-presence/media-players
  - Versions of Music Presence prior to 2.2.8
    won't get updates for supported media players anymore.
    If your media player is not detected as of this version,
    then you will have to update Music Presence
- Bug fixes and improvements
  - Fixed update failure when another new version is installed
    while a restart is pending for a previously installed update.
    Fixes [#89](https://github.com/ungive/discord-music-presence/issues/89)
  - Fixed setting "Show Music instead of the player name"
    showing as overridden, when any setting for the current media player
    is overridden.
    Fixes [#90](https://github.com/ungive/discord-music-presence/issues/90)
  - Fixed crash on Mac when changing the language,
    caused by improper termination of still-running threads
    that attempt to access deallocated memory.
    Fixes [#92](https://github.com/ungive/discord-music-presence/issues/92)
  - Fixed crash on Mac when changing the language,
    caused by not unregistering now playing notification observers
    and old observers attempting to read deallocated memory
  - Fixed a small memory leak with media detection on Mac on an application reload,
    e.g. when changing the language in the settings
  - Fixed negative numbers in the progress bar of the status
    when the duration of media is too high by limiting the duration
    and removing the duration entirely
    when the duration is unrealistically high
  - Fixed certain TIDAL songs showing as the incorrect version in the status
    due to how the TIDAL API formats versions of some songs
  - Fixed a potential for incomplete player icon downloads
    when media players are updated at the start of Music Presence
  - Downloaded icons of supported media players
    (located in `%APPDATA%\Music Presence\assets` on Windows
    and `~/Library/Application Support/Music Presence/assets` on Mac)
    are now re-downloaded whenever they got an update
    and old unused icons are now automatically deleted.
    Music Presence now also only downloads supported players and icons
    for the platform it is running on instead of all players for all platforms
- Languages
  - Added Slovak / Slovenčina &nbsp;—&nbsp; Thank you [Tibor Stegmann](https://github.com/stegmann-tibor)
  - Added Japanese / 日本語 &nbsp;—&nbsp; Thank you [momizi06](https://github.com/momizi06)
  - Added Vietnamese / Tiếng Việt &nbsp;—&nbsp; Thank you [longnuub](https://github.com/coderheck)
  - Added Hungarian / Magyar &nbsp;—&nbsp; Thank you cobra525
- Media players
  - Added Apple Podcasts on Mac

## 2.2.7

- Fixed language selection not working for English.
  Fixes [#86](https://github.com/ungive/discord-music-presence/issues/86)
- Improved changelog popup to show all versions since the last feature release

## 2.2.6

- Added **translations to other languages** and a language selection setting!
  - Music Presence will now be displayed in your system language by default.
    You can change the language by navigating to "Settings" (gear icon)
    and then choosing a language under the "Language" menu item
  - Do you want to help with translating?
    Read [here](https://github.com/ungive/discord-music-presence/blob/master/documentation/translations.md) for more information
    or come by and say Hi in the `#translations` channel
    on our [Discord server](https://discord-invite.musicpresence.app)!
  - Music Presence is now available in the following languages:
    - **English**
    - **Afrikaans**
    - **Deutsch** / German
    - **Español** / Spanish
    - **Français** / French
    - **Hrvatski** / Croatian
    - **Indonesia** / Indonesian
    - **Italiano** / Italian
    - **한국어** / Korean
    - **Nederlands** / Dutch
    - **Polski** / Polish
    - **Русский** / Russian
    - **українська** / Ukrainian
    - **正體中文** / Traditional Chinese
- Added an "About" window to the "Help" menu
  - Everyone who has helped with translations is mentioned here
- Bug fixes and improvements
  - Fixed missing cover image in the status
    when the media player reports a cover image
    but claims it has a different image type,
    like Apple Music does on Apple Silicon.
    Fixes [#77](https://github.com/ungive/discord-music-presence/issues/77)
  - Fixed album and artist splitting for Apple Music
    which sometimes split at the wrong position with multibyte characters
    causing the status to contain scrambled song information
  - Improved app shutdown time, mainly so that it reloads faster
    when changing the language of the application
  - When enabling the setting
    to show the artist and album name on the same line,
    the album name setting is now automatically enabled, if it was disabled
  - The player name is now shown by default instead of "Music"
  - Fixed use of "C" locale on Mac instead of the proper system locale
  - Fixed improper selection of the UTF-8 locale variant on Mac
  - Removed some icons in the tray menu on Mac to make it look less cluttered
    since menu icons shift the text to the right
    which can look inconsistent in some cases.
    Links that open a website still always have an "open" icon
- Media players
  - Added Windows 11 identifier for Cider
  - Added Jellyfin Media Player on Windows

## 2.2.5

- Added [more donation options](https://donate.musicpresence.app)
  to the tray menu, including
  [buymeacoffee.com](https://buymeacoffee.com/jonasvandenberg).
  Thank you for supporting my work!
- Added the option for a **paused icon for streaming services**.
  When you pause media you will see a paused icon
  instead of the streaming service logo,
  to more clearly indicate that the media is not playing,
  as this was pretty unclear up until now.
  Playing media from streaming services
  will still always show the player's logo.
- Added the option to show a **frozen progress bar for paused media**.
  Enable this in the settings using the
  "Freeze the progress bar for paused media" option.
  You can now show no progress bar, a frozen one
  or how long the media is paused.
  Note that "frozen" means stuck at 0:00
  since Discord doesn't offer a way to pin it to a specific time
- Added the option to **show the artist and the album on the same line**,
  separated by a dash. This is great if want to show the album name
  without showing three lines of text
- Added support for **animated cover images** for TIDAL
  - Animated covers are enabled by default,
    but you can disable them in the settings, if you want to
  - The video is automatically converted to a GIF using our own online service,
    for which you can find the source code here:
    https://github.com/ungive/video-conversion-service
- Apple Music on Windows:
  Automatically removing the Apple Music user name
  from songs that are played from a personalized "Station",
  The name of the station usually contains the user's name
- The option to use the MusicBrainz API will be removed in a future version
  and is automatically disabled upon launching this version.
  You can still enable it again, but if you rely on it, please let me know by
  [opening an issue](https://github.com/ungive/discord-music-presence/issues)
  or [joining the Discord](https://discord-invite.musicpresence.app),
  otherwise it will disappear soon
- Bug fixes and improvements
  - Fixed missing cover images in your status (appearing as a question mark),
    when you have an unstable internet connection.
    Fixes [#52](https://github.com/ungive/discord-music-presence/issues/52)
  - Fixed crash when disconnecting your internet while listening to music
    and using cover images from media players.
    This possibly also fixes crashes that happen with unstable connections
  - Fixed continuous disconnects and reconnects from the proxy server
    when the album cover image that the media player reports has zero bytes.
    Images with such a size are now treated as if there was no image.
    Also logging and ignoring cover images
    for which conversion to a smaller format
    results in an image with zero bytes.
    Fixes [#59](https://github.com/ungive/discord-music-presence/issues/59)
  - Fixed the possibility of disconnecting from the proxy server continuously
    and spamming the log file, when the Discord RPC would not report
    when it disconnected from Discord
  - Fixed duplicate artists in the Discord status with media players
    that rely on an external API.
    Fixes [#67](https://github.com/ungive/discord-music-presence/issues/67)
  - Fixed rectangle cover images being cropped incorrectly
    Fixes [#69](https://github.com/ungive/discord-music-presence/issues/69)
  - Fixed random crashes on Windows
    (rare for some users, more frequent for others)
    related to how media is detected
  - Fixed segmentation fault (crash) on Mac
    when an app without a bundle identifier
    (i.e. an app that is not located in the Applications directory)
    was playing and reporting media
  - Improved release file naming.
    Files now follow a more consistent and descriptive naming scheme
    which should make it easier to find the right file you are looking for.
    Also added a `legacy` file for Windows
    so that automatic updates do not break for versions prior to 2.2.5
    (it has the same content as the ZIP file for Windows)
  - Starting with this version releases of Music Presence
    are built automatically instead of manually
    using a custom CI pipeline.
    This lays the foundation for a preview build channel in the future,
    where users can get releases of the newest changes much earlier
  - Now using the user's country code for the TIDAL API
    to get more accurate search results, see the `countryCode` parameter in the
    [TIDAL API documentation](https://developer.tidal.com/apiref?spec=search-v2&ref=get-searchresults-v2)
- Media players
  - Added Yandex.Music on Windows
  - Added Windows 11 identifier for YouTube Music on Windows
  - Added Podurama for Windows (via WebCatalog)
  - Added identifier for SoundCloud on Windows (via WebCatalog)
  - Added YouTube on Windows (via WebCatalog)
  - Added Cider on Mac
  - Added mpv on Mac and Windows
  - Added iTunes on Windows

## 2.2.4

This version comes with better support for podcasts,
the option to change certain global settings for specific players only,
additional individual settings for some players,
the option to show paused media for streaming services
and an overall better synergy with Spotify.
Read more below!

*Consider supporting my ongoing efforts to improve Music Presence*
*by becoming a [**Patreon member**](https://patreon.com/musicpresence).*
*Thank&nbsp;you to all my supporters&nbsp;🤍*

- **Better support for podcasts** with Spotify and other players!
  - Spotify and Deezer will now show "Listening to a Podcast" instead of "Music"
    when listening to a podcast
  - For Spotify specifically you have the option
    to *only* show podcasts in your status.
    That means you can use Music Presence
    together with the official Spotify status
    in order to share both your music and the podcasts you listen to!
  - Pocket Casts now always shows "Listening to a Podcast" instead of "Music"
- Added **individual settings per player**.
  This includes both the possibility
  to override certain global settings for one specific player,
  as well as player-specific options that aren't available for other players.
  - This menu is called "Player" and should be pretty intuitive to use.
    You need to first play media
    in order to configure the player that is playing the media.
    You can still configure that player when it's paused
    until another player starts playing media.
    You will also get a visual clue in the "Appearance" menu,
    if any settings are overridden for the currently active player.
    To revert back to using the global setting either
    hold SHIFT while clicking the overridden setting
    or click "Reset all overridden settings"
  - You can override these global settings per player at the moment:
    - *Show the name of the player instead of "Music"*
    - *Show paused media in your status*
    - *Show a playing icon when music is playing* (non-service players only)
    - *Show the logo of a media player* (non-service players only)
    - If you feel like another setting should be overridable per player,
      please [let me know](https://github.com/ungive/discord-music-presence/issues)!
  - There are also individual settings per player, namely the following:
    - Spotify: Option to try and filter out advertisements (enabled by default).
      This might not be reliable or break in the future.
      Check if it's still working when you update Spotify!
      You can always keep an eye on the tray icon when an ad is playing
    - Spotify: Option to always show "Listening to a Podcast" for podcasts.
      This means it will show that
      even when you enabled player names ("Listening to Spotify").
      Listening to music would therefore show "Spotify",
      but podcasts "a Podcast" (disabled by default)
    - Spotify: Option to *only* share podcasts, but not music from Spotify.
      This is useful if you want to use the official Spotify status for music
      and Music Presence to show podcasts (disabled by default)
    - Apple Music: Splitting album and artist, which are reported together,
      separated by a hyphen (enabled by default).
      If you liked the way it looked before you can uncheck this setting
    - Deezer: Option to try and filter out advertisements (enabled by default).
      Sometimes this doesn't work because while an ad is being played
      Deezer reports it as if it were the song you just played,
      which is impossible to detect
- **Paused media is now also shown for streaming services**!
  There won't be any paused icon,
  but you can show a timer for how long media is paused.
  This might be further improved in the future
- Improved cropping of local cover images to remove unnecessary transparency
  - Now cropping covers to the largest center square
    without too many surrounding transparent pixels
  - This has the added benefit that Spotify's album cover images 
    do not appear in your status with the Spotify logo/brand at the bottom,
    which is redundant
    because the Spotify logo is already shown as a small icon.
    Before and after: [https://i.imgur.com/hy9nJOL.png](https://i.imgur.com/hy9nJOL.png)
  - Cover images are also never cropped too much (currently at most 50%)
- Added the option to use the Deezer API to retrieve missing song information
  - The Deezer API is only used for Deezer and can be disabled in the settings
  - This is used to retrieve the missing album name, the song duration
    and the correct cover image for podcasts.
    The local cover image for podcasts is merely a simple icon for some reason
- Bug fixes and improvements
  - Updated automatic update library
    [`ungive/update`](https://github.com/ungive/update)
    to commit
    [`fd38aa6e`](https://github.com/ungive/update/compare/8f12c40...fd38aa6e)
    - Updates do not fail anymore
      when updating any existing start menu shortcut fails.
      This has caused a handful of automatic update failures
      which should now be fixed
    - Properly encoding paths as UTF-8 for ZIP extraction.
      Extracting the ZIP file failed for some users,
      mainly those that likely had non-ASCII characters in their Windows username.
      This has caused a few automatic update failures which should now be fixed
    - Now logging the results of successful SHA256 checksum verifications
      and cryptographic signature verifications
      in addition to logging when these checks fail
    - Added logging of purely informational, non-fatal error messages
    - Improved error messages
  - Cancelling automatic updates for one week, if they keep failing too often.
    Otherwise the download counter on GitHub keeps increasing for failed updates
    which incorrectly reflects how often a new version is downloaded.
    This currently amounts to a maximum of 16 allowed update failures per month
  - Fixed the potential for a crash when starting
    a new version of Music Presence
    if it was never installed to the default installation directory
  - Fixed paused media duration not showing when timestamps are disabled
  - Fixed the potential for a very unlikely deadlock (application freeze)
    under specific conditions
  - Added a workaround for another potential but unlikely deadlock
    when using cover images from media players.
    This is caused by the Qt websocket library freezing
    when attempting to send data using a connection that isn't opened yet.
    See [e8b08c5](https://github.com/ungive/loon/commit/e8b08c5)
  - Fixed a crash when updating the Discord status
    for a media player that is not whitelisted
    (which practically never happens)
  - Showing the app name and currently shared song in the tray tooltip text.
    Fixes [#48](https://github.com/ungive/discord-music-presence/issues/48)
  - Fixed "See what's new when launching a new version"
    incorrectly toggling the checkbox and setting for
    "Notify when a new version is available".
    Fixes [#50](https://github.com/ungive/discord-music-presence/issues/50)
  - Fixed album name not showing when there is no cover image
  - Fixed accidentally increasing the size of TIDAL API query parameters
    and sending a lot of URL-encoded null bytes
  - Fixed the tray icon being stuck at an incorrect state
    in some cases when no media player was detected
  - Using the MusicBrainz API to retrieve missing song durations as well now,
    so the status shows a progress bar whenever that information is available
- Media players
  - Added Harmonoid on Windows
  - Added Pocket Casts (Podcasts) on Windows
  - Added Windows 11 identifier for Deezer

## 2.2.3

This version comes with the option to show paused media in your Discord status
for **offline** media players and a few bug fixes and small improvements.

- Offline media players now have the option to show paused media in your status.
  Note that this does **not** work with streaming services at this time
  (read below for more information)
  - This is disabled by default and must be enabled in the appearance settings
  - When you enable paused media for your status
    the playback progress bar/timer disappears,
    since the media is not playing anymore.
    The rest of the song information remains visible
  - Paused media shows a small paused icon (two vertical bars)
    by default when you enable it,
    but you can uncheck that option again, if you don't want it
  - Playing media can have a small playing icon (a triangle)
    which you can explicitly enable in the settings.
    This will replace the player logo for playing media
  - You can also show for how long your media is paused,
    if you want to. This will count the time from the point the media is paused.
    Note that this timer might be reset by scrubbing the song!
  - This is not availabe for streaming services
    and I'm not planning to add it at this time,
    as I always want to show the service brand/logo whenever I can
    and showing paused media would not be very meaningful
    without at least showing a paused icon.
    If you really want this for streaming services too though,
    please let me know by opening an issue
    [here](https://github.com/ungive/discord-music-presence/issues/new/choose)
    or by letting me know on our
    [Discord server](https://discord-invite.musicpresence.app)
- Bug fixes and small improvements
  - Fixed an issue with the Discord status not updating
    when the artist name, song title or album name
    is a single unicode character.
    This was due to improper calculation of the text length
    with multibytes characters
    and Discord requiring the text to be 2 characters or longer
  - Fixed Music Presence not setting the status any longer
    until a program restart when a Discord RPC error occurs.
    This was due to assuming Discord RPC disconnects on every error
  - Moved the option to hide the player logo
    for non-service (i.e. offline) media players
    into "Settings for offline music players"
    and changed the name to "Show the logo of the media player"
  - The help menu entry "My media player is not detected" now opens
    the [troubleshooting](https://troubleshooting.musicpresence.app) page
    to serve as first aid for users of media players
    that need additional steps to work.
    You can still submit detected media players
    by clicking on "Submit detected media players" in the help menu
  - Explicitly setting the program locale to the system locale
    and attempting to use a UTF-8 variant of that locale on program startup.
    This is necessary for proper text length calculation with multibyte strings

## 2.2.2

- **Redesigned the Music Presence tray icon and logo.**  
  The tray icon is now more defined and has better contrast.
  Sharing music in your status is now symbolized by a triangle
  in the bottom right corner of the tray icon,
  with the app logo remaining to be recognizable and easily identifiable.
  - The icon color automatically adapts to the system theme
    (changes to either black or white)
  - You can read more about this 
    [here](https://github.com/ungive/discord-music-presence/issues/36)
- If you previously installed version 2.2.1
  and you are now seeing the same changelog appear again,
  that is because 2.2.1 contained a bug that would crash the app
  which is fixed in this version.
  Read more [here](https://github.com/ungive/discord-music-presence/issues/39)
- Added the option to hide the player logo for media players
  that are not streaming services.
  You can hide it for e.g. foobar2000 or MusicBee,
  but not players like TIDAL, Spotify or Apple Music at the moment
- Improvements and bug fixes for cover images from media players
  ("use cover images from media players")
  - The cover image from the media player is now also used
    when Music Presence reconnects to the proxy server after a disconnect
    or when it takes longer to connect than the initial timeout.
    This should help with unstable or slow internet connections
  - Fixed Discord account switching or Discord restarts
    not causing the app to disconnect from the proxy server
    and instead entering an idle disconnect/reconnect loop
    and wrongfully reusing proxy links that aren't valid anymore
  - When the proxy client disconnects the status is updated
    to use a different cover image (if available)
    so that it does not show nothing
  - When there is no correct cover image URL from an API or the proxy,
    the status falls back to a guessed cover image (if available),
    so that there is at least something to show
  - Increased the idle timeout to 60 seconds (from 30 seconds)
    to accomodate for bad internet connections
    and give enough time to reconnect to the proxy server, if needed
  - Increased the interval at which the app
    attempts to reconnect to the proxy server,
    in case the client disconnects or fails to connect
- When starting Music Presence for the first time
  the application now shows a small popup instead of a notification
  to inform you that it sits in the tray menu.
  First-time users should now have an easier time finding the app.
- Left-clicking on the tray icon now opens the tray menu as well.
  Previously the tray menu could only be opened by right-clicking it (Windows)
- Fixed system theme changes not being reflected properly in the app
  (not detected reliably in version 2.1.3 and prior,
  temporarily disabled in version 2.2.0).
  Now all colours and icons in the tray menu are properly updated,
  when you change your system theme
- When installing this update from within the app,
  either via automatic updates or by manually clicking install,
  the start menu shortcut on Windows should be updated automatically
  to reflect the app icon change
- The application logs now show if the media has a cover image available,
  whether it is used in the status or if an API's cover image is used
  - If the media player has a cover image, the log shows `cover:image`
  - If the cover image from the media player is shown in the status
    using the proxy server, the log shows `cover:image/proxy`
  - Otherwise the domain name of the image URL is shown,
    e.g. `resources.tidal.com` for TIDAL images
- Changed the following default settings:
  - MusicBrainz is now disabled by default for new users.
    The reason for this is that since the last update
    it does not add much value to the status anymore
    and just increases the delay until the Discord status is visible.
    It also only gets useful information sometimes, not all the time.
    Since Music Presence is slowly growing in popularity,
    I want to make sure the MusicBrainz API is not strained unnecessarily
    for information that is not needed in most cases anway.
    If you want to use it, you can always enable it manually
  - Using the "Listening to" activity type by default now
    and removed the "(BETA)" status
  - The artist ("by") and album prefix ("on") is not enabled by default anymore
  - Title and artist are now shown on separate lines by default,
    assuming most users will prefer to have it this way
- Added support for the following media players:
  - SoundCloud on Windows
  - Next-Player (DryForest) on Windows
  - Winamp and WACUP on Windows
  - Nora on Windows
  - Dopamine on Windows
  - MediaMonkey on Windows
  - VLC Media Player on Windows

## 2.2.1

This version is identical to version 2.2.2,
but it contains a bug which crashes Music Presence under certain conditions.
See [here](https://github.com/ungive/discord-music-presence/issues/39)
for more information.
If you see this message in the in-app pop-up,
consider updating to version 2.2.2.

## 2.2.0

This version introduces the option
to show the cover image from your media player in your status,
update installation directly within the app,
including automatic cryptographic verification
and automatic installation whenever a new version is available,
a revamped tray menu which is better organized and more user-friendly,
controls over which external services are used to get additional song metadata
and more.
Read below for details.

### Cover images from media players

Added the option to use the album cover image directly from the media player.
You will now always have a cover image in your status,
if your media player supplies one.

- Media players like foobar2000 and MusicBee,
  which play local files, like MP3 and FLAC,
  will show the cover image that is embedded in the music file
  or detected otherwise by your media player.
- How does this work? A small version of the cover image
  (100x100, less than 50KB) is temporarily uploaded to our own service
  and stored only for the duration that the Discord status is visible.
  This has minimal impact on your internet bandwidth.
  For more information read the
  [documentation](https://github.com/ungive/discord-music-presence/blob/master/documentation/cover-images-proxy.md)
  and the [privacy notice](https://github.com/ungive/discord-music-presence/blob/master/PRIVACY.md).
- The code that powers this feature is open-source! See
  [https://github.com/ungive/loon](https://github.com/ungive/loon).
- Why? Some media players do not report the name of the album the song is from.
  Because of this it is impossible to tell
  which album cover image is the correct one
  and sometimes the Discord status would show the wrong image
  (or no image at all).
  With this update the status will always show the correct cover image.
  Additionally Music Presence does not rely
  on an external service like the TIDAL API anymore
  to have a cover image in the status.
- If this feature is disabled or an error is encountered,
  then Music Presence falls back to the old behaviour
  and works exactly like previous versions by using
  an appropriate API service to get a cover image
  (given that these are enabled in the settings).
- Music Presence only contacts our service when its enabled in the settings,
  when the Discord status is enabled and music is actively playing
  and being shared in your Discord status.
  When you stop listening,
  Music Presence disconnects after a short idle timeout.
- The application logs show exactly when Music Presence connects to the proxy,
  when it disconnects and when a cover image is uploaded.

### Automatic updates

The application now installs updates automatically.
A number of checks are made before an update is actually installed,
including but not limited to
cryptographically strong authentication of the source.

- For information about the security of the updater read the
  [documentation](https://github.com/ungive/discord-music-presence/blob/master/documentation/automatic-updates.md).
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
- The source code of the updater component is open-source (too)! See
  [https://github.com/ungive/libupdate](https://github.com/ungive/libupdate).
- The update installation does not require elevated administator privileges.
- Why? There are a lot of features
  [planned](https://github.com/ungive/discord-music-presence/blob/master/documentation/roadmap.md),
  which is why automatic updates were introduced.
  Automatic updates allow me to make more frequent and smaller releases
  which can be adopted much more quickly than before.
  This feature also saves the manual download step that was necessary before
  and verifies the integrity and authenticity of the downloaded update,
  so you do not have to do it manually.
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
- Because of the introduction of this update,
  each release now also has a `sha256sum.txt` and `sha256sum.txt.sig` file,
  which contain the SHA256 checksum and the Ed25519 signature respectively.
  If you want to, you can use these files to verify your download yourself,
  by following the steps
  [here](https://github.com/ungive/discord-music-presence/blob/master/documentation/automatic-updates.md#verifying-releases).
- This feature is currently only available to Windows users,
  but Mac users will get automatic updates in the future too.

### Changelog popup

- When automatic updates are enabled and a new version is launched,
  you will see a popup with the latest changes,
  so you won't miss out on what was added in the latest update.
- You can also open the changelog popup from the settings window,
  if you ever think you missed something.
- When a new version is available and automatic updates are disabled,
  the application shows a popup window with the changelog of the newest version
  and a button to install the update.
  This can be disabled in the settings.
- The application now shows a popup with the latest changelog
  whenever you start a new version.
  This can be disabled in the settings,
  but I recommend you leave it on,
  so you don't miss out on what was added in the latest update.
  This popup is not shown if you launch Music Presence
  for the very first time.

### Tray menu improvements

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

### Other improvements

- Media without an artist is not skipped anymore.
  You can now share songs from e.g. MP3 files that aren't properly tagged.
  Previously media without an artist was skipped by Music Presence.
- MusicBrainz API results now add additional artists, if available,
  and make a best-effort guess at the album name, if it is missing.
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
- Moved the update information banner to the bottom of the tray menu,
  so it's not in the way, but still clearly visible.
- Now saving a backup of the settings file if it contains syntax errors,
  such that editing it does not cause it to be completely reset,
  in case any syntax errors are introduced by the user.
- Removed the setting to enable or disable Discord invite notifications,
  as that notification is only shown once per installation anyway.
- Long title and/or artist names are shortened in the tray menu,
  so that the menu does not get overly wide.
  Hovering over the song information shows the entire title and artist.
- The Windows installer does not require elevated privileges anymore,
  unless you have a version prior to Music Presence version 2.2.0 installed,
  in which case the "uninstaller.exe" will require elevated privileges
  in order to uninstall it from the program files directory.
- Renamed the setting "Show the song title and artist on separate lines"
  to "Show the song title and artist on a single line".

### Bug fixes

- Fixed Discord RPC and TIDAL API errors
  when song or artist names are too long.
- Fixed an issue with UTF-16 characters in filesystem paths,
  where configuration and log files would not be saved correctly or at all.
  Fixes [#34](https://github.com/ungive/discord-music-presence/issues/34).

### Technical changes

- The `--launch` parameter of `launcher.exe` on Windows
  now behaves the same way as the `--launch-if-closed` parameter,
  only launching the application if it is not running already.
- Added a `--local-launch` parameter to `launcher.exe` on Windows,
  which applies any updates that have been downloaded
  to `%LOCALAPPDATA%\Music Presence` and starts the latest version.
  To clarify, `--launch` only launches the executable that is
  in the same directory as the launcher, while `--local-launch`
  launches any installation in the local app data directory.

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
  - To read the entire privacy policy, see
    [PRIVACY.md](https://github.com/ungive/discord-music-presence/blob/master/PRIVACY.md).
- Released under the name "Music Presence", without using the Discord brand name.
- Licensed under different terms,
  since the software has been rewritten from the ground up.
  See [LICENSE.md](https://github.com/ungive/discord-music-presence/blob/master/LICENSE.md) for details.
- Currently only works on Windows, but support for Mac and Linux is underway.
- Future plans are outlined in [the roadmap](https://github.com/ungive/discord-music-presence/blob/master/documentation/roadmap.md).
- If you would like to fund the project, see
  [FUNDING.md](https://github.com/ungive/discord-music-presence/blob/master/FUNDING.md).

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
