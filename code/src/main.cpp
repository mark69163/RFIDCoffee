#include <Arduino.h>

#include "config.h"

#include "motor.h"

Motor motor(motPwmPin1,motPwmPin2,motEncPin1);

void setup() {
  Serial.begin(115200);
  if(!motor.begin())Serial.println("Motor operational");
  else  Serial.println("Motor is jammed!");
}

void loop() {
  //motor.feed();
  //Serial.println(analogRead(A0));
}



