# Integrating with Music Presence

Are you interested in integrating
your application or service with Music Presence?

This is a work-in-progress,
but the plan is to allow our users to integrate external services
in order to **stream real-time playback information of currently playing music**
not only to Discord, but **anywhere they want**.

If you are a service provider, please contact me either
by joining our [Discord server](https://discord-invite.musicpresence.app)
and shooting me a message or using one of the contact options
on my [GitHub profile](https://github.com/ungive).

If you are a user and you wish to see integration of a specific service
(or a service that does not exist yet but should), feel free to
[open an issue](https://github.com/ungive/discord-music-presence/issues/new/choose).

Real-time playback information includes:

- The exact playback position at any given point in time
- The title of the song, the name of the artist and the album name
- Which media player is playing the song (e.g. Spotify or TIDAL)
- A link to the song, if it's played by a streaming service's media player
  (e.g. a Spotify URL if it's played by Spotify
  or a TIDAL URL if played by TIDAL)
- The album cover image from the user's media player
  (either the raw data or a temporary URL to it)
- and [more](https://github.com/ungive/discord-music-presence/blob/master/PRIVACY.md#media-metadata)...

Ideas how this data could be used:

- Synchronizing playback between users, ***across media players***.
  That means someone listening on TIDAL
  could listen along with someone who uses Spotify.
- ...
