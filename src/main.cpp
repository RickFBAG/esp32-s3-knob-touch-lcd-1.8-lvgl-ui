#include "lcd_bsp.h"
#include "cst816.h"
#include "lcd_bl_pwm_bsp.h"
#include "lcd_config.h"

void setup()
{
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  delay(100);

#if LCD_DEBUG_LOGS
  Serial.println("[DBG] setup: start");
#endif
  Touch_Init();
#if LCD_DEBUG_LOGS
  Serial.println("[DBG] setup: touch init done");
#endif
  lcd_bl_pwm_bsp_init(LCD_PWM_MODE_255);
#if LCD_DEBUG_LOGS
  Serial.println("[DBG] setup: backlight init done");
#endif
  lcd_lvgl_Init();
#if LCD_DEBUG_LOGS
  Serial.println("[DBG] setup: lcd_lvgl_Init returned");
#endif
}

void loop()
{
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
#else
  delay(10);
#endif
}
