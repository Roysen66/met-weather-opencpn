# OpenCPN Plugin API – Technical Investigation

**Project:** MET Weather for OpenCPN  
**Status:** Investigation in progress  
**Target platforms:** Linux, Android, Windows  
**Initial OpenCPN reference:** 5.14.2 (Linux)

## 1. Purpose

This document tracks the investigation of OpenCPN's plugin API, with particular emphasis on chart display control.

The first technical priority is to determine whether MET Weather can safely switch between normal navigation and simplified weather analysis views.

No weather data processing or user interface implementation should begin until the essential chart display capabilities have been investigated.

## 2. Architecture Principles

- Maintain one shared codebase for Linux, Android and Windows.
- Use documented public OpenCPN plugin APIs wherever possible.
- Avoid modifying OpenCPN's internal code.
- Keep platform-specific code isolated.
- Minimize dependencies on OpenCPN internals.
- Preserve the user's existing chart settings.
- Never permanently hide navigation information when weather analysis mode is closed.

## 3. Chart Display API Candidates

The following API functions have been identified for further investigation.

| Function | Intended use |
|---|---|
| `EnableENCDepthSoundingsDisplay()` | Control depth sounding display |
| `EnableENCTextDisplay()` | Control ENC chart text |
| `EnableLightsDisplay()` | Control light display |
| `EnableBuoyLightLabelsDisplay()` | Control buoy and light labels |
| `EnableLightDescriptionsDisplay()` | Control light descriptions |
| `EnableAisTargetDisplay()` | Control AIS target display |
| `EnableTideStationsDisplay()` | Control tide station display |
| `EnableCurrentStationsDisplay()` | Control current station display |
| `SetENCDisplayCategory()` | Change ENC display category |

**Important:** The availability, exact signatures and behavior of these functions must be verified against the OpenCPN plugin API headers and implementation used by each target platform.

Corresponding getter functions must also be identified and verified before implementing automatic restoration.

## 4. Proposed Display Modes

### Navigation Mode

- Preserve the user's normal chart configuration.
- Display optional, unobtrusive weather symbols.
- Avoid covering essential chart information.
- Keep the normal navigation display available.

### Weather Analysis Mode

- Save the current chart display configuration.
- Simplify the chart using supported display controls.
- Enable optional weather color overlays.
- Display wind, current or wave direction and numerical values.
- Provide a clearly accessible exit control.
- Restore the original chart configuration when leaving the mode.

This design is provisional and depends on API capabilities.

## 5. Platform Verification

| Capability | Linux | Android | Windows |
|---|---|---|---|
| Plugin loading | Not tested | Not tested | Not tested |
| Read chart settings | Not tested | Not tested | Not tested |
| Change chart settings | Not tested | Not tested | Not tested |
| Restore chart settings | Not tested | Not tested | Not tested |
| Chart overlay rendering | Not tested | Not tested | Not tested |
| Touch-friendly controls | Not tested | Not tested | Not tested |
| Offline operation | Not tested | Not tested | Not tested |

Existing OpenCPN plugins provide implementation examples, but they do not replace testing of MET Weather on each platform.

## 6. First Prototype

The first prototype will be a minimal plugin with one control:

**Navigation / Weather Analysis**

The prototype should:

1. Read and save the current chart display settings.
2. Apply a simplified chart display configuration.
3. Allow switching back to navigation mode.
4. Restore the previous settings exactly.
5. Verify behavior after plugin shutdown and OpenCPN restart.
6. Check whether display settings can be controlled per chart canvas.

No MET Norway data retrieval is required for this prototype.

## 7. Safety Requirements

Weather analysis mode must never silently leave essential navigation information hidden.

Special attention is required for:

- Unexpected plugin termination.
- OpenCPN crashes or forced shutdown.
- Application restart.
- Manual chart setting changes while weather mode is active.
- Switching between chart canvases.
- Android application suspension and restoration.

If reliable restoration cannot be guaranteed, the design must be reconsidered.

## 8. Open Questions

- Are all required chart display functions exposed through the public plugin API?
- Which getter functions are available?
- Do the functions support individual chart canvases?
- Are these APIs available in the Android build?
- Do chart display changes persist after application restart?
- Can display settings be restored without affecting user changes?
- Can a plugin determine when the active chart canvas changes?
- Does the Android version impose additional limitations?

## 9. References

- [OpenCPN source code](https://github.com/OpenCPN/OpenCPN)
- [OpenCPN plugin API header](https://github.com/OpenCPN/OpenCPN/blob/master/include/ocpn_plugin.h)
- [OpenCPN plugin API documentation](https://opencpn-manuals.github.io/main/api-docs/)
- [OpenCPN GRIB plugin source](https://github.com/OpenCPN/OpenCPN/tree/master/plugins/grib_pi)

## 10. Investigation Log

### 2026-10-16 – Initial documentation

- Defined chart display control as the first technical milestone.
- Identified candidate plugin API functions.
- Established Linux, Android and Windows as target platforms.
- Established reliable restoration of navigation settings as a critical requirement.
- No prototype testing performed yet.

---

*This document will be updated as API behavior is verified through source inspection and practical testing.*
