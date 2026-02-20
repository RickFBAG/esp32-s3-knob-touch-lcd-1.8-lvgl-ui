#include "cst816.h"
#include "lcd_config.h"
#include <Arduino.h>
#include <Wire.h>

static uint8_t i2c_write_buff(uint8_t addr, uint8_t reg, const uint8_t *buf, uint8_t len)
{
  Wire.beginTransmission(addr);
  Wire.write(reg);
  for (uint8_t i = 0; i < len; i++) {
    Wire.write(buf[i]);
  }
  return (uint8_t)Wire.endTransmission();
}

static uint8_t i2c_read_buff(uint8_t addr, uint8_t reg, uint8_t *buf, uint8_t len)
{
  Wire.beginTransmission(addr);
  Wire.write(reg);
  uint8_t ret = (uint8_t)Wire.endTransmission(false);
  if (ret != 0) {
    return ret;
  }

  uint8_t got = (uint8_t)Wire.requestFrom((int)addr, (int)len);
  if (got != len) {
    return 1;
  }
  for (uint8_t i = 0; i < len; i++) {
    buf[i] = (uint8_t)Wire.read();
  }
  return 0;
}

void Touch_Init(void)
{
  Wire.begin(EXAMPLE_PIN_NUM_TOUCH_SDA, EXAMPLE_PIN_NUM_TOUCH_SCL, 300000U);

  uint8_t data = 0x00;
  i2c_write_buff(EXAMPLE_TOUCH_ADDR, 0x00, &data, 1); // Switch to normal mode
}

uint8_t getTouch(uint16_t *x, uint16_t *y)
{
  uint8_t GetNum = 0;
  uint8_t data[7] = {0};
  if (i2c_read_buff(EXAMPLE_TOUCH_ADDR, 0x00, data, 7) != 0) {
    return 0;
  }
  GetNum = data[2];
  if (GetNum) {
    *x = ((uint16_t)(data[3] & 0x0f) << 8) + (uint16_t)data[4];
    *y = ((uint16_t)(data[5] & 0x0f) << 8) + (uint16_t)data[6];
    return 1;
  }
  return 0;
}


