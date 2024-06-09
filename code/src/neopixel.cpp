#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "neopixel.h"

Neopixel::Neopixel(int numOfPixel, int pin) 
  : pixels(numOfPixel, pin, NEO_GRB + NEO_KHZ800) { // Use member initializer list to initialize pixels
    pixels.begin();
    _neopixel_pin = pin;
    _numOfPixels = numOfPixel;
}

void Neopixel::dispStandby() {
  pixels.clear();
  for(int i=0; i<_numOfPixels; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 127, 0));
  }
  pixels.show(); 
}

void Neopixel::dispTransactionLoading(){
  pixels.clear();

  for(int i=0; i<_numOfPixels; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 127));
    pixels.show(); 
    delay(100);
  }
    pixels.clear();
    pixels.show(); 
    delay(100);
}