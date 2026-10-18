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

## Current migration and build status

- Migrated source committed and pushed to GitHub on main.
- Migration commit: ac6163e.
- Flatpak build from the new repository completed successfully.
- Build target: flatpak-build.
- Package target: flatpak-pkg.
- Flatpak SDK: 25.08, architecture: x86_64.
- Package: build/testplugin_pi-1.0.363.0-x86_64_flatpak-25.08.tar.gz.
- Corrected cmake/PluginPackage.cmake to package from build/app/files.
- Verified archive has one testplugin-flatpak-1.0.363.0/ root.
- Verified lib/opencpn/libtestplugin_pi.so and manifest.json.
- No unwanted files/ or local home/ paths in the archive.
- Temporary packaging symlink removed.
- Flatpak builder fetches source from GitHub main.
- The newly packaged plugin has NOT yet been runtime-tested in OpenCPN.

## Next steps

1. Commit and push the packaging correction and updated documentation.
2. Test the new Flatpak package in OpenCPN 5.14.2.
3. Verify plugin loading, toolbar button and dialog.
4. Document runtime results and commit the milestone.
5. Begin implementing navigation/weather mode switching.

## Working rules

- Use this repository as the project source of truth.
- Document important findings and decisions.
- Distinguish API declarations from compiled and runtime-tested code.
- Commit and push at major milestones, including during a session.
- Preserve working code before making substantial changes.
- Prefer one verified development step at a time.

## MET Weather 0.1.0 – egen pluginidentitet (18.10.2026)

- Endret visningsnavn til MET Weather og pakkenavn til metweather.
- Satt versjon til 0.1.0.
- Skilt datakatalog og konfigurasjon fra Testplugin.
- Oppdatert ikonsti og verktøylinjetekster.
- Opprettet tre SVG-ikoner: normal, deaktivert og aktiv.
- Oppdatert Cloudsmith-referansen til metweather.
- Endringene er foreløpig kun gjort i kildekoden.
- Bygging, pakking og kjøring i OpenCPN er IKKE verifisert.
- Eksisterende Testplugin skal beholdes som fungerende referanse.
