// ----------------------------------------------------------------------------
// LED засветка фоторезиста и паяльной маски
// версия 4.0 (Atmega328)
// (c) 2020 Дмитрий Дементьев <dementiev@me.com>
// ----------------------------------------------------------------------------

#include <EEPROM.h>
#include "config.h"
#include "button.h"
#include "lcd.h"

LCD lcd;
LCDData dataScreen;
BUTTON button1;
BUTTON button2;
BUTTON button3;

int Presets[] = {0, 0, 0};
unsigned long currentTime;   // текущее время
unsigned long loopTime;      // время окончания
unsigned long LimitTime = 0; // таймер
volatile boolean turn;
volatile boolean up;
int mode = 0; // флаг запуска отсчета

void setup()
{
  firstRun();
  Presets[0] = EEPROM.read(0); // берем пресеты из EEPROM
  Presets[1] = EEPROM.read(1);
  Presets[2] = EEPROM.read(2);
  for (int i = 0; i < 2; i++)
  {
    if (Presets[i] < 0 || Presets[i] > 86400) Presets[i] = 0;
  }
  pinMode(5, INPUT); // входы
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  digitalWrite(3, HIGH);
  pinMode(8, INPUT);
  digitalWrite(8, HIGH);
  pinMode(9, INPUT);
  digitalWrite(9, HIGH);
  pinMode(7, INPUT);
  digitalWrite(7, HIGH);
  pinMode(13, OUTPUT);
  attachInterrupt(0, isr, CHANGE); // прерывание энкодера
  currentTime = millis();
  lcd.init();
  lcd.splashScreen();
  delay(1000);
}

void loop()
{
  /**
   * режим отсчета
   */
  if (mode == 1)
  {
    digitalWrite(13, HIGH); // включаем
    tone(10, BUZ_TONE, BUZ_TIME1); // звук

    currentTime = millis();
    loopTime = currentTime + LimitTime * 1000;
    while (currentTime < loopTime)
    {
      int h = LimitTime / 60 / 60;
      int m = LimitTime / 60 % 60;
      int s = LimitTime % 60;

      sprintf(dataScreen.txtTime, "%02d.%02d.%02d", h, m, s);
      sprintf(dataScreen.txtHelp, "%s", "BLTN PFCDTNRF");

      LimitTime = (loopTime - currentTime) / 1000;
      currentTime = millis();

      lcd.updateScreen(&dataScreen);
    }

    digitalWrite(13, LOW); // отключаем
    tone(10, BUZ_TONE, BUZ_TIME2); // звук
    lcd.resultScreen("PFRJYXTYJ");
    delay(3000);
    mode = 0;

  /**
   * режим выбора времени
   */
  }
  else
  {
    digitalWrite(13, LOW); // отключаем

    if (LimitTime > 86400) LimitTime = 0;
    int h = LimitTime / 60 / 60;
    int m = LimitTime / 60 % 60;
    int s = LimitTime % 60;

    sprintf(dataScreen.txtTime, "%02d.%02d.%02d", h, m, s);
    if (h == 0 && m == 0 && s == 0) sprintf(dataScreen.txtHelp, "%s", "Ecnfyjdbnt dhtvz");
    else                            sprintf(dataScreen.txtHelp, "%s", "Yf;vbnt CNFHN");

    buttonPress(1, button1.checkButton(8));
    buttonPress(2, button2.checkButton(9));
    buttonPress(3, button3.checkButton(7));

    if (turn)
    {
      // Энкодеры бывают разных типов. Если при вращении вправо время уменьшается
      // то здесь нужно поправить += на -= и наоборот
      if (up) LimitTime += SEC_STEP; else LimitTime -= SEC_STEP;
      turn = false;
      if (LimitTime < 0) LimitTime = 0;
    }
    // кнопка энкодера
    if (digitalRead(3) == LOW) mode = true;

    lcd.updateScreen(&dataScreen);
    delay(250);
  }
}

// прерывание энкодера
void isr()
{
  up = (digitalRead(5) == digitalRead(2));
  turn = true;
}

// кнопки пресетов
void buttonPress(int btnNumm, int clkType)
{
  int i = btnNumm - 1;

  // нажатие на кнопку
  if (clkType == 1)
  {
    char stroka[20];
    sprintf(stroka, "Ds,hfkb #%d", btnNumm);
    LimitTime = Presets[i];
    lcd.resultScreen(stroka);
    delay(1000);
  }
  // долгое нажатие. сохранили
  if (clkType == 3)
  {
    EEPROM.update(i, LimitTime);
    Presets[i] = LimitTime;
    lcd.resultScreen("Cj[hfytyj!");
    delay(1000);
  }
}

// первый запуск
bool firstRun()
{
  for (uint16_t i; i < sizeof(Presets); i++)
  {
    if (EEPROM.read(i) != 255) return false;
  }
  for (int i = 0; i < 5; i++)
  {
    EEPROM.update(i, 0);
  }
}
