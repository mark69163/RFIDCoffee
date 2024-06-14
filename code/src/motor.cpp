#include <Arduino.h>
#include "motor.h"

Motor::Motor(uint8_t pwmPin1, uint8_t pwmPin2,uint8_t encoderPin1,uint8_t encoderPin2, uint8_t maxSpeed, uint8_t minSpeed, bool forwardDir){
    _maxSpeed = maxSpeed;
    _minSpeed = minSpeed;
    _forwardDir = forwardDir;

    _pwmPin1 = pwmPin1;
    _pwmPin2 = pwmPin2;
    _encoderPin1 = encoderPin1;
    _encoderPin2 = encoderPin2;

};

Motor::Motor( uint8_t pwmPin1, uint8_t pwmPin2, uint8_t encoderPin1,uint8_t encoderPin2){
_maxSpeed = 255;
_minSpeed = 0;
_forwardDir = 0;

_pwmPin1 = pwmPin1;
_pwmPin2 = pwmPin2;
_encoderPin1 = encoderPin1;
_encoderPin2 = encoderPin2;



};

void Motor::begin(){
  pinMode(_pwmPin1,OUTPUT);
  pinMode(_pwmPin2,OUTPUT);

  pinMode(_encoderPin1,INPUT);
  pinMode(_encoderPin2,INPUT);
};

void Motor::feed(bool dir, byte speed){
  //feed forward
  if(dir == _forwardDir){
      analogWrite(Motor::_pwmPin1,speed);
      analogWrite(Motor::_pwmPin2,0);
  }

  //feed backwards
  else{
      analogWrite(Motor::_pwmPin1,0);
      analogWrite(Motor::_pwmPin2,speed);
  }
};

void Motor::feed(){
//feed forward
if(!_forwardDir){
    analogWrite(Motor::_pwmPin1,Motor::_maxSpeed);
    analogWrite(Motor::_pwmPin2,0);
}
//feed backwards
else{
    analogWrite(Motor::_pwmPin1,0);
    analogWrite(Motor::_pwmPin2,Motor::_maxSpeed);
}

};

void Motor::stop(){
   analogWrite(Motor::_pwmPin1,0);
   analogWrite(Motor::_pwmPin2,0);
};

bool Motor::testJam(){
    unsigned long currentTime = millis();
    int turnCounter = 0;

    //motor test function, drive it, and see whether a move is detected, else throw error
    while(millis()-currentTime <= testJamDuration){

        //if(map(analogRead(_encoderPin1),0,1024,0,1) == 1)turnCounter++;
        if(digitalRead(_encoderPin1))turnCounter++;
        else{
            //drive forward
            if(turnCounter<=rpm)feed(_forwardDir,127);
            //drive backwards
            else if (turnCounter<2*rpm && turnCounter>rpm)feed(!_forwardDir,127);
        }
        //Test Success: forward and backwards movement was successfully detected within the jamTestDuration
        if(turnCounter>=2*rpm){
            stop();
            return 0;
        }
        delay(10);
    }

    //Test Fail
    stop();
    return 1;
};
