# How to install and use Music Presence

To install Music Presence, pick the right download for your platform:

<!-- DL_BUTTONS_BEGIN -->
[<img src="https://raw.githubusercontent.com/ungive/discord-music-presence/refs/heads/master/assets/download-win-exe-x64-2x.png" width="182">](https://github.com/ungive/discord-music-presence/releases/download/v2.3.0/musicpresence-2.3.0-windows-x64-installer.exe)&ensp;
[<img src="https://raw.githubusercontent.com/ungive/discord-music-presence/refs/heads/master/assets/download-win-zip-x64-2x.png" width="182">](https://github.com/ungive/discord-music-presence/releases/download/v2.3.0/musicpresence-2.3.0-windows-x64.zip)&ensp;
[<img src="https://raw.githubusercontent.com/ungive/discord-music-presence/refs/heads/master/assets/download-mac-dmg-arm64-2x.png" width="182">](https://github.com/ungive/discord-music-presence/releases/download/v2.3.0/musicpresence-2.3.0-mac-arm64.dmg)&ensp;
[<img src="https://raw.githubusercontent.com/ungive/discord-music-presence/refs/heads/master/assets/download-mac-dmg-x86_64-2x.png" width="182">](https://github.com/ungive/discord-music-presence/releases/download/v2.3.0/musicpresence-2.3.0-mac-x86_64.dmg)
<!-- DL_BUTTONS_END -->

> *Don't know what download to choose?*
> *Click [**here**](#which-download-should-i-choose)*
> *or scroll to the bottom of the page.*

Continue reading for detailed instructions on how to install your download.

After installing the app for the first time,
you should see the following popup window appear.
That's when you know you did everything right
and you're ready to use Music Presence!

![](../assets/screenshot-first-start.png)

## Windows

If you downloaded the `exe` file,
simply double-click it and follow the installer's instructions.
At the end you should be given the option to launch Music Presence.
You will also get a start menu entry and for convenience,
Music Presence will launch whenever you log into your computer.

If you picked the `zip` file download,
you have to right-click and extract it,
then open the extracted folder, double-click `Music Presence.exe`
and you are good to go!

## Mac

Installation on Mac can be a little more tricky, especially on macOS Sequoia.

At this time your Mac won't be able to
"identify the developer" of Music Presence
because the application is not signed by me yet.
You might get a dialog that says one of the following things (in quotes):

> "Music Presence cannot be opened because it is from an unidentified developer"

In this case it should be enough to hold down your Control key
while you right-click the app and click Open,
and then click Open again in the popup window that appears.

Alternatively you can navigate to your system settings,
go to Privacy & Security and there should be an option to "open anyway".
If not, try opening Music Presence again
and see if you can click "open anyway" now.

> "Music Presence is damaged and can't be opened"

This is macOS Sequoia or newer "quarantining" any download it can't verify.
In reality the file is *not* damaged and it *can* be opened,
macOS is just trying to protect you from malicious downloads
in a rather questionable way that puts you out of control.

To work around this, please check the following help article:

- https://discussions.apple.com/thread/253714860?sortBy=rank

## After installation

After you installed and started Music Presence,
you should see an icon in the tray menu of your device:

![Music Presence in the Windows tray menu](../assets/tray-windows.png)

On Windows it might be hidden under the little arrow
when you start it for the first time:

![Music Presence in the Windows tray overflow menu](../assets/tray-windows-hidden.png)

On Mac it should appear in your system tray as well:

![Music Presence in the Mac tray menu](../assets/tray-mac.png)

Right-click on the icon to open the settings,
the rest should be straight-forward!

If your media player is not detected,
please read the troubleshooting guide [**here**](./troubleshooting.md).

## Which download should I choose?

Are you on Windows? Simply pick the `exe` download,
this should be the easiest to install!

On Mac you need to check if you're using an Intel or an Apple Silicon Mac first.
Click the Apple logo in the top left of your screen,
then click "About This Mac".

- If it shows "M1", "M2", "M3" or similar under the Chip category,
  then you're on **Apple Silicon**
  and you need to pick the Apple Silicon download from above
- If it shows "Intel" under the Processor category,
  you're using an **Intel** CPU and you need to pick the
  "Intel x86_64" download from above

## Still need help?

Join our Discord community:
[**discord.gg/musicpresence**](https://discord.gg/musicpresence)

Or open an issue here:
[**github.com/ungive/discord-music-presence/issues**](https://github.com/ungive/discord-music-presence/issues)

---

## If you're willing to donate to the project

You can make a small monthly donation to help with
making the installation experience more straightforward and less involved,
especially for Mac users.
Your donation would allow me to:

- Get an Apple Developer account (99 USD a year) to sign macOS builds
  and completely remove the above errors.
  Also allows me to add animated album art for Apple Music
  ([#23](https://github.com/ungive/discord-music-presence/issues/123))
- At some point get a Windows signing certificate
  (prices vary, but certificates cost multiple hundred dollars a year).
  The need for this is not as high as signed builds for macOS though,
  since macOS makes it especially hard to install unsigned apps,
  even more so since macOS Sequoia

Check the links [**here**](https://donate.musicpresence.app)
for all available donation options.
Thank you, if you do decide to make a donation!
