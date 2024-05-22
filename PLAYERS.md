# Supported media players

Overview of supported media players for each operating system.

## Support Table

> Note: A release for Linux is being worked on.

| Application      |                   Windows                   |           Mac            |          Linux           | test status               |
|------------------|:-------------------------------------------:|:------------------------:|:------------------------:|:--------------------------|
| TIDAL            |             :white_check_mark:              |    :white_check_mark:    |           ...            | paid only                 |
| Amazon Music     | :white_check_mark: :face_with_head_bandage: |   :white_check_mark:*    |     :grey_question:      | paid only                 |
| Apple Music      |               :grey_question:               |    :white_check_mark:    |     :grey_question:      | unpaid + local files only |
| Deezer           |             :white_check_mark:*             |   :white_check_mark:*    |     :grey_question:      | unpaid only               |
| foobar2000       |             :white_check_mark:*             |    :white_check_mark:    | :heavy_multiplication_x: | fully tested              |
| MusicBee         |         :white_check_mark: :pencil:         | :heavy_multiplication_x: | :heavy_multiplication_x: | fully tested              |
| Qobuz            |             :white_check_mark:*             |        :warning:         | :heavy_multiplication_x: | unpaid only               |
| Spotify          |           :ballot_box_with_check:           | :ballot_box_with_check:  |           ...            | not tested                |
| Spotify (unpaid) |                  :warning:                  |    :white_check_mark:    |           ...            | fully tested              |

### Legend

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

## Additional notes

### Music Bee

Music Bee works well with this plugin:
https://github.com/HenryPDT/mb_MediaControl

The installation of such a plugin is required
because otherwise MusicBee does not report what it is playing to Windows.
Once you have installed and enabled it, Music Presence should detect Music Bee.

---

## Players with known issues

> These are issues with the ***media players themselves***,
not with Music Presence!
Affected players are sometimes reporting
incorrect song metadata or playback information,
Music Presence cannot do anything about that.

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
