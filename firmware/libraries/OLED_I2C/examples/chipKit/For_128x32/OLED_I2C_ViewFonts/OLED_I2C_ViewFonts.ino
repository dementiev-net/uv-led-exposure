// OLED_I2C_ViewFonts
// Copyright (C)2018 Rinky-Dink Electronics, Henning Karlsen. All right reserved
// web: http://www.RinkyDinkElectronics.com/
//
// **********************************************
// *** This demo is for 128x32 pixel displays ***
// **********************************************
//
// A quick demo of how to use my OLED_I2C library.
//
// To use the hardware I2C (TWI) interface of the chipKit you must connect
// the pins as follows:
//
// chipKit Uno32/uC32:
// ----------------------
// Display:  SDA pin   -> Analog 4
//           SCL pin   -> Analog 5
// *** Please note that JP6 and JP8 must be in the I2C position (closest to the analog pins)
//
// chipKit Max32:
// ----------------------
// Display:  SDA pin   -> Digital 20 (the pin labeled SDA)
//           SCL pin   -> Digital 21 (the pin labeled SCL)
//
// The chipKit boards does not have pull-up resistors on the hardware I2C interface
// so external pull-up resistors on the data and clock signals are required.
//
// You can connect the OLED display to any available pin but if you use any
// other than what is described above the library will fall back to
// a software-based, TWI-like protocol which will require exclusive access 
// to the pins used.
//

#include <OLED_I2C.h>

OLED  myOLED(SDA, SCL); // Remember to add the RESET pin if your display requires it...

extern uint8_t SmallFont[];
extern uint8_t TinyFont[];

void setup()
{
  if(!myOLED.begin(SSD1306_128X32))
    while(1);   // In case the library failed to allocate enough RAM for the display buffer...
}

void loop()
{
  myOLED.setFont(SmallFont);
  myOLED.clrScr();
  myOLED.print("Upper case:", LEFT, 0);
  myOLED.print("SmallFont", RIGHT, 0);
  myOLED.print("ABCDEFGHIJKLM", CENTER, 16);
  myOLED.print("NOPQRSTUVWXYZ", CENTER, 24);
  myOLED.update();
  delay (5000);
  
  myOLED.clrScr();
  myOLED.print("Lower case:", LEFT, 0);
  myOLED.print("SmallFont", RIGHT, 0);
  myOLED.print("abcdefghijklm", CENTER, 16);
  myOLED.print("nopqrstuvwxyz", CENTER, 24);
  myOLED.update();
  delay (5000);
  
  myOLED.clrScr();
  myOLED.print("Numbers:", LEFT, 0);
  myOLED.print("SmallFont", RIGHT, 0);
  myOLED.print("0123456789", CENTER, 16);
  myOLED.update();
  delay (5000);
  
  myOLED.clrScr();
  myOLED.print("Special:", LEFT, 0);
  myOLED.print("SmallFont", RIGHT, 0);
  myOLED.print("!\"#$%&'()*+,-./:", CENTER, 16);
  myOLED.print(";<=>?@[\\]^_`{|}~", CENTER, 24);
  myOLED.update();
  delay (5000);

  myOLED.setFont(SmallFont);
  myOLED.clrScr();
  myOLED.print("Upper case:", LEFT, 0);
  myOLED.print("TinyFont", RIGHT, 0);
  myOLED.setFont(TinyFont);
  myOLED.print("ABCDEFGHIJKLM", CENTER, 16);
  myOLED.print("NOPQRSTUVWXYZ", CENTER, 22);
  myOLED.update();
  delay (5000);
  
  myOLED.setFont(SmallFont);
  myOLED.clrScr();
  myOLED.print("Lower case:", LEFT, 0);
  myOLED.print("TinyFont", RIGHT, 0);
  myOLED.setFont(TinyFont);
  myOLED.print("abcdefghijklm", CENTER, 16);
  myOLED.print("nopqrstuvwxyz", CENTER, 22);
  myOLED.update();
  delay (5000);
  
  myOLED.setFont(SmallFont);
  myOLED.clrScr();
  myOLED.print("Numbers:", LEFT, 0);
  myOLED.print("TinyFont", RIGHT, 0);
  myOLED.setFont(TinyFont);
  myOLED.print("0123456789", CENTER, 16);
  myOLED.update();
  delay (5000);
  
  myOLED.setFont(SmallFont);
  myOLED.clrScr();
  myOLED.print("Special:", LEFT, 0);
  myOLED.print("TinyFont", RIGHT, 0);
  myOLED.setFont(TinyFont);
  myOLED.print("!\"#$%&'()*+,-./:", CENTER, 16);
  myOLED.print(";<=>?@[\\]^_`{|}~", CENTER, 22);
  myOLED.update();
  delay (5000);
}


