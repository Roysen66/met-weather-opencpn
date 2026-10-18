# MET Weather for OpenCPN — Project Status

Last updated: 2026-10-18

## Project

Repository: https://github.com/Roysen66/met-weather-opencpn

Goal: Develop a touch-friendly weather plugin for OpenCPN using
MET Norway weather data, with support for Linux, Windows and Android.

The plugin should provide a single toolbar button for switching
between navigation mode and weather mode.

## Development environment

- Development computer: Linux Mint (KontorPC)
- OpenCPN: 5.14.2, installed using Flatpak
- CMake: 3.28.3
- GCC: 13.3.0
- Git: 2.43.0
- Flatpak SDK: Freedesktop 25.08
- Plugin API configured in CMakeLists.txt: 1.21

## Completed and verified

- OpenCPN testplugin source obtained and modified.
- Plugin previously built as a Flatpak package.
- Plugin loaded in OpenCPN.
- Green TP toolbar button displayed.
- Toolbar button opens and closes the plugin control dialog.
- Existing modified source files copied into this repository.
- opencpn-libs registered as a Git submodule.
- opencpn-libs pinned to commit:
  6a5616930143528470442e376349ccc2be7800b4

The original working source remains available in:
~/Utvikling/testplugin_pi

## Investigated but not runtime-verified

- OpenCPN API 1.21 chart display controls.
- Saving and restoring chart display settings.
- Per-canvas display settings and viewport handling.
- Compatibility of all required API functions with
  OpenCPN 5.14.2 Flatpak.

See docs/opencpn-api.md for API investigation notes.

## Not yet implemented

- Navigation/weather mode switching.
- Automatic saving and restoring of chart settings.
- MET Norway weather data download.
- Automatic geographic area selection.
- Weather, current and wave layer selection.
- Weather overlays and legends.
- Offline caching.
- Touch-friendly interface.
- Windows and Android builds.

## Safety requirement

Weather mode must not silently disable essential navigation
information. In particular, AIS target visibility should be
preserved unless the user explicitly changes it.

## Current migration status

The source code has been copied from the original testplugin
directory into the MET Weather repository.

The dependency submodule has been pinned to the original version.

A clean build from this new repository has NOT yet been tested.
The migrated code has NOT yet been committed or pushed to GitHub.

## Next steps

1. Review Git status and verify ignored build files.
2. Commit the migrated source, dependency reference and documentation.
3. Push the milestone to GitHub.
4. Perform a clean build from this repository.
5. Verify plugin loading and toolbar operation in OpenCPN.
6. Begin implementing navigation/weather mode switching.

## Working rules

- Use this repository as the project source of truth.
- Document important findings and decisions.
- Distinguish API declarations from compiled and runtime-tested code.
- Commit and push at major milestones, including during a session.
- Preserve working code before making substantial changes.
- Prefer one verified development step at a time.
