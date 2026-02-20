#include "lcd_bsp.h"
#include "cst816.h"
#include "lcd_bl_pwm_bsp.h"
#include "lcd_config.h"
void setup()
{
  Serial.begin(115200);
  Serial.setDebugOutput(true);

  // Give USB CDC enough time and emit repeated markers so monitor can catch them.
  uint32_t start_ms = millis();
  while (!Serial && (millis() - start_ms) < 8000) {
    delay(10);
  }

  for (int i = 0; i < 20; i++) {
    Serial.printf("[DBG] boot banner %d/20, millis=%lu\r\n", i + 1, (unsigned long)millis());
    Serial.flush();
    delay(200);
  }

  Serial.println("[DBG] setup: start");
  Touch_Init();
  Serial.println("[DBG] setup: touch init done");
  lcd_bl_pwm_bsp_init(LCD_PWM_MODE_255);
  Serial.println("[DBG] setup: backlight init done");
  lcd_lvgl_Init();
  Serial.println("[DBG] setup: lcd_lvgl_Init returned");
}
void loop()
{
  static uint32_t last_heartbeat = 0;
  if (millis() - last_heartbeat > 1000) {
    last_heartbeat = millis();
    Serial.printf("[DBG] heartbeat millis=%lu\r\n", (unsigned long)last_heartbeat);
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
