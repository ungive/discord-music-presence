# Scripts

## Update the latest release changelog

```sh
$ ./scripts/update-latest-changelog
```

Updates the release changelog of the latest tag on GitHub
by generating the changelog from the release notes
for the latest tag in `CHANGELOG.md` and uploading the text to GitHub,
given that a release for it exists in the repository.

Requirements:

- Must have `gh` (GitHub CLI) installed and on PATH and be logged in
- There must be an existing release in the GitHub repository (may be a draft)
- You should have created a tag in the format of `vX.Y.Z`
- There should be release notes for version `X.Y.Z` in `CHANGELOG.md`
  with a heading in the same format

## Generate release changelog

```sh
$ ./scripts/generate-release-changelog X.Y.Z
```

Generates a changelog from `CHANGELOG.md` for the given version

Requirements:

- There should be release notes for version `X.Y.Z` in `CHANGELOG.md`
  with a heading in the same format

Features:

- Extracts the changelog text of the section with the title "X.Y.Z"
- Adapts the changelog's bullet points to be properly formatted
  for GitHub release notes: Line breaks in bullet points are removed,
  as they are translated to literal line breaks, which are not intended
- Inserts the changelog text into the template `scripts/release-changelog.template.md`
- Outputs the generated changelog to `scripts/out/changelog.md`
