#include <Arduino.h>
#include "config.h"
#include "motor.h"
#include "neopixel.h"
#include "lcd.h"
#include "nfc.h"
#include <ESP32Time.h>

Motor motor(motPwmPin1,motPwmPin2,motEncPin1,motEncPin2);
Neopixel ledRing(numOfPixels,neopixelPin);
LCD lcd(lcdAddress,COLLS,ROWS,SDA,SCL);
Nfc nfc(nfcIrqPin,nfcReset);

ESP32Time rtc(0);


void setup(){

  //get real current time with ntp connection on startup, continue with rtc
  rtc.setTime(1, 59, 9, 16, 6, 2024);  // 16th Jun 2024 09:24:00
  //rtc.offset = GMT2;
  
  motor.begin();
  lcd.off();
  ledRing.dispOff();
  nfc.begin(SDA, SCL);

  lcd.printStandby();

}

void loop(){
  refreshTime();
  lcd.printTimestamp(operationDate, operationTime);
}

void refreshTime(){

  if(rtc.getDay() < 10){
    operationDate="0";
    operationDate+=String(rtc.getDay());
    }
  else operationDate=String(rtc.getDay());

  operationDate+= "/";
  if(rtc.getMonth()<10)operationDate+="0";
  operationDate+=String(rtc.getMonth());
  operationDate+="/";
  operationDate+=String(rtc.getYear());

  if(rtc.getHour()<10){
    operationTime="0";
    operationTime+=String(rtc.getHour(true));
  }
  else  operationTime=String(rtc.getHour(true));
  operationTime+=":";
  if(rtc.getMinute()<10)operationTime+="0";
  operationTime+=String(rtc.getMinute());
}
