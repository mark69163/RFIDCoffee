#include <Arduino.h>
//#include "wifi.h"
#include <WiFi.h>
#include "time.h"

/*
void beginNpt(const char *ssid, const char * pwd,const long gmt, int dayLightOffset, const char *ntp){
  //connect to WiFi
  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED);
  
  //init and get the time
  configTime(gmt, dayLightOffset, ntp);

  //disconnect WiFi as it's no longer needed
  //WiFi.disconnect(true);
  //WiFi.mode(WIFI_OFF);
}
*/
