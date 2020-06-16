#include "lcd.h"

LCD::LCD()
{
  isset = true;
  display = new OLED(A4, A5);
}

void LCD::init()
{
  if (!isset)
  {
    return;
  }
  display->begin(SSD1306_128X64);
  display->setFont(SmallFont);
  display->update();
}

void LCD::splashScreen()
{
  display->clrScr();
  display->drawBitmap(0, 0, LogoBmp, 128, 64);
  display->update();
}

void LCD::updateScreen(LCDData *refdataScreen)
{
  display->clrScr();
  display->drawLine(0, 5, 128, 5);
  display->drawLine(0, 40, 128, 40);
  display->setFont(TimerNumbers);
  display->print(refdataScreen->txtTime, CENTER, 10);
  display->setFont(RusFont);
  display->print(refdataScreen->txtHelp, CENTER, 52);
  display->update();
}

void LCD::resultScreen(char text[20])
{
  display->clrScr();
  display->setFont(RusFont);
  display->print(text, CENTER, 32);
  display->update();
}
