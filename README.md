# MET Weather for OpenCPN

**A lightweight, touch-friendly MET Norway weather plugin for OpenCPN.**

MET Weather is an open-source project aiming to make marine weather forecasts easier and faster to access directly within OpenCPN.

The project was inspired by real-world sailing experience along the Norwegian coast, where the existing GRIB plugin proved difficult to operate on a small Android touchscreen.

The goal is not to replace OpenCPN's powerful GRIB plugin, but to provide a simpler alternative focused on MET Norway forecast data.

## Project Goals

- Simple, touch-friendly interface with minimal user interaction.
- Automatic selection of forecast regions based on the visible chart area.
- Automatic downloading and caching of available forecasts.
- Three primary data modes: **Weather**, **Current**, and **Waves**.
- Instant switching between available forecast types.
- Clear visualization of wind, ocean currents, and waves.
- Optional color overlays with understandable legends and units.
- Simple timeline navigation through forecast periods.
- Offline access to previously downloaded forecasts.
- Minimal interference with nautical chart information.

## Supported Platforms

The project is intended to support:

- **Linux** — primary development platform.
- **Android** — priority platform for touchscreen usability.
- **Windows** — planned support through a shared codebase.

Platform compatibility, especially Android plugin API support, must be verified during development.

## Technical Approach

MET Weather is planned as a C++ plugin using OpenCPN's plugin API and wxWidgets where appropriate.

The architecture will separate:

1. **Core:** MET Norway data access, GRIB processing, caching, forecast management and geographic region selection.
2. **OpenCPN Integration:** Chart overlays, coordinate handling and chart display settings.
3. **User Interface:** Compact, touch-friendly controls with platform-specific adjustments where necessary.

The project will investigate reusing suitable components from OpenCPN's existing GRIB plugin to minimize duplicated code and long-term maintenance.

## Chart Display Modes

Two display modes are being investigated:

**Navigation Mode**

Displays weather symbols and relevant numerical values over the normal nautical chart, with minimal visual interference.

**Weather Analysis Mode**

Provides a simplified chart presentation suitable for weather color overlays, directional symbols and forecast analysis.

The project will investigate OpenCPN's chart display API to determine whether chart settings can be safely changed and restored on Linux, Android and Windows.

Restoring the original navigation display reliably is a key requirement.

## Development Status

**Status: Planning and technical investigation.**

The first development milestone is a minimal OpenCPN test plugin capable of reading, modifying and restoring selected chart display settings.

This functionality must be verified before implementing weather data retrieval and visualization.

No functional release is available yet.

## License

MET Weather is intended to be distributed under the **GNU General Public License version 3.0 (GPL-3.0)**.

Any reused OpenCPN GRIB plugin code will be reviewed for license compatibility and proper attribution before inclusion.

## Acknowledgements

This project builds upon the work of the OpenCPN community and the marine forecast services provided by the Norwegian Meteorological Institute (MET Norway).

- [OpenCPN](https://opencpn.org/)
- [OpenCPN source code](https://github.com/OpenCPN/OpenCPN)
- [MET Norway](https://www.met.no/)
- [MET Norway APIs](https://api.met.no/)

---

*Marine weather information should be accessible when it is needed — without navigating through a maze of menus.*
