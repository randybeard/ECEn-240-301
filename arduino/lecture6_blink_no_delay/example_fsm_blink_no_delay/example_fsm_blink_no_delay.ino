#include "Arduino.h"

// compiler directive: the compiler replaces name with number
#define LED 3
#define TRUE 1
#define FALSE 0
#define BLINK_TIME 1000

/********************************************************************
 * setup function - this gets executed at power up, or after a reset
 ********************************************************************/
void setup() {  
  Serial.begin(9600);  // set up serial connection at 9600 Baud
  pinMode(LED, OUTPUT);  // set the LED pin to OUTPUT mode
  doTurnLedOn();  // turn the LED on at beginning
}

/********************************************************************
 * main loop - this gets executed in an infinite loop until power
 * off or reset.
 ********************************************************************/
void loop() 
{
  // state machine to blink LED
  fsmBlinkLed();

  // do other stuff here while LED is on or off
}

/********************************************************************
 * finite state machines
 ********************************************************************/
// finite state machine for blinking LED
int fsmBlinkLed() 
{
  static int state = 0;   // initialize the state machine to state 0
  static unsigned long start_time = millis();  // initialize the start time in milliseconds: keep in memory between function calls
  unsigned long current_time = millis();  // compute the current time in milliseconds
  unsigned long time_in_state = current_time-start_time;  // compute time spent in current state
  Serial.println(state);  
  switch (state)
  {
    case 0:  // LED is on
      // in-state actions
        // no action because LED is already on
      
      // state transition logic
      if (time_in_state > BLINK_TIME) {  
        state = 1; // if so, go to state 1
        // output actions
        start_time = current_time;  // reset the start time
        doTurnLedOff();  // turn LED off in transition
      }
      break;
    case 1:  // LED is off
      // in-state actions
        // no action because LED is already off

      // state transition logic
      if (time_in_state > BLINK_TIME) {  
        state = 0; // if so, go to state 0
        // output actions
        start_time = current_time;  // reset the start time
        doTurnLedOn();  // turn LED on in transition
      }
      break;
  }
  return(state);
}

/********************************************************************
 * functions that test different conditions
 ********************************************************************/

/********************************************************************
 * functions that take actions
 ********************************************************************/
// Function to turn LED on
void doTurnLedOn()
{
  digitalWrite(LED, HIGH); // write HIGH (5V) to the LED pin
}

// Function to turn LED off
void doTurnLedOff()
{
  digitalWrite(LED, LOW); // write LOW (0V) to the LED pin
}
