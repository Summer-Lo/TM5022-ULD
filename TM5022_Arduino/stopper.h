// stopper.h

#ifndef stopper_h
#define stopper_h

#include <Arduino.h>

#define STOPPER_L_PIN 9
#define STOPPER_R_PIN 10

class stopper
{
    public:
        stopper(int pin);
        void close();
        void open();

    private:
        int _pin;
        int count;
        int previousStatus; // 0 == open, 1 == close
};

#endif
