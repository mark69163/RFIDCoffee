#pragma once

#include "Arduino.h"

class Motor{
    private:
         byte _pwmPin1;
         byte _pwmPin2;
         byte _encoderPin1;

         byte _maxSpeed;
         byte _minSpeed;
         
         bool _forwardDir;

        const unsigned long testJamDuration = 5000; //5s jam test duration
        const int rpm = 68;
        

    public:
        Motor( byte pwmPin1, byte pwmPin2, byte maxSpeed, byte minSpeed, bool forwardDir,byte encoderPin1);
        Motor( byte pwmPin1, byte pwmPin2, byte encoderPin1); 
        void feed(bool dir,byte speed);
        void feed();
        void stop();
        bool begin();
        bool testJam();
};

