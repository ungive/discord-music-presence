# Development

## Requirements

- You need an installation of the Qt6 SDK.
Preferrably one that was compiled with the same toolchain/compiler that you are using to develop locally.
For instance, for Visual Studio, install the MSVC version via the official Qt installer from https://qt.io.

## Windows

### Visual Studio Community 2022

1. Create a new project by cloning the project from source control.
2. Open the project. Visual Studio should [automatically](https://learn.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170#ide-integration)
run CMake once you import a project with a `CMakeLists.txt` in the root of the project.
If it doesn't, close the project and reimport the directory.
3. Edit the `CMakeSettings.json` (right-click `CMakeLists.txt`, click "CMake Settings",
then click "Edit JSON" in the top-right corner) to add an environment variable,
so CMake can find the Qt6 SDK (if such an environment variable doesn't exist already),
by adding the "variables" key to each of your configurations
(with the appropriate Qt6 installation directory):
```json
"variables": [
  {
    "name": "CMAKE_PREFIX_PATH",
    "value": "C:\\tools\\Qt\\6.6.2\\msvc2019_64",
    "type": "STRING"
  }
],
```

### Command Line

*TODO*

## Mac OS

*TODO*

## Linux

*TODO*

## Troubleshooting

### External symbols not resolved (Qt6)

I've had this error a few times (on Windows only so far).
It only happened with MinGW builds of Qt6,
so try installing Qt6 through the official installer for your build platform (MinGW, MSVC, etc.).
Extending the PATH variable, to include the `bin` directory,
e.g. with `"environments": [ { "PATH": "C:\\Qt\\6.2.4\\mingw_64\\bin;${env.PATH}" } ]`
in `CMakeSettings.json` sometimes caused MSVC to not be used as the compiler anymore
(see my Stackoverflow issue [here](https://stackoverflow.com/q/78189175/6748004)).
