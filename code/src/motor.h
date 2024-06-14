#pragma once

#include <Arduino.h>

class Motor{
    private:
        uint8_t _pwmPin1;
        uint8_t _pwmPin2;
        uint8_t _encoderPin1;
        uint8_t _encoderPin2;

        uint8_t _maxSpeed;
        uint8_t _minSpeed;
         
        bool _forwardDir;

        const int rpm = 68;
        unsigned long testJamDuration = 5000; //jam test duration

    public:
        Motor( uint8_t pwmPin1, uint8_t pwmPin2,uint8_t encoderPin1,uint8_t encoderPin2, uint8_t maxSpeed, uint8_t minSpeed, bool forwardDir);
        Motor( uint8_t pwmPin1, uint8_t pwmPin2, uint8_t encoderPin1,uint8_t encoderPin2); 
        void feed(bool dir,uint8_t speed);
        void feed();
        void stop();
        void begin();
        bool testJam();
};

