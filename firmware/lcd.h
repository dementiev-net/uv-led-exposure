#ifndef LCD_H
#define LCD_H

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "config.h"
#include "fonts.h"
#include <OLED_I2C.h>

struct LCDData
{
  char txtTime[20];
  char txtHelp[20];
};

class LCD {
  private:
    OLED *display;
  public:
    bool isset;
    LCD();
    void init();
    void splashScreen();
    void updateScreen(LCDData* refdataScreen);
    void resultScreen(char text[20]);
};

#endif
