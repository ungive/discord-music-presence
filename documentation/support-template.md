# Support request template

You can use this template to send to the support team for a media player,
when that player does not report what it is playing to the operating system
and is therefore not detected by Music Presence.

The following quote outlines what the developers of the media player need to do
for the media player to report information about currently playing media
and what song metadata is required to make the media player
work flawlessly with Music Presence.
It also outlines that doing this not only
makes Music Presence detect the media player,
but also offers the users of the media player a better user experience:

> For your media player to be detected by Music Presence, it needs to report what media it is playing to the operating system. On Windows this would e.g. be done via SMTC (System Media Transport Controls), which is the Windows API that pretty much every media player or application uses to offer playback information and media controls to the user through Windows's native controls: https://imgur.com/a/YDQegwW Implementing this would not only make your media player work with Music Presence, but also offer every user of your player a better user experience and proper integration with the operating system, which ultimately improves the quality of your media player as a whole. Your media player should report at least this information to work flawlessly with Music Presence: Playback status (playing or paused), song title, artist, album name, live playback position, song duration and the album cover image. Official Windows Documentation for SMTC: https://learn.microsoft.com/en-us/uwp/api/windows.media.systemmediatransportcontrols On Mac devices the "MediaRemote" framework is used by Music Presence to detect media from applications, on Linux your media player should use MPRIS to report what it is playing. These are standard protocols/APIs which are widely used for the purpose of reporting what media an application is playing.

You can quote me on this in case you open a feature request with a media player.

Good luck!
