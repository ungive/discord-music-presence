# Automatic updates

> This is a preview document and might be updated
> before version 2.2.0 is released.

> At the moment this feature is only available for Windows users.

Starting with version 2.2.0, Music Presence ships with the option
to install updates directly within the application,
either automatically in the background or manually with a single click.
Visiting the download page is not required anymore.

This document aims to give insight into how it works and the security of it.

## Summary

- The source code for the updater component is open-source:
  [https://github.com/ungive/libupdate](https://github.com/ungive/libupdate)
- The following guarantees are made about automatically downloaded updates:
  - The download was not tampered with during transmission (integrity)
  - The update was created by the project author and no other party
    (authenticity): [https://github.com/ungive](https://github.com/ungive)
  - The downloaded version is always a newer version,
    i.e. the application will not downgrade itself
  - At the moment, updates are only released on and downloaded from GitHub
- A number of security measures are employed to verify downloaded updates
  - The integrity is verified with SHA256 checksums: `sha256sum.txt`
  - The authenticity is verified with a cryptographic Ed25519 signature:
    `sha256sum.txt.sig`
- The cryptographic keys used to verify the release can be found here:
  - [https://github.com/ungive/keys](https://github.com/ungive/keys)
  - [https://vandenbe.com/keys](https://vandenbe.com/keys)
- You can verify releases yourself using the instructions below

## How it works

At the moment releases are published solely on GitHub.[^1]
The application contacts the GitHub API[^2][^3] on application startup
and at an interval of 12 hours while it is running
to retrieve information about the latest available version.
When the following conditions are met,
the release that is reported by the GitHub API is considered for updating:

- The version number in the `tag_name` field
  is newer than the currently installed version
- The release contains an appropriate update file
  for the user's operating system
- The update file's filename
  contains the same version number as the `tag_name` field.
  This check is made to verify that only newer versions are installed,
  since the checksum file (`sha256sum.txt`) contains the exact release filename
  and that file is authenticated
  with a cryptographic signature (`sha256sum.txt.sig`),

Then the following files are downloaded:

- On Windows (x86_64): The file whose name contains
  `win64` and ends with `.zip`
- On Mac (x86_64, Intel): The file whose name contains
  `mac`, `x64` and ends with `.dmg`
- On Mac (arm64, Apple Silicon): The file whose name contains
  `mac`, `arm64` and ends with `.dmg`
- `sha256sum.txt` is always downloaded.
  It contains SHA256 checksums of all release files,
  which is used to verify the integrity[^4] of the download.
- `sha256sum.txt.sig` is always downloaded.
  It contains a cryptographic signature of the contents of `sha256sum.txt`,
  which is used to verify the authenticity[^5] of the download.

After that the cryptographic signature is verified
and the checksum is computed and compared as described in the next section.
If everything is valid, the download is ready for installation
and is installed automatically if automatic updates are enabled.

Note that the last two files above (checksums and signature)
are NOT downloaded from the GitHub release itself,
but from the following URLs (at the example of version 2.1.3):

- https://pages.musicpresence.app/releases/2.1.3/sha256sum.txt
- https://pages.musicpresence.app/releases/2.1.3/sha256sum.txt.sig

These files are hosted
[on GitHub as well](https://github.com/ungive/discord-music-presence/tree/master/docs/releases)
and have the same content as the files attached to the release.
The reason for not downloading the from the release
is to not artifically inflate the GitHub download counter.
Otherwise one in-app or automatic update
would cause the download counter to increase by 3 instead of 1.

[^1]: Music Presence releases:
https://github.com/ungive/discord-music-presence/releases
[^2]: GitHub API documentation: https://docs.github.com/en/rest
[^3]: Example GitHub API request
to retrieve information about the latest version:
https://api.github.com/repos/ungive/discord-music-presence/releases/latest
[^4]: By verifying the integrity of a file,
it is ensured that it has not been modified by a third party,
see https://en.wikipedia.org/wiki/Data_integrity
[^5]: By verifying the authenticity of a file,
it is ensured that it originates from the correct source
(in this case the project author and nobody else),
see https://en.wikipedia.org/wiki/Authentication

## Verifying releases

Follow these instructions to verify the integrity and authenticity
of a release.

Music Presence performs these steps automatically for each downloaded release
and rejects and deletes any update files
which do not have a valid checksum and signature.

### Requirements

- OpenSSL:
  [https://openssl-library.org/source](https://openssl-library.org/source)  
  The `openssl` command must be available to the terminal/command line

### Windows

Download the release file you wish to verify,
`sha256sum.txt` and `sha256sum.txt.sig` from the
[release page](https://github.com/ungive/discord-music-presence/releases).

Also download the public key that was used to sign the release
from any of the following sources:

> It is recommended to download the key from the **non-GitHub link**,
as the release has already been downloaded from GitHub
and it is good practice to not put all your trust into one party.

- https://vandenbe.com/keys
- https://github.com/ungive/keys

The key's filename should be `ed25519_ungive.key`.

#### Step 1: Verifying the checksum

Make sure your browser did not rename any of the downloaded files,
e.g. by adding `(1)` to the name.

Then compute the checksum with the following command:

```
certutil -hashfile .\music-presence-2.1.3-win64.exe SHA256
```

Look at the contents of `sha256sum.txt`
and verify that the checksums/hashes are identical:

```
type sha256sum.txt
```

Example output:

```
C:\> certutil -hashfile .\music-presence-2.1.3-win64.exe SHA256
SHA256 hash of .\music-presence-2.1.3-win64.exe:
08d686713fabe2208593483802752ed0c44fb5f86513fb077da2131a74b21ccc
CertUtil: -hashfile command completed successfully.

C:\> type sha256sum.txt
69a7f9658fb9bf697cddec0fc10c8524c3788ef7d8cab25fb8ad09ab0bb396df *music-presence-2.1.3-mac-arm64.dmg
bea276349c2fa7a75c7f1c33019970b9aadcabad13a5e8d759632ee15cf49b30 *music-presence-2.1.3-mac-x64.dmg
08d686713fabe2208593483802752ed0c44fb5f86513fb077da2131a74b21ccc *music-presence-2.1.3-win64.exe
00e1e00e4583fc91d29efb7fd9c6aeede252d4348843b2315fb28f6b92bd5ba1 *music-presence-2.1.3-win64.zip
```

Both outputs contain
`08d686713fabe2208593483802752ed0c44fb5f86513fb077da2131a74b21ccc`,
the file hash/checksum is identical.

#### Step 2: Verifying the cryptographic signature

To verify the signature `sha256sum.txt.sig` execute the following command:

```
openssl pkeyutl -verify -pubin -inkey ed25519_ungive.key -rawin -in sha256sum.txt -sigfile sha256sum.txt.sig
```

The signature is **valid** with the following output:

```
Signature Verified Successfully
```

The release file is **corrupted** if the output states the following:

```
Signature Verification Failure
```

You can either attempt these steps again with a fresh download
or report this error, if you are sure you followed all steps correctly.

## Source code

The logic for automatic updates
has been decoupled from the Music Presence application
and is available as an open-source C++ library.
It is licensed under the MIT license:

- https://github.com/ungive/libupdate
- https://github.com/ungive/libupdate/blob/master/LICENSE.txt
- https://github.com/ungive/libupdate/blob/master/SECURITY.md

The statements that are made in this document
can be verified by reading the source code.

## Security

If you encounter any security issues, please report them as documented
[here](https://github.com/ungive/libupdate/blob/master/SECURITY.md).

---

Last updated: 27.08.2024
