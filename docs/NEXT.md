# MET Weather for OpenCPN — Next Steps

Last updated: 2026-10-18

## Read this first

This document is the starting point when resuming development.

Read together with:
- docs/STATUS.md — verified progress and project status
- docs/opencpn-api.md — OpenCPN API investigation

Do not repeat completed investigations unless new evidence
makes it necessary.

## Current milestone: Verify the migrated Flatpak package

The migrated source is committed and pushed to GitHub main.
Migration commit: ac6163e.

The Flatpak build and package creation succeeded from the new
repository. The packaging path bug in cmake/PluginPackage.cmake
has been corrected and the archive structure verified.

Package:

    build/testplugin_pi-1.0.363.0-x86_64_flatpak-25.08.tar.gz

The Flatpak builder currently fetches source from GitHub main.
Changes to plugin source must be pushed before relying on a
new flatpak-build result.

The original working source remains at:

    ~/Utvikling/testplugin_pi

## IMMEDIATE NEXT ACTION

Commit and push the verified packaging fix and documentation
to Roysen66/met-weather-opencpn, branch main.

Then test the newly built package in OpenCPN 5.14.2 Flatpak.

Verify:
- Plugin loads successfully.
- Toolbar button appears.
- Toolbar button opens and closes the control dialog.

Do not mark the new package runtime-verified until these tests
have actually succeeded.

## Next development milestone: Weather mode

Extend the existing toolbar button instead of creating a
separate plugin interface.

Desired behavior:

Navigation mode:
- Normal OpenCPN chart display.
- User's existing chart settings preserved.

Weather mode:
- Save relevant chart display settings.
- Apply a suitable weather-overlay display configuration.
- Keep essential navigation information visible.
- Prepare the chart for weather overlays.

Returning to navigation mode:
- Restore the saved settings.
- Avoid changing unrelated user preferences.

Important:
The existing toolbar button currently toggles the testplugin
dialog only. Weather mode is NOT implemented yet.

## Later development

- MET Norway data integration.
- Automatic selection of the visible geographic area.
- Weather, current and wave layer switching.
- Clear legends explaining displayed colors and values.
- Touch-friendly controls for tablets.
- Offline data caching.
- Linux, Windows and Android compatibility.

## Development discipline

- One terminal command or verification step at a time.
- Examine actual output before deciding the next action.
- Never assume a successful build or runtime test.
- Document decisions and test results.
- Commit and push at every important milestone.
- Preserve working versions before major modifications.
- Avoid destructive Git operations and unnecessary rewrites.

## How to resume after an interruption

1. Read docs/NEXT.md.
2. Read docs/STATUS.md if more context is needed.
3. Check git status.
4. Continue from the immediate next action.
5. Update these documents when the milestone changes.
