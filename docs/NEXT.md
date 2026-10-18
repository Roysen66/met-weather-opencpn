# MET Weather for OpenCPN — Next Steps

Last updated: 2026-10-18

## Read this first

This document is the starting point when resuming development.

Read together with:
- docs/STATUS.md — verified progress and project status
- docs/opencpn-api.md — OpenCPN API investigation

Do not repeat completed investigations unless new evidence
makes it necessary.

## Current milestone: Secure the migrated project

The modified testplugin source has been copied from:

    ~/Utvikling/testplugin_pi

Into the dedicated project repository:

    ~/Utvikling/met-weather-opencpn

The original source directory must remain untouched until the
new project has been built and tested successfully.

The OpenCPN libraries are a Git submodule pinned to:

    6a5616930143528470442e376349ccc2be7800b4

## IMMEDIATE NEXT ACTION

Inspect the repository before committing:

    cd ~/Utvikling/met-weather-opencpn
    git status --short --untracked-files=normal

Check that:
- Source files are present.
- Documentation is present.
- The opencpn-libs submodule is registered.
- build/ and backup files are ignored.
- No unexpected generated files are staged.

Then stage, review and commit the migration.

Push to:

    https://github.com/Roysen66/met-weather-opencpn.git

Do not push to the original testplugin upstream repository.

## After the migration commit

1. Perform a clean build from the new repository.
2. Verify the plugin loads in OpenCPN 5.14.2 Flatpak.
3. Verify the toolbar button and dialog still work.
4. Record build commands and results in documentation.
5. Commit and push the verified build milestone.

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
