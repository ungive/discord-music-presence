# Privacy

## Overview

This section provides a short overview over how your data is processed.
It is not a complete summary or replacement of the sections that follow.
Please read the entire privacy notice for complete information
about how your data is processed.

* The Software only collects and shares data about media
  that is being played on your device.
  This includes media like audio and video playback from other applications.
* None of this data is shared with the developer of the Software.
* Some of this data is shared with third parties
  to provide the functionality of the application.
* You can control exactly which data is shared with third parties,
  by disabling some or all of the applications that play media.
  Information about media from disabled applications
  is never shared with third parties.
* You should be aware that some media might contain Personal Data.
  It is your responsibility to disable applications that play media
  with Personal Data attached to it.
* The application updates itself by default.
  This is done securely by downloading via an encrypted connection,
  verifying the download's content with a checksum
  and authenticating it with a cryptographic signature.
* Additionally, the application reports limited statistics at most once a day,
  to understand how many users are actively using the software,
  which old versions are still in use and for how long,
  whether automatic updates are enabled or not
  and which operating systems the application is used on.
  This is done completely anonymously.

## Table of Contents

<!-- TOC -->

* [Overview](#overview)
* [Table of Contents](#table-of-contents)
* [How does the Software collect data?](#how-does-the-software-collect-data)
* [What data is collected by the Software?](#what-data-is-collected-by-the-software)
  * [Media Metadata](#media-metadata)
  * [Analytics Metrics (privacy-friendly)](#analytics-metrics-privacy-friendly)
  * [No Personal Data](#no-personal-data)
  * [Reporting undetected media players](#reporting-undetected-media-players)
* [How is the data being used and shared?](#how-is-the-data-being-used-and-shared)
  * [Discord](#discord)
  * [TIDAL](#tidal)
  * [MetaBrainz - MusicBrainz and Cover Art Archive](#metabrainz---musicbrainz-and-cover-art-archive)
  * [Simple Analytics](#simple-analytics)
  * [GitHub](#github)
  * [Our own services](#our-own-services)
  * [Encryption](#encryption)
* [Which Media Metadata is shared by default?](#which-media-metadata-is-shared-by-default)
* [How can the user control which data is shared?](#how-can-the-user-control-which-data-is-shared)
* [Automatic updates](#automatic-updates)
* [Scope of this privacy policy](#scope-of-this-privacy-policy)
* [Changes to this privacy policy](#changes-to-this-privacy-policy)
* [Contact details](#contact-details)

<!-- /TOC -->

## How does the Software collect data?

Music Presence (the "Software")
runs in the background and permanently tracks, observes and handles
media playback on the device it is running on ("Media Observation").
This includes music and videos played by streaming services and Media Players,
but also music and videos played in a web browser.
Some of this data is collected and shared with third parties,
exactly how is outlined in the following sections.

## What data is collected by the Software?

### Media Metadata

The following data ("Media Metadata")
is collected when observing media playback:

* The title of the media (music or video title)
* The name of the person that created the media (the artist)
* The name of the album (album name)
* The name of the person that created the album (album artist)
* The duration of the song or video (or its length)
* The current playback position (how much of the media has been played)
* The exact time at which the media has started or stopped playing
* Information about the application that is playing the media, this includes:
  * The application's executable file name and full path
  * The application's bundle identifier (on macOS)
  * The application's display name
* The repeat mode of the song (whether the song or playlist is on repeat)
* The shuffle mode of the playlist
* The cover image of the media
  (this can be album artwork or a small thumbnail of the media)

### Analytics Metrics (privacy-friendly)

The following anonymous metrics ("Analytics Metrics")
are transmitted to a privacy-friendly analytics service
(Simple Analytics, more information in the next section)
at most once a day:

* The version of the Software that is used
* The operating system type (Windows, Mac or Linux) and its architecture
* Your current time zone (for region information) and your local time
* The following settings in regard to automatic updates:
  * Whether automatic updates are enabled
  * Whether update popups are enabled
  * Whether the changelog is shown
    when a new version is launched for the first time

This data is only used to understand
which older versions of the Software are still being used,
which operating system and architecture is used most predominantly
and from which regions users are vaguely coming from.
Additionally, the listed settings are reported
in order to understand how many users
are interested in updates of the Software.

When the user installs an update within the app,
either manually or because automatic updates are enabled,
and the installation fails with an error message,
the error message is anonymized
and transmitted to the mentioned analytics service.
This is necessary in order to know about update problems as soon as possible
and to be informed when critical errors occur that need attention.

To put these collected Analytics Metrics into perspective:
Nowadays almost all websites use some form of analytics
and most of them will collect much more information than what is listed above.
Your IP address is never stored or used in any way
(for specifics, see the privacy policy
and linked articles of Simple Analytics below).

### No Personal Data

No data that could be used to identify the user ("Personal Data")
is being *explicitly* collected or shared.
Media Metadata might *implicitly* contain Personal Data,
which may be shared with third parties, due to the nature of the software.
This might include the name of a relative in a personal home video
or the name of the user in a recorded audio file.
The Software has no control over this
and is not able to differentiate
whether some Media Metadata constitutes as Personal Data or not.

It is the responsibility of the user to:

1. be aware when media is being played that contains Personal Data
   in its Media Metadata;
2. disable the application that plays media
   with Personal Data in its Media Metadata
   via the controls in the Tray Menu of the Software
   (more on this in the following sections),
   or make sure it is already disabled;
3. to terminate the Software and make sure it is not running anymore,
   if any Media Metadata contains highly sensitive Personal Data.

In the event that Personal Data has been shared with third parties,
the data is handled by these third parties
in accordance with their privacy policies
(see the following sections).

### Reporting undetected media players

The user also has the option to report when a Media Player is not detected,
by clicking on "My media player is not detected" in the "Help" menu
of the Software.
This will open a [new issue on GitHub](
    https://github.com/jonasberge/discord-music-presence/issues/new)
that is filled out with the following information ("Report Information"):

* The user's operating system
* Which media players the user has used to play media with
  since the installation of the Software.
  This includes the name of the application and a unique identifier,
  that is specific to the operating system on which the Software is running:
  * On Windows and Linux: The executable name
  * On Mac: The bundle identifier

## How is the data being used and shared?

The Software uses Media Metadata
to upload it to the [Discord](https://discord.com/) platform,
to show other users of that platform
which media the user of the Software is playing on their device.
This functionality is called a "Presence".
When the Presence is "active" or "enabled",
Media Metadata is being actively shared with third parties.
When the Presence is "inactive" or "disabled", no data is being shared.

Media Metadata is never shared with the developer of the Software.

The Software sends some or all Media Metadata to the following services,
which will handle your Media Metadata
in accordance with their respective privacy policy:

### Discord

Media Metadata is sent to **Discord**, to show a
"[Rich Presence](https://discord.com/developers/docs/rich-presence/how-to)"
on the user's profile.
This Rich Presence aims to display
what media the user is currently listening to
and shows this information to other users of the Discord platform.

* **[Discord](https://discord.com/)**
  &ndash; [Privacy Policy](https://discord.com/privacy)

### TIDAL

Media Metadata may be sent to **TIDAL**, more specifically the
[TIDAL API](https://developer.tidal.com/documentation/api/api-overview),
to complete Media Metadata that is lacking song, track or video information
and to get more information about the media that is playing
from an online music database.

This service can be disabled in the settings of the Software.

* **[TIDAL](https://tidal.com/)**
  &ndash; [Privacy Policy](https://tidal.com/privacy)

### MetaBrainz - MusicBrainz and Cover Art Archive

Media Metadata may be sent to **MetaBrainz**, more specifically the
[MusicBrainz API](https://musicbrainz.org/doc/MusicBrainz_API)
and the [Cover Art Archive](https://coverartarchive.org/),
to complete Media Metadata that is lacking song, track or video information
and to get more information about the media that is playing
from an online music database.

This service can be disabled in the settings of the Software.

* **[MetaBrainz](https://metabrainz.org)**
  &ndash; [Privacy Policy](https://metabrainz.org/privacy)

### Simple Analytics

Analytics Metrics are sent to this service:

* **[Simple Analytics](https://simpleanalytics.com)**
  &ndash; [Privacy Policy](https://simpleanalytics.com/privacy-policy)
  * Article: [We don't track people](https://simpleanalytics.com/no-tracking)
  * Article: [What we do (and don't) collect](https://docs.simpleanalytics.com/what-we-do-and-dont-collect)

**Simple Analytics** does not store any personal data.
To find out which data this analytics service stores,
besides the Analytics Metrics mentioned in the previous section,
visit [this link](https://docs.simpleanalytics.com/what-we-collect)
("What we collect") on their website.

### GitHub

Report Information is transmitted to **GitHub**
and handled according to their privacy policy:

* **[GitHub](https://github.com)**
  &ndash; [Privacy Policy](
    https://docs.github.com/en/site-policy/privacy-policies/github-general-privacy-statement)

Additionally, the following requests are made to **GitHub**
on application startup:

* Download of information about media players from
  [live.musicpresence.app](https://live.musicpresence.app),
  which is hosted on **GitHub**
  ([repository](https://github.com/jonasberge/live.musicpresence.app)).
  **GitHub** may collect data in accordance with their Privacy Policy.
* Check for a new release of Music Presence.
  The Software makes a request to **GitHub**'s API
  to check whether there is a new release of Music Presence.
  **GitHub** may collect data in accordance with their Privacy Policy.

### Our own services

We provide our own services to extend the functionality of the Software
in accordance with this privacy policy.
These include the following services:

- A proxying service which makes cover images from media players
  accessible via a randomly generated, internet-accessible URL
  for a short amount of time,
  such that they can be shown in a Rich Presence on Discord.
  This service can be disabled in the settings.

### Encryption

All data is **encrypted** with the use of
modern and secure transport protocols,
when sent to **TIDAL**, **MetaBrainz**, **Simple Analytics**, **GitHub**
and our own services.
Media Metadata that is sent to **Discord** communicates
with the locally running Discord client application
without the use of a connection over an external network
and therefore does not use encryption,
since it does not leave the user's device.

## Which Media Metadata is shared by default?

By default, the Software will only share Media Metadata
from applications that have been whitelisted by the developer of the Software.
That means not all Media Metadata is shared by default,
but only that of a predefined set of applications.

The user can expect that all Media Metadata
from a Media Player will be shared by default,
if the Media Player in question meets the following criteria:

* The Media Player is **not** a web browser.
  Web browsers can play various kinds of media,
  including media like videos, podcasts and music,
  where it would be impossible to be certain,
  that the user always intends to share this media with other people.
* The Media Player is **not** any other multimedia player, or more generally,
  it is **not** frequently used to play media other than music.
  This means applications like the Windows Media Player,
  QuickTime or the VLC Media Player are not enabled by default.
  Videos are not intended to be shared with the Software by default.

The Software **can** and **will** share Media Metadata by default,
if the application is designed to play music most of the time.
This includes popular music streaming services
and music player applications which play local sound files.

Nevertheless, the user can **opt-in**
to share media from any Media Player they wish,
by toggling the state of a Media Player application in the Tray Menu.

## How can the user control which data is shared?

While the Software is opened,
it can be interacted with and controlled via the icon ("Tray Menu")
in the system's task bar or system tray.

All sharing of Media Metadata can be disabled
by disabling the Presence.
This is done by toggling the checkbox in the Tray Menu of the Software
with the name "Presence is active".
Once the text next to the checkbox has changed to "Presence disabled"
no Media Metadata is shared.
This is the case as long as "Presence disabled" is visible.
The Presence can only be enabled again by the user.

To know whether media from a specific application will be shared,
the user can disable the Presence (as described above),
start an application that can play media ("Media Player")
and play media with it,
then open the Tray Menu of the Software
and check whether the entry for the Media Player says "enabled".
The entry can be identified with the Media Player's application name.
If the Media Player is enabled, Media Metadata that stems from it
will be shared.
If Media Metadata from this Media Player should not be shared,
the user can click on it to toggle it.
After doing so "enabled" disappears and an "x" appears
in front of the name of the Media Player,
to signal that no Media Metadata from that Media Player
will be shared with third parties.

## Automatic updates

The Software checks for updates on application startup
and at an interval of 12 hours while it is running.
When a new version is available and automatic updates are enabled,
the Software downloads the update in the background.
The downloaded update then goes through the following checks,
to ensure that it has not been tampered with and stems from a trusted source:

- A checksum is used to verify the file's integrity,
  i.e. that the contents have not been modified.
- A cryptographic signature is used to verify the file's authenticity,
  i.e. that it stems from a trusted source
  (the developer of the Software and no other party).
- The signature is also used to ensure
  that the application is never downgraded to an older version.

Once all those checks have passed,
the update is installed to the user's computer
and executed after the application has been restarted.
For more detailed information read the
[documentation](https://automatic-updates-docs.musicpresence.app/).

Automatic updates can be disabled in the settings.
If they are disabled, the user has the option to install updates manually
by clicking the respective button in the Tray Menu.

---

## Scope of this privacy policy

This document applies to version 2.2.1 of Music Presence and that version only.

## Changes to this privacy policy

This privacy policy is kept under regular review.
Any updates are placed into this file in this repository.
The last update to this policy is stated below.

Last updated on 3 September 2024.  
This does not include changes to the scope of this privacy policy.

## Contact details

If you have any questions about this privacy policy
or if you found an error, feel free to send an email to:

* [privacy+954c50d8@musicpresence.app](
    mailto:privacy+954c50d8@musicpresence.app)
