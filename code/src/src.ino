#include <Arduino.h>

#include "config.h"

#include "motor.h"

Motor motor(motPwmPin1,motPwmPin2,motEncPin1);

bool motSelftestDone =false;

void setup() {
  
  Serial.begin(115200);
  motor.begin();

}

void loop() {
  motor.feed(1,127);
  delay(2000);
  motor.feed();
  delay(2000);
  motor.stop();
  delay(2000);

}



