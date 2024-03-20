# Project Roadmap

Ideas and notes to indicate where the project is headed
and which features are planned to be added in the future.

## Media Player Support

### Generic Desktop Media

Windows allows to view and control all played media through its WinRT Media API.
This is accessible programmatically and can be used to view any media
that is currently played on the user's machine.
Support for this will allow to share songs from any application,
but an application whitelist should probably be used,
to exclude media from video streaming services.

Mac OS and Linux might support a similar kind of access,
but this is subject to further research at the moment.

With this, it is of course important to detect whether the media is actually music or not.
Blindly assuming every media is music might result in unnecessary API calls
to check whether the media title and artist actually represent music.

### Generic Browser Media

The Windows Media API mentioned above also exposes which application is playing the media.
It would be possible to detect a browser and add support for e.g. YouTube videos,
by whitelisting the text "YouTube" in the browser window title
and fuzzy searching for a song with the video title and artist.

Alternatively a browser extension could be created,
but that is likely a lot of effort for very little use.

Just like with Desktop Media, it is important to detect
whether played media is actually music or not.

### Grabbing Music Metadata from Window titles

This is possible on Windows and is used by the
[original project](https://github.com/purpl3F0x/TIDAL-Discord-Rich-Presence-UNOFFICIAL)
to find the song that is currently playing in TIDAL.
Qobuz works the exact same way as TIDAL, so adding support this way is trivial.
Media from a browser could be detected this way as well (as mentioned above).

### Special cases

#### TIDAL on Linux

There is no official TIDAL Linux client,
but there is an open-source community-driven desktop application,
which even has it's own Discord Presence feature
and exposes currently played music via an HTTP API:
[Mastermindzh/tidal-hifi](https://github.com/Mastermindzh/tidal-hifi).

The localhost API could be used to very easily check which song is currently playing.

### Missing Support

#### Qobuz on Linux

There is currently no official Qobuz Linux client
and there does not seem to be a community-developed desktop application either,
so support for this application would likely only be available
once Browser Media support lands.

#### Mobile (Android and iOS)

It might be possible to support mobile operating systems,
but the Discord Game SDK might not be able to detect which user is using it.
Also other platforms are priority at the moment.
iOS will likely not be supported, as I do not use Apple devices,
nor do I have an iPhone.

#### Spotify

Someone who mainly listens to TIDAL or Qobuz might want to occasionally
listen to Spotify and show it in their Discord profile,
through the same Discord Rich Presence status
(without it interfering with the integrated Spotify presence).
Support for Spotify might be added in the future.

## Notes

### Brainstorm

- Add a config file and optionally a settings window
- Allow configuring and fine-tuning the looks of the Discord status
- Adapt the icon in the Discord status based on the application that is playing the media
- Do not solely depend on the TIDAL API, add fallbacks to other APIs
- Use our own TIDAL API token (currently still using the forked one)
- Support invites for TIDAL (and perhaps other applications), as this is frequently
[requested](https://github.com/purpl3F0x/TIDAL-Discord-Rich-Presence-UNOFFICIAL/issues/82).
But is this even possible, since you need to change songs?
There would likely need to be an API to control the music player.
TIDAL Hi-Fi (Linux) actually supports player controls!
But it would need to work across platforms.
- Add a button to listen to the song (what should it open though?)
- Write logs to a log file
- Create a GitHub Pages landing page
- Create a Windows installer/signed exe (?)
- Automatic updates?

### Quality improvements

- When starting a song, with the presence just activating,
it starts showing as "idle" before showing the song information.
The song details should be shown as early as possible.
