#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#define EXAMPLE_LCD_H_RES              360
#define EXAMPLE_LCD_V_RES              360

#define LCD_BIT_PER_PIXEL              16

#define EXAMPLE_PIN_NUM_LCD_CS      14
#define EXAMPLE_PIN_NUM_LCD_PCLK    13
#define EXAMPLE_PIN_NUM_LCD_DATA0   15
#define EXAMPLE_PIN_NUM_LCD_DATA1   16
#define EXAMPLE_PIN_NUM_LCD_DATA2   17
#define EXAMPLE_PIN_NUM_LCD_DATA3   18
#define EXAMPLE_PIN_NUM_LCD_RST     21
#define EXAMPLE_PIN_NUM_LCD_DC      -1
#define EXAMPLE_PIN_NUM_BK_LIGHT    47

#define EXAMPLE_LVGL_BUF_HEIGHT        (EXAMPLE_LCD_V_RES / 10)
#define EXAMPLE_LVGL_TICK_PERIOD_MS    2                          //Timer time
#define EXAMPLE_LVGL_TASK_MAX_DELAY_MS 500                        //LVGL Indicates the maximum time for a task to run
#define EXAMPLE_LVGL_TASK_MIN_DELAY_MS 1                          //LVGL Minimum time to run a task
#define EXAMPLE_LVGL_TASK_STACK_SIZE   (4 * 1024)                 //LVGL runs the task stack
#define EXAMPLE_LVGL_TASK_PRIORITY     2                          //LVGL Running task priority

#define EXAMPLE_TOUCH_ADDR                0x15
#define EXAMPLE_PIN_NUM_TOUCH_SCL 12
#define EXAMPLE_PIN_NUM_TOUCH_SDA 11


//#define Backlight_Testing
//#define EXAMPLE_Rotate_90

// Display transport A/B toggles
#ifndef LCD_USE_QSPI
#define LCD_USE_QSPI                      1   // 1: QSPI, 0: SPI fallback on DATA0
#endif

#ifndef LCD_COLOR_ORDER_BGR
#define LCD_COLOR_ORDER_BGR               0   // 0: RGB, 1: BGR
#endif

#ifndef LCD_QSPI_PCLK_10MHZ
#define LCD_QSPI_PCLK_10MHZ               0   // 0: 20MHz, 1: 10MHz
#endif

#ifndef LCD_LVGL_ASYNC_FLUSH
#define LCD_LVGL_ASYNC_FLUSH              0   // 0: sync flush_ready, 1: callback flush_ready
#endif

#ifndef LCD_QSPI_CMD_PACKING_ALT
#define LCD_QSPI_CMD_PACKING_ALT          0   // 0: opcode<<24|cmd<<8, 1: opcode<<8|cmd
#endif

#ifndef LCD_RUN_PANEL_SOLID_COLOR_TEST
#define LCD_RUN_PANEL_SOLID_COLOR_TEST    1   // 1: run color bars before LVGL demo
#endif

#ifndef LCD_PANEL_TEST_COLOR_HOLD_MS
#define LCD_PANEL_TEST_COLOR_HOLD_MS      1000
#endif

#ifndef LCD_START_LV_DEMO_WIDGETS
#define LCD_START_LV_DEMO_WIDGETS         1   // 1: start lv_demo_widgets() after panel test
#endif
#endif
