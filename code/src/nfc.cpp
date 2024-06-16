#include <Arduino.h>
#include "nfc.h"

Nfc::Nfc(uint8_t irq, uint8_t reset) 
    : nfc (irq, reset){
    }

void Nfc::begin(uint8_t sda, uint8_t scl){
   Wire.begin(sda, scl);
   nfc.begin();
}

bool Nfc::selfTest(){
  if(!nfc.begin())nfc.begin();
  
  if (! nfc.getFirmwareVersion())return true;
 
  firmwareVersion = nfc.getFirmwareVersion();
  return false;

  
}