#include "lcd_bsp.h"
#include "cst816.h"
#include "lcd_bl_pwm_bsp.h"
#include "lcd_config.h"
#include <stdio.h>

#define DBG_BOTH(fmt, ...)                        \
  do {                                            \
    Serial.printf(fmt, ##__VA_ARGS__);            \
    Serial.flush();                               \
    printf(fmt, ##__VA_ARGS__);                   \
    fflush(stdout);                               \
  } while (0)

void setup()
{
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  setvbuf(stdout, NULL, _IONBF, 0);

  // Keep startup deterministic and always emit markers even if CDC attach is late.
  delay(100);

  for (int i = 0; i < 20; i++) {
    DBG_BOTH("[DBG] boot banner %d/20, millis=%lu\r\n", i + 1, (unsigned long)millis());
    delay(200);
  }

  DBG_BOTH("[DBG] setup: start\r\n");
  Touch_Init();
  DBG_BOTH("[DBG] setup: touch init done\r\n");
  lcd_bl_pwm_bsp_init(LCD_PWM_MODE_255);
  DBG_BOTH("[DBG] setup: backlight init done\r\n");
  lcd_lvgl_Init();
  DBG_BOTH("[DBG] setup: lcd_lvgl_Init returned\r\n");
}
void loop()
{
  static uint32_t last_heartbeat = 0;
  if (millis() - last_heartbeat > 1000) {
    last_heartbeat = millis();
    DBG_BOTH("[DBG] heartbeat millis=%lu\r\n", (unsigned long)last_heartbeat);
  }
#ifdef Backlight_Testing
  setUpdutySubdivide(LCD_PWM_MODE_255);
  delay(1000);
  setUpdutySubdivide(LCD_PWM_MODE_200);
  delay(1000);
  setUpdutySubdivide(LCD_PWM_MODE_150);
  delay(1000);
  setUpdutySubdivide(LCD_PWM_MODE_100);
  delay(1000);
  setUpdutySubdivide(LCD_PWM_MODE_50);
  delay(1000);
  setUpdutySubdivide(LCD_PWM_MODE_0);
  delay(1000);
#endif
}
