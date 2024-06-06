[![Number of downloads](https://img.shields.io/github/downloads/ungive/discord-music-presence/total?style=flat&label=downloads&labelColor=444)](https://github.com/ungive/discord-music-presence/releases)
&nbsp;[![Number of downloads of the latest version](https://img.shields.io/github/downloads/ungive/discord-music-presence/latest/total?style=flat&label=downloads%20%40latest&labelColor=444)](https://github.com/ungive/discord-music-presence/releases)
&nbsp;
[![Join the Discord server](https://img.shields.io/discord/1224509771068211292?logo=discord&logoColor=eee&label=Discord&labelColor=464ce5&color=fff)](https://discord-invite.musicpresence.app)
&nbsp;
[![Support Music Presence on Patreon](https://img.shields.io/endpoint.svg?url=https%3A%2F%2Fshieldsio-patreon.vercel.app%2Fapi%3Fusername%3Dmusicpresence%26type%3Dpatrons&style=social)](https://patreon.com/musicpresence)

# Music Presence for Discord

![Screenshot of the application in the tray menu and the Discord status](
  ./assets/banner.png)

Music Presence allows you to show your friends what you are listening to,
no matter which media player or streaming service you are using.
It works by observing which media players are playing music on your device
and showing the information as a Discord activity.

The most notable features include:

- Fine-grained control over which applications are shared
  in your Discord status.
- Supports numerous music players and streaming services
  (support for more is being worked on!)
- The tray icon changes and reflects whether your status is currently active or not!
- Shows the streaming service or media player you are using in your status.
- Shows a button in the status that allows others to open a link the song
  (only for TIDAL right now).
- Shows the exact playback position, if the media player supports it.
- Controls are easily accessible via the tray menu.

## Supported media players

The following media players will be detected
and shared in your Discord status:

<span><a href="https://tidal.com"><img title="TIDAL" alt="" height="48" src="https://live.musicpresence.app/v2/tidal.ico"></a></span>&nbsp;
<span><a href="https://www.qobuz.com"><img title="Qobuz" alt="" height="48" src="https://live.musicpresence.app/v2/qobuz.ico"></a></span>&nbsp;
<span><a href="https://spotify.com"><img title="Spotify" alt="" height="48" src="https://live.musicpresence.app/v2/spotify.ico"></a></span>&nbsp;
<span><a href="https://www.deezer.com"><img title="Deezer" alt="" height="48" src="https://live.musicpresence.app/v2/deezer.ico"></a></span>&nbsp;
<span><a href="https://www.amazon.de/dp/B00CTTEKJW"><img title="Amazon Music" alt="" height="48" src="https://live.musicpresence.app/v2/amazon-music.ico"></a></span>&nbsp;
<span><a href="https://www.foobar2000.org"><img title="foobar2000" alt="" height="48" src="https://live.musicpresence.app/v2/foobar2000.ico"></a></span>&nbsp;
<span><a href="https://www.getmusicbee.com"><img title="MusicBee" alt="" height="48" src="https://live.musicpresence.app/v2/musicbee.ico"></a></span>&nbsp;
<span><a href="https://music.apple.com"><img title="Apple Music" alt="" height="48" src="https://live.musicpresence.app/v2/apple-music.ico"></a></span>&nbsp;
<span><a href="https://en.wikipedia.org/wiki/Windows_Media_Player_(2022)"><img title="Windows Media Player" alt="" height="48" src="https://live.musicpresence.app/v2/windows-media-player.ico"></a></span>&nbsp;
&ensp;*and more...*

This is only a selection of supported media players.
For a table of all players
and how well they are supported on each operating system,
please refer to [PLAYERS.md](./PLAYERS.md).

If your media player is not listed or detected, please
[suggest it](#my-media-player-is-not-detected),
as described below!

## Download

For downloads visit the
**[Releases](https://github.com/ungive/discord-music-presence/releases)**
page.
You can currently download Music Presence for **Windows** and **Mac**.
Support for **Linux** is underway
and will be added in a future update!

## Join the Discord server

Feel free to join the Discord server to stay in touch!

- **[Open the invite](https://discord-invite.musicpresence.app)**

## Donations

The development of this project largely depends
on the effort of a single developer,
who is working on this application in his free-time.
If you would like to support the development progress
or would simply like to show your appreciation,
you can do so by making a donation.
Thank you!

- **[Patreon](https://patreon.com/musicpresence)**
  &nbsp;&ndash;&nbsp; *the preferred option with
  [additional benefits](https://www.patreon.com/musicpresence/membership)*
- **[GitHub Sponsors](https://github.com/sponsors/ungive)**
- **[LiberaPay](https://liberapay.com/jonasvandenberg)**

For more information, check [FUNDING.md](./FUNDING.md).

## My media player is not detected

> The application is still in early development.
> If your media player is not detected, simply follow the steps outlined here
> to request support for your media player or streaming service.

To report that a media player is not detected:

1. In the tray menu, navigate to "Help"
   and click on "My media player is not detected".
2. A new GitHub issue will open in your browser.
3. Please describe which media player is not detected and submit the form.

The issue will be filled out with some information about your system.
This will help me add support for the media player that you are requesting.
Once you have submitted the issue, I will come back to you as soon as I can!

---

## Privacy

For detailed information on which data Music Presence collects
and to which services the data is sent,
please read [`PRIVACY.md`](./PRIVACY.md)
or click on "Privacy Notice" in the "Help" menu of the application.

## Roadmap

For an overview of features that are being worked on,
please read [ROADMAP.md](./ROADMAP.md).

## Changelog

For information about changes with each version
read the [CHANGELOG.md](./CHANGELOG.md) file.

## License

This project is licensed under the Music Presence license.  
For more information read the [LICENSE.txt](./LICENSE.txt) file.

## Legacy source code

For the source code of versions prior to version 2.0.0,
please visit the repository for the
[legacy source code](https://github.com/ungive/tidal-discord-presence).

## Disclaimer

- This software is **not** affiliated with or endorsed by Discord.  
- This software is **not** affiliated with or endorsed by
  any streaming service, media player or company that distributes music,
  including but not limited to those mentioned above.
