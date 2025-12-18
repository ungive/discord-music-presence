# Self-hosted cover image proxy

To host your own cover image server, follow the steps in this document:
https://github.com/ungive/loon/blob/master/deployments/basic-deployment/README.md

After setting up the server,
make sure you've followed the steps in the section
"Server is running on a remote server",
to make sure that it is accessible from the internet.

After that you can enter your information into Music Presence:

1. Open the Music Presence setting window
2. Go to Discord > Services and scroll down to "Custom cover proxy server"
3. For "Websocket URL" enter e.g. `wss://example.com/ws`,
   if you are using HTTPS (you should)
   and your server's domain is `example.com`.
   Change the domain to the actual domain of your server
4. For Discord it is important that you configured the "frontend base URL"
   to be a `http://` URL.
   Discord won't display images from URLs with self-signed certificates.
   You will therefore have to open up 2 ports on your server,
   one for HTTP (80 by default) and one for HTTPS (443 by default)
5. Enter your username in the "Username" field
6. Enter your password in the "Password" field
7. Check the box for "Disable TLS verification".
   This is required with self-signed TLS certificates
   and connecting will not work, if you do not check this box
8. Hit "Save" and verify that the connection succeeded in the status message

If something went wrong, check your `presence.log` file:

- Windows: `%APPDATA%\Music Presence\presence.log`
- Mac: `~/Library/Application Support/Music Presence/presence.log`
- Linux: `~/.local/share/Music Presence/presence.log`

It will contain detailed information on what happened.

If you need more help setting up your server,
feel free to join the Music Presence Discord:

**https://discord.gg/musicpresence**
