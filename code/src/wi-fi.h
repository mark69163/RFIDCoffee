#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include "time.h"

void beginNpt(const char *ssid, const char * pwd,const long gmt, int dayLightOffset, const char *ntp);
int GetHourNpt();
int getMinuteNpt();
int getYearNpt();
int getMonthNpt();
int getDayNpt();


/*
class wifi{
  public:
    wifi();
    void begin(const char* ssid, const char* pwd);
    void configTime(const long gmt, int dayLightOffset, const char* ntp);
    int getHour();
    int getMinute();
    int getYear();
    int getMonth();
    int getDay();
};
*/