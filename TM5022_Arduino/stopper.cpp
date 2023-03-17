#include <Arduino.h>
#include "stopper.h"

stopper::stopper(int pin)
{
    if (pin == 0) _pin = STOPPER_L_PIN;    // left stopper
    if (pin == 1) _pin = STOPPER_R_PIN;    // right stopper
    pinMode(_pin,OUTPUT);        // set pin as the GPIO output pin
    count = 0;
    previousStatus = 0;                    // 0 == open and 1 == close
}

void stopper::close()
{
    if(previousStatus == 0){             // if previous Status = open, reset counting
      count = 0;
    }
    if(count == 0){
      digitalWrite(_pin, LOW);          // LOW == PULL HIGH (BJT)
      // Serial.println("Pin is: " + String(_pin));
      // Serial.println("Stopper is closed!");
      previousStatus = 1;
      count++;
    }
    
}

void stopper::open()
{
    if(previousStatus == 1){             // if previous Status = close, reset counting
      count = 0;
    }
    if(count == 0){
      digitalWrite(_pin, HIGH);         // HIGH == PULL LOW (BJT)
      // Serial.println("Pin is: " + String(_pin));
      // Serial.println("Stopper is Opened!");
      previousStatus = 0;
      count++;
    }
}
