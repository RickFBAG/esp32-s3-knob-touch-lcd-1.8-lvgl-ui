#include "lcd_bsp.h"
#include "cst816.h"
#include "lcd_bl_pwm_bsp.h"
#include "lcd_config.h"
void setup()
{
  Serial.begin(115200);
  delay(300);
  Serial.println("[DBG] setup: start");
  Touch_Init();
  Serial.println("[DBG] setup: touch init done");
  lcd_lvgl_Init();
  Serial.println("[DBG] setup: lcd_lvgl_Init returned");
  lcd_bl_pwm_bsp_init(LCD_PWM_MODE_255);
  Serial.println("[DBG] setup: backlight init done");
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
#endif
}
