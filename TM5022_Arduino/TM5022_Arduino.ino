  /*
 * GPIO Output read status LOW = 0
 * GPIO Output read status HIGH = 1
 */
#include "stopper.h"
#include <neotimer.h>
#include "sensor.h"

//GPIO SetUp (Stopper)
stopper leftStopper(0);
stopper rightStopper(1);

//GPIO SetUp (Sensor)
sensor stationSensor(5);
sensor statusButton(1);

// Timer Setup
Neotimer t0 = Neotimer(2000);   // 2 second timer
Neotimer t1 = Neotimer(3000);   // 3 second timer
Neotimer t2 = Neotimer(5000);   // 5 second timer

int state = 0;
int deliver = 0;
char message;
char store;

void setup() {
  Serial.begin(9600);
  t0.start();

  // Original Position
  leftStopper.open();
  delay(200);
  rightStopper.open();

  Serial.println("Start\n");
}



void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.read() == 's')
  {
    deliver = 1;            // 1 = ready to mailing process
    // Serial.print("Ready for collection!\n");
    // Serial.print("Signal received\n");
  }
  
  if (state == 0)                                         // Open all stopper and start and wait for node-red 's' response
  {
     //Serial.print("State 0 is started\n");
     rightStopper.open();
     delay(200);
     leftStopper.open();
     if (Serial.read() == 's')                            // TRANSITION CONDITION // 's' is transmitted by node-red
     {
       state = 1;
       Serial.print("Change to State 1\n");
       deliver=1;
    }
  }
}
