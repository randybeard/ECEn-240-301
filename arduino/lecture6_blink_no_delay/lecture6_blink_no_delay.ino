#include "Arduino.h"

#define LED 3
#define TRUE 1
#define FALSE 0

void setup() {  
  Serial.begin(9600);  // set up serial connection at 9600 Baud
  pinMode(LED, OUTPUT);  // set up the pins
  doTurnLedOn(LED);  // start with LED on
}

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
  static int state = 0;   
  static unsigned long start_time = millis();  
  unsigned long current_time = millis();
  unsigned long time_in_state = current_time-start_time;
  switch (state)
  {
    case 0:  // LED is on
      if (time_in_state > 1000){  
        state = 1; 
        start_time = current_time;  
        doTurnLedOff(LED);  
      }
      break;
    case 1:  // LED is off
      if (time_in_state > 1000){  
        state = 0; 
        start_time = current_time;  
        doTurnLedOn(LED);  
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
