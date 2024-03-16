## Development roadmap

Necessary before working on new features:

- Make appropriate changes to make this a standalone project,
independent of its original fork:
  - Bump or reset the version number
  - Change the update url that is being checked in `main.cc`
  - Update the license file
- Make a release for all newly implemented features so far, since
[my pull request](https://github.com/purpl3F0x/TIDAL-Discord-Rich-Presence-UNOFFICIAL/pull/100)
has not been merged yet and several people would like to make use of the new features.
- Update the SDK to version 3.2.1
([here](https://discord.com/developers/docs/game-sdk/sdk-starter-guide))
and check if it's possible to use the "Listening to" activity type now.
[Kizzy](https://github.com/dead8309/Kizzy) is able to show the "Listening" presence type,
so we should be able to do that too.
Investigate further, if the Game SDK
[still](https://github.com/purpl3F0x/TIDAL-Discord-Rich-Presence-UNOFFICIAL/issues/77)
does not allow us to do it.

New features:

- Add more applications which show the current song in the title, while it's playing:
  - Qobuz (works exactly the same as TIDAL, confirmed working)
- Update the little icon in the presence based on the music player/streaming service
which is playing the song that is displayed.

Extending platform/media detection support:

- Check in what way I can support macOS, since I do not personally own an Apple computer.
- Look into detecting any media being played on Windows through its Media API
(visible in the menu that pops up when changing volume with the volume keys).
  - It must be possible to detect playing/paused status
  and the song name and artist at the minimum,
  otherwise this is not an option.
  - It will be a requirement to detect if the media being played is actually music.
  We don't want an arbitrary YouTube video or other media to be shown as music on Discord.
  We also don't want to make dozens of TIDAL API requests,
  just to check if a YouTube video is a song
  (we need some way to detect if the media title is a song or not),
  so be careful here.
  - Alternatively check which application is playing the media (if possible),
  and check if it is whitelisted.
  Adding support for a music player is then only a matter of whitelisting it.
- Add support for Linux on a best-effort basis.
  - [tidal-hifi](https://github.com/Mastermindzh/tidal-hifi) -
  Linux desktop player for TIDAL,
  which exposes the currently playing song via an API.
  Does not show the currently playing song in the title, while it's playing though.
  It also integrates Discord Rich Presence.
  - Is it possible to enumerate media being played on Linux,
  through something similar as the Windows Media API?
  Very likely depends on the desktop environment that is being used.
- Do not solely depend on the TIDAL API.
Extend to e.g. iTunes or YouTube Music API,
especially for fuzzy searching songs
(other APIs might be better at that than the TIDAL API).
This might not be in the interest of users though
("what does a TIDAL or Qobuz listener have to do with iTunes or Google's YouTube Music?")

Quality improvements:

- When starting a song, with the presence just activating,
it starts showing as "idle" before showing the song information.
The song details should be shown as early as possible.

Adding Spotify to the list of supported applications (low priority):

- Someone who mainly listens to TIDAL or Qobuz might want to occassionaly
listen to Spotify and show it in their Discord profile,
through the same Discord Rich Presence
(without it interfering with the integrated Spotify presence).
  - Spotify on Windows shows the currently playing song in the title
  (just like TIDAL and Qobuz). What about macOS and Linux?

## Brainstorm

- Does it make sense to support Android?
- Create a browser extension to support 
