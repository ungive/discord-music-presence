# Where are Music Presence files located?

You can find the Music Presence settings, logs and other files in these directories:
- Windows: `%APPDATA%\Music Presence`
- Mac: `~/Library/Application Support/Music Presence`
- Linux: `~/.local/share/Music Presence`

Note that the `~` symbol resembles your home directory,
e.g. `/Users/Me` on Mac or `/home/me` on Linux.

You will find files like the following:
- `settings.json`: Your Music Presence settings. This file does not contain any personal data and can be safely shared with other people. Some settings rely on data that is stored in `stats.json` though, e.g. which Discord accounts you disabled the presence for and your entered music API credentials.
- `stats.json` (SENSITIVE): Locally stored statistics of events that occurred while the app was running and which need to be remembered across app restarts. This file can also contain personal information, like the IDs and usernames of the Discord accounts you have used Music Presence with and the music API credentials you entered in the settings. Do not share this file with anyone!
- `presence.log`: Application logs that can be useful for debugging and finding the cause for errors. This may contain personal information, so please review it before uploading it publicly. Personal information may include the name of the user on your computer, your Discord username, your Last.fm (or other scrobbling service) username and similar information. Keys and passwords are never logged.

None of these mentioned files, any other files or the information therein are uploaded anywhere. 
