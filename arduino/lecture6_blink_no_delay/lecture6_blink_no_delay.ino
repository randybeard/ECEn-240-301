#include "Arduino.h"

// compiler define functions: the compiler replaces name with number
#define LED 3
#define TRUE 1
#define FALSE 0

/********************************************************************
 * setup function - this gets executed at power up, or after a reset
 ********************************************************************/
void setup() {  
  Serial.begin(9600);  // set up serial connection at 9600 Baud
  pinMode(LED, OUTPUT);  // set up the pins
  doTurnLedOn(LED);  // start with LED on
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
  static int state = 0;   // initialize the state machine to 0
  static unsigned long start_time = millis();  // get the current time in milliseconds
  unsigned long current_time = millis();
  unsigned long time_in_state = current_time-start_time;
  Serial.println(state);
  switch (state)
  {
    case 0:  // LED is on
      // in-state actions
        // no action because LED is already on
      
      // state transition logic
      if (time_in_state > 1000){  // check to see if time in state is > 1000 milliseconds
        state = 1; // if so, go to state 1
        // output actions
        start_time = current_time;  // reset the start time
        doTurnLedOff(LED);  // turn LED off in transition
      }
      break;
    case 1:  // LED is off
      // in-state actions
        // no action because LED is already off

      // state transition logic
      if (time_in_state > 1000){  // check to see if time in state is > 1000 milliseconds
        state = 0; // if so, go to state 1
        // output actions
        start_time = current_time;  // reset the start time
        doTurnLedOn(LED);  // turn LED on in transition
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
void doTurnLedOn(int led_pin)
{
  digitalWrite(led_pin, HIGH); 
}

// Function to turn LED off
void doTurnLedOff(int led_pin)
{
  digitalWrite(led_pin, LOW); 
}
