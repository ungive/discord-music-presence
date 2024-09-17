# Supported media players

> [!NOTE]
> If your media player is not detected,
read [below](#my-media-player-is-not-detected-)
for more information on what you can do.

## Overview

**Streaming services**

<span><a href="https://tidal.com"><img title="TIDAL" alt="" height="48" src="https://live.musicpresence.app/v2/tidal.ico"></a></span>&nbsp;
<span><a href="https://www.qobuz.com"><img title="Qobuz" alt="" height="48" src="https://live.musicpresence.app/v2/qobuz.ico"></a></span>&nbsp;
<span><a href="https://spotify.com"><img title="Spotify" alt="" height="48" src="https://live.musicpresence.app/v2/spotify.ico"></a></span>&nbsp;
<span><a href="https://www.deezer.com"><img title="Deezer" alt="" height="48" src="https://live.musicpresence.app/v2/deezer.ico"></a></span>&nbsp;
<span><a href="https://www.amazon.com/music"><img title="Amazon Music" alt="" height="48" src="https://live.musicpresence.app/v2/amazon-music.ico"></a></span>&nbsp;
<span><a href="https://music.apple.com"><img title="Apple Music" alt="" height="48" src="https://live.musicpresence.app/v2/apple-music.ico"></a></span>&nbsp;
<span><a href="https://th-ch.github.io/youtube-music/"><img title="YouTube Music (Unofficial Desktop)" alt="" height="48" src="https://live.musicpresence.app/v2/youtube-music.ico"></a></span>&nbsp;

**Offline media players**

<span><a href="https://www.foobar2000.org"><img title="foobar2000" alt="" height="48" src="https://live.musicpresence.app/v2/foobar2000.ico"></a></span>&nbsp;
<span><a href="https://www.getmusicbee.com"><img title="MusicBee" alt="" height="48" src="https://live.musicpresence.app/v2/musicbee.ico"></a></span>&nbsp;
<span><a href="https://en.wikipedia.org/wiki/Windows_Media_Player_(2022)"><img title="Windows Media Player" alt="" height="48" src="https://live.musicpresence.app/v2/windows-media-player.ico"></a></span>&nbsp;
<span><a href="https://apps.microsoft.com/detail/9nblggh67n4f"><img title="Next-Player (DryForest)" alt="" height="48" src="https://live.musicpresence.app/v2/next-player.ico"></a></span>&nbsp;
<span><a href="https://winamp.com/"><img title="Winamp" alt="" height="48" src="https://live.musicpresence.app/v2/winamp.ico"></a></span>&nbsp;
<span><a href="https://getwacup.com/"><img title="WACUP" alt="" height="48" src="https://live.musicpresence.app/v2/wacup.ico"></a></span>&nbsp;
<span><a href="https://github.com/Sandakan/Nora"><img title="Nora Music" alt="" height="48" src="https://live.musicpresence.app/v2/nora.ico"></a></span>&nbsp;
<span><a href="https://www.aimp.ru"><img title="AIMP" alt="" height="48" src="https://live.musicpresence.app/v2/aimp.ico"></a></span>&nbsp;

## Support Table

| Desktop Application       |                   Windows                   |           Mac            |          Linux           | test status                |
|---------------------------|:-------------------------------------------:|:------------------------:|:------------------------:|:---------------------------|
| TIDAL                     |             :white_check_mark:              |    :white_check_mark:    |           ...            | paid only*                 |
| Amazon Music              | :white_check_mark: :face_with_head_bandage: |   :white_check_mark:*    |           ...            | paid only*                 |
| Apple Music               |               :grey_question:               |    :white_check_mark:    |           ...            | unpaid* + local files only |
| Deezer                    |             :white_check_mark:*             |   :white_check_mark:*    |           ...            | unpaid only*               |
| foobar2000                |             :white_check_mark:*             |    :white_check_mark:    | :heavy_multiplication_x: | fully tested               |
| MusicBee                  |         :white_check_mark: :pencil:         | :heavy_multiplication_x: | :heavy_multiplication_x: | fully tested               |
| Qobuz                     |             :white_check_mark:*             |        :warning:         | :heavy_multiplication_x: | unpaid only*               |
| Spotify                   |           :ballot_box_with_check:           | :ballot_box_with_check:  |           ...            | not tested                 |
| Spotify (unpaid)          |                  :warning:                  |    :white_check_mark:    |           ...            | fully tested               |
| Windows Media Player      | :white_check_mark: :face_with_head_bandage: | :heavy_multiplication_x: | :heavy_multiplication_x: | fully tested               |
| YouTube Music<sup>1</sup> |             :white_check_mark:              |           ...            |           ...            | fully tested               |
| Next-Player<sup>2</sup>   |             :white_check_mark:              | :heavy_multiplication_x: | :heavy_multiplication_x: | fully tested               |
| Winamp                    |             :white_check_mark:*             | :heavy_multiplication_x: | :heavy_multiplication_x: | fully tested               |
| WACUP                     |             :white_check_mark:*             | :heavy_multiplication_x: | :heavy_multiplication_x: | fully tested               |
| Nora<sup>3</sup>          |             :white_check_mark:              | :heavy_multiplication_x: |           ...            | fully tested               |
| AIMP                      |        :white_check_mark:* :pencil:         | :heavy_multiplication_x: |           ...            | fully tested               |

|          Symbol          | Meaning                                                                        |
|:------------------------:|--------------------------------------------------------------------------------|
|    :white_check_mark:    | This player is supported                                                       |
|   :white_check_mark:*    | This player is supported, but only reports basic playback information          |
|         :pencil:         | Does not work out of the box, please check the additional notes below          |
| :face_with_head_bandage: | This player has known issues, see below                                        |
| :ballot_box_with_check:  | This player is supported and should work, but wasn't explicitly tested         |
|        :warning:         | Does not report any playback information unfortunately                         |
| :heavy_multiplication_x: | Not available on this operating system                                         |
|     :grey_question:      | Not tested or not known to have a desktop application on this operating system |
|           ...            | Not supported yet, but will likely be added in the future                      |

> Media from websites in browsers and Linux are not yet supported

*\* This means Music Presence was only tested
with the paid or unpaid version of the player,
i.e. with a paid subscription or with the free, unpaid version*

<sup>1</sup> Using [this](https://github.com/th-ch/youtube-music) unofficial desktop app  
<sup>2</sup> From the developer "DryForest", [link](https://apps.microsoft.com/detail/9nblggh67n4f)  
<sup>3</sup> [GitHub](https://github.com/Sandakan/Nora)

## Additional notes

### MusicBee

MusicBee works well with this plugin:
https://github.com/HenryPDT/mb_MediaControl

The installation of such a plugin is required
because otherwise MusicBee does not report what it is playing to Windows.
Once you have installed and enabled it, Music Presence should detect Music Bee.

### AIMP

AIMP requires this plugin to work:
https://www.aimp.ru/forum/index.php?topic=63341

Unfortunately this plugin does not report accurate playback information,
but everything else seems to work just fine.

## My media player is not detected 😢

If this happens, simply follow these steps:

1. In the tray menu of the application,
   navigate to "Help" and click on "My media player is not detected"
2. A new GitHub issue will open in your browser,
   you will have to log in with a GitHub account
3. Please describe which media player is not detected and submit the form

The issue will be filled out with some information about your system.
This will help me add support for the media player that you are requesting.

Once you have submitted the issue, I will come back to you as soon as I can.
Adding support for a player usually doesn't take very long
and you can expect to be able to use it within the day!

---

## Players with known issues

> These are issues with the ***media players themselves***,
> not with Music Presence!
> Affected players are sometimes reporting
> incorrect song metadata or playback information,
> we unfortunately can't do much about that.

> Also note that the information here was gathered some time ago
> and might be outdated for some media players.
> Contributions with updated information are very welcome.

### Not working randomly

Some players stop reporting song information arbitrarily at some point.

- Windows Media Player on Windows

### Incorrect song metadata

The following players sometimes report incorrect song information,
like a missing artist, a scrambled song name or no information at all,
which might cause some songs to not be shown in your status
or only with incomplete information.

- Amazon Music on Windows

### Players with only basic playback information

#### No precise playback position

These players do not report a precise playback position
and will only show how much time has elapsed since starting the song,
instead of adjusting correctly,
depending on which playback position you jump to in the song.

- Amazon Music on Windows
- Amazon Music on Mac
- Deezer on Windows
- Deezer on Mac
- foobar2000 on Windows
- Qobuz on Windows
- Winamp on Windows
- WACUP on Windows
- AIMP on Windows

#### Incorrect playback position timestamp

These media players report a playback position
(which might also be imprecise, see above),
but they also say e.g. "this playback position is from 10 minutes ago"
even though the media just started playing and it should say something like
"this playback position is from a few seconds ago".
This only becomes a problem when pausing the song and continuing it later,
which might report something like "13:04 elapsed"
for a song that's 3 minutes long.

- Deezer on Mac
