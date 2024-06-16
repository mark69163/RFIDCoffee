#include <Arduino.h>
#include "config.h"
#include "motor.h"
#include "neopixel.h"
#include "lcd.h"
#include "nfc.h"

Motor motor(motPwmPin1,motPwmPin2,motEncPin1,motEncPin2);
Neopixel ledRing(numOfPixels,neopixelPin);
LCD lcd(lcdAddress,COLLS,ROWS,SDA,SCL);
Nfc nfc(nfcIrqPin,nfcReset);

void setup(){

  motor.begin();
  lcd.off();
  ledRing.dispOff();
  nfc.begin(SDA, SCL);

  /*
  Serial.begin(115200);
  while (!Serial) delay(10); 

  if (nfc.selfTest()) {
    Serial.print("Didn't find PN53x board");
  }
  else{
    // Got ok data, print it out!
      //Serial.println(nfc.firmwareVersion);
      Serial.print("Found chip PN5"); Serial.println((nfc.firmwareVersion>>24) & 0xFF, HEX);
      Serial.print("Firmware ver. "); Serial.print((nfc.firmwareVersion>>16) & 0xFF, DEC);
      Serial.print('.'); Serial.println((nfc.firmwareVersion>>8) & 0xFF, DEC);
  }
  */

}

void loop(){
//ledRing.dispTransactionProcessing(0,0,127);
//motor.feed();
}