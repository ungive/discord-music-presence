# Checksums and signatures for releases

This directory contains checksum and signature files of each release,
in addition to them being published with a GitHub release.
The automatic updater downloads these files from these links:

- https://ungive.github.io/discord-music-presence/releases/2.1.3/sha256sum.txt
- https://ungive.github.io/discord-music-presence/releases/2.1.3/sha256sum.txt.sig

This is done so that the download counter on GitHub is not artifically inflated
and does not show more downloads than there actually are.
If this wasn't done any automatic update would increase the counter by 3
instead of 1.

Unfortunately the badge in the README can't filter out specific files[^1].

[^1]: https://shields.io/badges/git-hub-downloads-all-assets-latest-release
