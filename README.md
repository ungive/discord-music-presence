[![Build status](https://ci.appveyor.com/api/projects/status/bthj30lvfthw9es0?svg=true)](https://ci.appveyor.com/project/jonasberge/discord-music-presence)
[![GitHub Release Downloads](https://img.shields.io/github/downloads/jonasberge/discord-music-presence/total?style=flat)](https://github.com/jonasberge/discord-music-presence/releases)
[![GitHub Sponsor](https://img.shields.io/badge/sponsor-30363D?style=flat&logo=GitHub-Sponsors)](https://github.com/sponsors/jonasberge)

# Discord Music Presence

This is a desktop application to share your listening activity
on Discord by showing a custom status via Disord's Rich Presence.
Currently only supports the TIDAL music player, but plans are set in place
to include other music players as well in the near future.
Discord deeply integrates Spotify into its ecosystem,
but other music players and streaming services are not supported at all.
This application aims to fill this hole.

> ![Screenshot of what the discord status currently looks like](./assets/screenshot-2.png)

This project emerged as a fork of the wonderful TIDAL rich presence plug-in by Stavros Avramidis,
which you can find [here](https://github.com/purpl3F0x/TIDAL-Discord-Rich-Presence-UNOFFICIAL).
Check the [changelog](./CHANGELOG.md) and [roadmap](./ROADMAP.md)
to see progress on development of this application.

## Installation

Download a release ZIP (Windows) or DMG (macOS) from latest release here
[here](https://github.com/jonasberge/discord-music-presence/releases).
Make sure to open the **Assets** dropdown menu on this page to see these files.
Extract or install the application and run it.
A small icon should appear in the status bar of your desktop.
Right-click it to open the controls.

Make sure to also enable "Share your activity with others" on Discord,
by going into your settings and navigating to "Activity Settings > Activity Privacy".
Play a song in your music player and observe it being shared as an activity on Discord.

## Supported Music Players and other Media Sources

Here is a table of supported music players, streaming services
or other media sources on each operating system:

| Player | Windows | Mac OS | Linux |
|:-|:-:|:-:|:-:|
| TIDAL | :heavy_check_mark: | :heavy_check_mark: | :memo: |
| Qobuz | :memo: | :memo: | :x: |
| Desktop Media\* | :memo: | ... | ... |
| Browser Media\*\* | ... | ... | ... |
| Spotify | ... | ... | ... |

\* *Selected media played on your desktop,
independent of the source. Work in progress*  
\*\* *Selected media played in your browser*

### Legend

- :heavy_check_mark: Supported
- :x: Likely no support in the future
- :memo: Support is being worked on and will likely arrive soon
- Three dots indicate that support might be added at some point in the future,
but it is currently unclear whether it is technically possible or feasible.

For reasoning behind each choice,
see "Media Player Support" in the [ROADMAP](./ROADMAP.md) file.

### Android and iOS

Mobile support might be added in the future,
but is currently not on the radar,
as other features take priority at the moment.
If you would like to share your non-Spotify music listening status on your phone,
let me know by [opening an issue](https://github.com/jonasberge/discord-music-presence/issues)!

## Customization

The application supports limited customization options at this point in time,
but will support more options in the future!

### Changing the "Playing Music" status to something else

You can change the text after "Playing" to anything you like,
by using a custom Discord application ID,
by creating an application [here](https://discord.com/developers/applications),
giving it a custom name, then copying its "Application ID"
and passing this ID as an argument to the application.
Find more detailed instructions for Windows
[here](https://github.com/purpl3F0x/TIDAL-Discord-Rich-Presence-UNOFFICIAL/pull/100#issuecomment-2007452770).

About "Playing": Currently it is only possible to show "Playing ..." as the status,
as the Discord Game SDK [does not support](https://github.com/discord/discord-api-docs/issues/1002)
any other status like "Listening to ..." (which is what Spotify uses).
Bots are allowed to do this, and it is technically possible to create a self-bot
which shows your activity as "Listening to Music" or "Listening to TIDAL",
but creating a self-bot is against Discord's ToS
and will therefore not be implemented.

### Changing the look of the Discord status

This will be supported in a future version of this application! Stay tuned!

## Contributing

As a user, you can contribute by reporting issues and bugs
or by making feature requests.
To do so, simply create an issue
[here](https://github.com/jonasberge/discord-music-presence/issues).
Any suggestions are welcome!

As a developer, you can contribute by making a
[pull request](https://github.com/jonasberge/discord-music-presence/pulls).

For development and build instructions check [BUILD.md](./BUILD.md).

## Funding

You can support the development of this project
by funding the maintainer through one of the following means:

- GitHub Sponsors: [github.com/sponsors/jonasberge](https://github.com/sponsors/jonasberge)

Thank you for your support!

## Acknowledgments

- Stavros Avramidis, author of the original project  
[purpl3F0x/TIDAL-Discord-Rich-Presence-UNOFFICIAL](https://github.com/purpl3F0x/TIDAL-Discord-Rich-Presence-UNOFFICIAL)  
[github.com/sponsors/purpl3F0x](https://github.com/sponsors/purpl3F0x)

## Libraries used

- [nlohmann/json](https://github.com/nlohmann/json)
- [yhirose/cpp-httplib](https://github.com/yhirose/cpp-httplib)
- [Discord Game SDK](https://discord.com/developers/docs/game-sdk/getting-started)

## License

Distributed under the MIT License.
See `LICENSE` for more information.
