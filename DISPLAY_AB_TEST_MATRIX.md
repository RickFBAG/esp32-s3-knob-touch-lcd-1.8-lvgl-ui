# SH8601 Display Transport A/B Matrix

This project now uses Arduino Core 3 (IDF5) as the stable baseline.

## Stable Baseline (current default)
- `LCD_USE_QSPI=1`
- `LCD_COLOR_ORDER_BGR=0`
- `LCD_QSPI_PCLK_40MHZ=1`
- `LCD_LVGL_ASYNC_FLUSH=1`
- `LCD_QSPI_CMD_PACKING_ALT=0`
- `LCD_QSPI_OCTAL_MODE=0`
- `LCD_QSPI_CMD_BITS_8=0`
- `LCD_DC_AS_CMD_PHASE=0`
- `LCD_USE_CUSTOM_INIT_CMDS=1`
- `LCD_EXPLICIT_DISP_ON=1`
- `LCD_RUN_PANEL_SOLID_COLOR_TEST=1`
- `LCD_START_LV_DEMO_WIDGETS=0`

## Presets in `platformio.ini`
- Stable: `env:esp32-s3-devkitc-1`
- Debug: `env:esp32-s3-devkitc-1-debug` (`LCD_DEBUG_LOGS=1`)

## How To Run A/B Tests
Change only one flag at a time in `build_flags`, then upload and observe:
1. Color order: `LCD_COLOR_ORDER_BGR=1`
2. PCLK: `LCD_QSPI_PCLK_40MHZ=0` plus `LCD_QSPI_PCLK_10MHZ=0` (20MHz), or `LCD_QSPI_PCLK_10MHZ=1` (10MHz)
3. Flush mode: `LCD_LVGL_ASYNC_FLUSH=0`
4. Command packing: `LCD_QSPI_CMD_PACKING_ALT=1`
5. Command width: `LCD_QSPI_CMD_BITS_8=1`
6. Explicit display command: `LCD_EXPLICIT_DISP_ON=0`
7. QSPI mode flag: `LCD_QSPI_OCTAL_MODE=1` (diagnostic only)
8. Init table bypass: `LCD_USE_CUSTOM_INIT_CMDS=0`

## Interpretation Hints
- Wrong colors with stable geometry: likely RGB/BGR mismatch.
- Noise/gibberish that changes with pclk/cmd packing: transport framing/timing issue.
- Black + backlight with clean boot: panel init or display-on sequencing issue.
- Crashes around touch init on Arduino3: check that `cst816.cpp` remains on `Wire` API.