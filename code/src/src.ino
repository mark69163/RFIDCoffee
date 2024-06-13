#include <Arduino.h>
#include "config.h"
#include "motor.h"
#include "neopixel.h"
#include "lcd.h"

//Motor motor(motPwmPin1,motPwmPin2,motEncPin1);
Neopixel ledRing(numOfPixels,neopixelPin);
LCD lcd(lcdAddress,COLLS,ROWS,SDA,SCL);

void setup(){


//rewrite motor

}

void loop(){

ledRing.dispTransactionProcessing(0,0,127);
  lcd.off();

}