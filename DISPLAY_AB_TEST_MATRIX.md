# SH8601 Display Transport A/B Matrix

Use these `build_flags` overrides in `platformio.ini` to isolate panel transport faults.

## Baseline
- `-DLCD_USE_QSPI=1`
- `-DLCD_COLOR_ORDER_BGR=0`
- `-DLCD_QSPI_PCLK_10MHZ=0`
- `-DLCD_LVGL_ASYNC_FLUSH=0`
- `-DLCD_QSPI_CMD_PACKING_ALT=0`
- `-DLCD_RUN_PANEL_SOLID_COLOR_TEST=1`
- `-DLCD_START_LV_DEMO_WIDGETS=1`

## Test Matrix
1. `RGB/BGR` only: set `LCD_COLOR_ORDER_BGR=1`
2. `PCLK` only: set `LCD_QSPI_PCLK_10MHZ=1`
3. `Flush mode` only: set `LCD_LVGL_ASYNC_FLUSH=1`
4. `QSPI cmd packing` only: set `LCD_QSPI_CMD_PACKING_ALT=1`
5. `SPI fallback` only: set `LCD_USE_QSPI=0`
6. If still corrupt: combine `10MHz + ASYNC + ALT packing`

## Expected Interpretation
- Solid fills are stable, but wrong colors: color-order mismatch (`RGB/BGR`)
- Solid fills flicker/tear/noise only at 20MHz: signal/timing issue (prefer 10MHz)
- Corruption disappears with async flush: flush-ready timing issue
- Corruption disappears with ALT packing: QSPI command framing mismatch
- Corruption disappears only in SPI fallback: QSPI bus-mode incompatibility
