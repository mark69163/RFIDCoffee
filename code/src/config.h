#pragma once

#include "Arduino.h"

//real-time clock congfig

//for gmt +2
#define GMT2  7200

//wi-fi config
#define SSID    "Mark-wifi-2.4G"
#define PWD     "MilkaCsoki22"
#define SERVER  "http://192.168.50.36//esp-post.php"
#define APIKEY  "tPmAT5Ab3j7F9"

//lcd config
#define lcdAddress  0x27
#define COLLS       16
#define ROWS        2

//#define date {"16","06","2024"}
//#define time {"08","56"}

String operationDate = "16/06/2024";
String operationTime  = "08:56";

/*

Select MCU - either ESP32, otherwise ESP8266

*/

#define ESP32
#ifdef ESP32

//i2c config
#define SDA 4
#define SCL 5

//motor config
#define motPwmPin1  16   
#define motPwmPin2  17   
#define motEncPin1  18
#define motEncPin2  8

//neopixel config
#define neopixelPin 15  
#define numOfPixels 8   

//nfc congig - interrupt pin
#define nfcIrqPin   6  
#define nfcReset    7
#define nfcAddress  0x24

//color config
#define selPin1     10
#define selPin2     11
#define colorInPin  12

/*

ESP8266 here

*/

#else
//motor config
#define motPwmPin1  14   //D5
#define motPwmPin2  12   //D6
#define motEncPin1  A0   //ADC0

//neopixel config
#define neopixelPin 13  //D7
#define numOfPixels 8   

//nfc congig - interrupt pin
#define nfcIrqPin   15  //D8
#define nfcAddress  0x24

//color config
#define selPin1     0   //D3
#define selPin2     14  //D4
#define colorInPin  16  //D0

#endif 