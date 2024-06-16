
#pragma once

#include <Arduino.h>
#include <LiquidCrystal_Software_I2C.h>

class LCD{ 
  private:
    LiquidCrystal_I2C lcd;
  public:
    LCD(uint8_t _address,uint8_t _cols, uint8_t _rows);
    LCD(uint8_t _address,uint8_t _cols, uint8_t _rows,uint8_t _sda, uint8_t _scl);
    void printKeyData(uint8_t, uint8_t);
    void printTimestamp(String,String);
    void printError(int errorCode);
    void printStandby();
    void off();
    bool testLcd();
};