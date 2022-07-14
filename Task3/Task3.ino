/*
 * Autor: Summer Lo
 * Updated date: 14/07/2022
 * Description: Design a step squence program for attaching the action in simultation and PLC via Raspberry Pi
 * 
 * GPIO Output read status LOW = 0 
 * GPIO Output read status HIGH = 1
 * Updates: Teacher version
 */
#include "stopper.h"
#include <neotimer.h>
#include "sensor.h"
int numBlinks=0;
int count = 0;

//GPIO SetUp (Stopper)
stopper leftStopper(0);
stopper rightStopper(1);
stopper bottomConveyor(2);
stopper dispatchCargo(3);
stopper verticalCargo(4);

//GPIO SetUp (Sensor)
sensor cargoDetector(0);
sensor statusButton(1);
sensor locationSensor(2);
sensor homeSensor(3);
sensor resetSensor(4);
sensor palletDetector(5);

// Timer Setup
Neotimer t0 = Neotimer(1600);   // 1.6 second timer
Neotimer t1 = Neotimer(3000);   // 3 second timer
Neotimer t2 = Neotimer(5000);   // 5 second timer

int state = 0;
int deliver = 0;
unsigned long timer1;
unsigned long timer2;
unsigned long timeDiff;

void setup() {
    Serial.begin(9600);
    t0.reset();
    t2.reset();

    // Original Position
    bottomConveyor.activate();
    delay(200);
    dispatchCargo.activate();
    delay(200);
    verticalCargo.activate();
    delay(200);

    Serial.println("Start\n");
}



void loop() {
    // put your main code here, to run repeatedly:
    
    if (state == 0)                                     // State 0
    {
        if (homeSensor.read() == 1)                     // Check the home sensor 
        {
            state = 1;                                  // Set state = 1
            Serial.println("The Cargo is ready!");
            Serial.println("Change to State 1!");
        }  
    }
    
    else if (state == 1)                                // State 1
    {
        // Write your code - Begin

        // Write your code - End
    }
    
    else if (state == 2)                                // State 2
    {
        // Write your code - Begin

        // Write your code - End
    }

    else if (state == 3)                                // State 3
    {
        if(cargoDetector.read() == 1)                   // Check the cargo detector
        {
            state = 0;                                  // Set state = 0
            Serial.println("Change to State 0!");
        }
    }
}