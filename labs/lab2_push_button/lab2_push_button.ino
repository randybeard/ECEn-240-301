//#include "Arduino.h"

// compiler define functions: the compiler replaces name with number
#define LED 2
#define BUTTON A0
#define TRUE 1
#define FALSE 0

/********************************************************************
 * setup function - this gets executed at power up, or after a reset
 ********************************************************************/
void setup() {
  // set up serial connection at 9600 Baud
  Serial.begin(9600);
  
  // set up the pins
  pinMode(LED, OUTPUT);
  turnLedOff(LED);  // turn the LED off at the beginning
}

/********************************************************************
 * main loop - this gets executed in an infinite loop until power
 * off or reset.
 ********************************************************************/
void loop() {
  // state machine to detect collisions
  fsmButtonForLed();
}

/********************************************************************
 * finite state machines
 ********************************************************************/
// finite state machine for detecting push of button
void fsmButtonForLed()  {
  static int state = 0;  // Q: why use a static variable for state?
  Serial.println(state);  // use this to plot the state
  switch (state) {
    case 0:  // LED is off in this state
      // state transition logic
      if (isButtonPushed(BUTTON)==TRUE){
        state = 1; // if button is pushed, go to state 1
        turnLedOn(LED);  // but first turn LED on
      }
      break;
    case 1:  // LED is on
      // state transition logic
      if (isButtonPushed(BUTTON)==FALSE){ 
        state = 0; // if putton is not pushed, go to state 0
        turnLedOff(LED);  // but first turn LED off
      }
      break;
  }
}

/********************************************************************
 * functions that test different conditions
 ********************************************************************/
// Function that tests if button is pushed
int isButtonPushed(int button_pin) {
  float button_voltage = getPinVoltage(button_pin);
  
  //Serial.println(button_voltage);  // use this to plot button voltage
  if (/* need a condition here */){
    return(TRUE);
  }
  else {
    return (FALSE);
  }
}


/********************************************************************
 * functions that take actions
 ********************************************************************/
// Function to turn LED on
void turnLedOn(int led_pin) {
  // add some code to turn LED on
}

// Function to turn LED off
void turnLedOff(int led_pin) {
  // add some codde to turn LED off
}

////////////////////////////////////////////////////////////////////
// Function to read pin voltage
float getPinVoltage(int pin) {
  // This function can be used for many different tasks in the labs:
  // study this line of code to understand what is going on!!
  // Q: What does analogRead(pin) do?
  // Q: Why is (float) needed?
  // Q: Why divide by 1024?
  // Q: Why multiply by 5.0?  
  return( 5.0 * ( (float) analogRead(pin) ) / 1024.0 );
}
