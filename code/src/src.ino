#include <Arduino.h>
#include "config.h"
#include "motor.h"
#include "neopixel.h"

Motor motor(motPwmPin1,motPwmPin2,motEncPin1);

Neopixel ledRing(numOfPixels,neopixelPin);

bool motSelftestDone =false;


void setup() {
  
  Serial.begin(115200);
  motor.begin();

}

void loop() {
  ledRing.dispTransactionLoading();
}