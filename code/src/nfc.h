#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_PN532.h>

class Nfc{
  private:
    Adafruit_PN532 nfc;
    
  public:
    uint32_t  firmwareVersion;

    Nfc(uint8_t irq, uint8_t reset);
    void begin(uint8_t sda, uint8_t scl);
    bool selfTest();
    bool read();
    //bool write(String data);
    
};

