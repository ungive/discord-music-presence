# How to help with translations

[![](https://translate.codeberg.org/widget/music-presence/desktop-application/287x66-grey.png)](https://translate.codeberg.org/projects/music-presence/desktop-application)

## Table of Contents

* [Table of Contents](#table-of-contents)
* [Introduction](#introduction)
  * [Reporting a bad or incorrect translation](#reporting-a-bad-or-incorrect-translation)
  * [Checking if your language still needs translations](#checking-if-your-language-still-needs-translations)
  * [The translation process](#the-translation-process)
  * [Joining the project](#joining-the-project)
* [Translation guide](#translation-guide)
  * [Things to keep in mind](#things-to-keep-in-mind)
  * [Talk to other translators](#talk-to-other-translators)
* [What happens next to my translations?](#what-happens-next-to-my-translations)
* [Attribution of your work](#attribution-of-your-work)
  * [Ensuring your contributions appear on your GitHub profile](#ensuring-your-contributions-appear-on-your-github-profile)

Please read this document top to bottom before helping with translations.
It contains in-depth information on what to look out for and how it all works.

## Introduction

### Reporting a bad or incorrect translation

First and foremost, if you found that a translation sounds bad or is incorrect,
please open an issue here to bring it to my attention:
[**music-presence/translations**](https://github.com/music-presence/translations/issues)

### Checking if your language still needs translations

Please head over to the Weblate project [**here**](https://translate.codeberg.org/projects/music-presence/desktop-application/) and check whether your language is listed there
and how much it has been translated already.

If you can't find it or it's not at 100% already, there's still work to do!

You may also review existing translations if you like.

### The translation process

At the moment translations make their way into the app
when they meet one of the following requirements:

- The translation was made by a native speaker
or by someone who speaks the language fluently
- The translation was reviewed and approved by a native speaker
or by someone who speaks the language fluently

If you do not speak a language natively you may still help with translating,
but make sure there is someone around who can review your translations.

### Joining the project

To help with translations you need to join the Weblate project.
To do this please join our
[Discord community](https://discord-invite.musicpresence.app) first
and quickly introduce yourself in the `#translations` channel.

While you're at it, you can already provide the following information

- Your Codeberg account name. If you don't have one yet, register it
by opening the [Weblate project](https://translate.codeberg.org/projects/music-presence/desktop-application/)
and then clicking "Register" at the top.
Make sure you have logged into `translate.codeberg.org`
at the end of the registration process at least once,
otherwise I won't be able to add you to the project.
- Which languages you want to translate into
and which of those languages you speak natively/fluently.

Once you have reached out, I will come back to you as soon as I can!

## Translation guide

Please take note of all the points in this guide before translating.

### Things to keep in mind

- There's a translation text note in the top right of the translation box. Please always be aware of the context in which the text is used before translating it. Make sure it makes sense in that context. If in doubt, feel free to ask me or other translators where the string is used.
- Translations shouldn't be a lot longer than the original text, otherwise it might increase the width of the tray menu. When in doubt though, favour accuracy of the translation over limiting its length! Sometimes it's okay for it to be longer if the original text is already quite short.
- Whenever there's a mention of a "button" the text should be short and concise since buttons usually do not contain that much text
- `{}` or `{...}` with text between the braces is a placeholder and must be copied 1:1 in the translation. The text inbetween the braces and/or the translation note describes what each of these placeholders will contain, e.g. `{player_name}` will contain the name of a media player. An example of a translation might be `Settings for {player_name}` which is translated to `Einstellungen für {player_name}` for German. In the app it will then appear as `Einstellungen für Spotify` for the player "Spotify".
- Preserve HTML tags, e.g. `<b>Original text</b>` becomes `<b>Translated text</b>`. If you are not that familiar with HTML, you can find a helpful introduction [here](https://www.w3schools.com/html/html_intro.asp).
- As a rule of thumb, simply always copy the text to translate into the translation box, then replace the English text with text in your language and never modify `{...}` or HTML tags.

### Talk to other translators

Feel free to talk and exchange with other translators!
Check the pinned messages in the `#translations` channel on the Discord server
to easily find who translated which languages.

## What happens next to my translations?

Your translations are stored in the Weblate project
until they are pushed to the GitHub repository automatically
[here](https://github.com/music-presence/translations).
It may take a few hours for your changes to be pushed
as this is done in intervals.
You will get a notification in the `#translations` announcement channel
on the Discord server.

Before every release of Music Presence
I lock the Weblate project and review the translations in the GitHub repository,
after which they make their way into the next Music Presence release.

## Attribution of your work

Your work will be attributed in the following places:

- Translations are stored in this GitHub repository:
[**music-presence/translations**](https://github.com/music-presence/translations).
If you want your translations to be linked to your GitHub account
please follow the instructions below!
This might not be the case by default.
- The "About" window in the Music Presence app (Help > About)
mentions all translators and optionally links to their GitHub profile.
Please **comment on [this issue](https://github.com/music-presence/translations/issues/1)**
if you want your name to be visible in the About window.
- All translations are licensed under the MIT License,
see [**here**](https://github.com/music-presence/translations/blob/main/LICENSE).
Please keep that in mind when making a contribution.

### Ensuring your contributions appear on your GitHub profile

Please follow these steps
if you want commits in the translations repository on GitHub
to be properly linked to your GitHub account:

- Go to your [GitHub Email settings](https://github.com/settings/emails)
and copy one of the e-mails that are associated with your GitHub account.
Make sure it's a verified e-mail address.
This will be the e-mail address that is used to commit your translations
and **you must be comfortable with it being public**!
If you are using a private e-mail address for GitHub,
consider adding another address to your account that is less sensitive.
- Next go to https://codeberg.org/user/settings/account 
and add that e-mail address to your account,
then verify the e-mail address.
- As a final step,
go to https://translate.codeberg.org/accounts/profile/#account
and select that e-mail address as your "Commit e-mail".
This will be used in the automatic GitHub commit
that's created by Weblate when syncing translations to the repository.
You might have to log out and in again for it to show up.
- Commits should now properly link to your GitHub account.

Feel free to ping me if you want to test it out.
Make a single translation, then I'll push it to the repo
for you to check if everything's working.

You can check if your contributions are linked properly
by visiting the commit history: https://github.com/music-presence/translations/commits/main.
If your name is clickable and opens your GitHub profile,
everything's good!

---

If you have any more questions, feel free to reach out!
