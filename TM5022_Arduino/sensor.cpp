#include <Arduino.h>
#include "sensor.h"

sensor::sensor(int pin)
{
    if(pin == 0){
      _pin = A2;  
    }
    if(pin == 1){
      _pin = 2;
    }
    count = 0;
    previousResult = 0;
    pinMode(_pin,INPUT);        // set pin as the GPIO input pin
}

int sensor::read()
{
    int result = digitalRead(_pin);          // 0 = didn't read the pallet / 1 = pallet read successfully (BJT Inverted)
    if(result != previousResult){
      count = 0;
    }
    //Serial.println("Counting number is: " + String(count));    
    previousResult = result;
    if(count == 0){
      // Serial.println("The read pin is: " + String(_pin));
      // Serial.println("The Sensor signal is read as: " + String(result));
      
      count ++;
    }
    
    return result;
}
