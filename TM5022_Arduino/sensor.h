// sensor.h

#ifndef sensor_h
#define sensor_h

#include <Arduino.h>

#define SENSOR_PIN A2
#define END_PIN 2

class sensor
{
    public:
        sensor(int pin);
        int read();

    private:
        int _pin;
        int count;
        int previousResult;
};

#endif
