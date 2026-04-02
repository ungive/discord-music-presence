# Supported media players

For an always up-to-date list of support media players visit:

**https://nimigames68.github.io/Music-Presence-Players**

This site was created by the community member [@NimiGames68](https://github.com/NimiGames68).

If your media player is not detected,
visit the [**troubleshooting**](./troubleshooting.md) page.

## Required plugins and helper programs

Some media players require a plugin or helper program.
Please refer to the list below for your media player.

### Qobuz

Since a past update Qobuz has stopped reporting what it's playing to Windows.

Possible workarounds are:
- Downgrading your Qobuz version, see this GitHub issue comment: https://github.com/ungive/discord-music-presence/issues/244#issuecomment-3556269025
- Modifying your Qobuz installation (might violate ToS): https://github.com/TubaApollo/qobuz-smtc

If you are on Linux, you can use the Qobuz website in a Firefox-based browser
or the install QBZ Qobuz desktop client: https://github.com/vicrodh/qbz.
Music played with either option will be detected by Music Presence

### MusicBee

MusicBee works well with this plugin:
https://github.com/HenryPDT/mb_MediaControl

The installation of such a plugin is required
because otherwise MusicBee does not report what it is playing to Windows.
Once you have installed and enabled it, Music Presence should detect Music Bee.

### foobar2000

While foobar2000 reports basic information out of the box,
this plugin will add the album name and a progress bar to your status:
https://github.com/ungive/foo_mediacontrol

This is a fork of an old plugin which I have adapted
to report missing song information.

### AIMP

AIMP requires this plugin to work:
https://www.aimp.ru/forum/index.php?topic=63341

Unfortunately this plugin does not report accurate playback information,
but everything else seems to work just fine.

### VLC

VLC requires this plugin to work:
https://github.com/spmn/vlc-win10smtc

At the moment this plugin does not report any cover images,
nor an accurate playback position.

### iTunes

On Windows you will need to run this helper program
for iTunes to report currently playing media to Windows:
https://github.com/thewizrd/iTunes-SMTC.
After that it should be detected and you should see it in your status.

iTunes on Mac is not supported as all versions for iTunes on Mac are too old.

### Winamp

For classic Winamp you might need this plugin,
for the player to report the currently playing media to Windows:

https://github.com/NanMetal/gen_smtc

### mpv

On Windows, mpv must either be run with `--media-controls=yes`
or by setting `media-controls=yes` in your `mpv.conf` file.
Otherwise mpv does not report currently playing media to Windows.

On Mac, you must install and run mpv using an app bundle
(file ending with `.app`),
otherwise it cannot be detected at this time.
Installing it with brew only installs a command line tool.
If you need Music Presence to work with the command line tool only
and you don't want to install an app bundle,
please [open an issue](https://github.com/ungive/discord-music-presence/issues).

If cover images are not showing or the above setting is not available,
try updating mpv or installing a development version of mpv.

---

## Players with known issues

Some media players do not report metadata properly.
Note that these are issues with the ***media players themselves***,
not with Music Presence.
Affected players are sometimes reporting
incorrect song metadata or playback information,
we unfortunately can't do much about that.

Known cases:

- **Windows Media Player** (Windows 10) stops working randomly
  and does not report album covers.
  If you are looking for suitable alternative that works with Music Presence,
  have a look at [ScreenBox](https://apps.microsoft.com/detail/9ntsnmsvcb5l)
- **Amazon Music** consistently reports bad metadata
  and never reports the album cover.
  The only solution is to switch streaming services
- **foobar2000**: Out of the box, foobar2000 does not report the album
  and the track duration, so you won't see a progress bar in your status.
  You need to install the
  [foo_mediacontrol](https://github.com/ungive/foo_mediacontrol)
  plugin for this

This list is a non-exhaustive.
