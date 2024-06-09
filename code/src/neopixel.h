#pragma once
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>


class Neopixel{ 
  private:
    Adafruit_NeoPixel pixels;
    int _numOfPixels;
    int _neopixel_pin;
  public:
    Neopixel(int numOfPixel,int pin);
    void dispTransactionLoading();
    void dispTransactionProcessing();
    void dispTransactionSuccess();
    void dispTransactionFaliure();
    void dispStandby();
};