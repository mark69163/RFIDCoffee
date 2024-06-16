#include <Arduino.h>
#include "config.h"

#include <WiFi.h>
#include "time.h"

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

  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED);
  
  //init and get the time
  configTime(GMT2, 0, NTPSERVER);

  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    return;
  }

  //disconnect WiFi as it's no longer needed
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);


  

  //get real current time with ntp connection on startup, continue with rtc
  rtc.setTime((int)timeinfo.tm_sec, (int)timeinfo.tm_min, (int)timeinfo.tm_hour, 
  (int)timeinfo.tm_mday,(int) timeinfo.tm_mon + 2, (int)timeinfo.tm_year + 1900);  // 16th Jun 2024 09:24:00
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

  operationDate = (rtc.getDay() < 10 ? "0" : "") + String(rtc.getDay()) + "/" +
                  (rtc.getMonth() < 10 ? "0" : "") + String(rtc.getMonth()) + "/" +
                  String(rtc.getYear());

  operationTime = (rtc.getHour(true) < 10 ? "0" : "") + String(rtc.getHour(true)) + ":" +
                  (rtc.getMinute() < 10 ? "0" : "") + String(rtc.getMinute());

}
