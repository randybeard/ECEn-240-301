#include "Arduino.h"

// compiler define functions: the compiler replaces name with number
#define LED_SERVO_UP 6  // replace the pin numbers with those you connect 
#define LED_SERVO_DOWN 2
#define LED_TURN_RIGHT 5
#define LED_TURN_LEFT 3
#define LED_STRAIGHT 7
#define BUTTON_LIGHT_TOP A0
#define BUTTON_LIGHT_BOTTOM A4
#define BUTTON_LIGHT_RIGHT A1
#define BUTTON_LIGHT_LEFT A3
#define BUTTON_COLLISION A2
#define TRUE 1
#define FALSE 0

/********************************************************************
 * setup function - this gets executed at power up, or after a reset
 ********************************************************************/
void setup() {
  // set up serial connection at 9600 Baud
  Serial.begin(9600);
  // set up the pins
  // set up the pins
  pinMode(LED_SERVO_UP, OUTPUT);
  pinMode(LED_SERVO_DOWN, OUTPUT);
  pinMode(LED_TURN_RIGHT, OUTPUT);
  pinMode(LED_TURN_LEFT, OUTPUT);
  pinMode(LED_STRAIGHT, OUTPUT);  
 }

/********************************************************************
 * main loop - this gets executed in an infinite loop until power
 * off or reset.
 ********************************************************************/
void loop() {
  // This state machine drives the robot to follow light at speed
  fsmFollowLight();
}

/********************************************************************
 * state machines
 ********************************************************************/
///////////////////////////////////////////////////
// main state machine for light following robot
int fsmFollowLight() {  
  static int state = 0;
  //Serial.println(state);
  switch (state) {
    case 0:  // no obstacle
      // state machine that turns robot side-to-side to follow light
      fsmTurnToLight();
      // state machine to move servo up and down to follow light
      fsmMoveLightSensor(); 
     
      // state transition logic
      if (isCollision()==TRUE){
        state = 1; // if collision, go to obstacle state
      }

      break;
    case 1:  // obstacle in front of robot
      doStopRobot();  // commands robot to stop

      // state transition logic
      if (isCollision()==FALSE){ 
        state = 0; // if no collision go to no-obstacle state
      }
      break;
  }
  return(state);
}

///////////////////////////////////////////////////
// State machine for detecting if light is to the 
// right or left, and steering the robot accordingly.
int fsmTurnToLight() {
  static int state = 0;
  switch (state) {
    case 0:
      doDriveRobot(0);  // in this state, drive straight

      // state transition logic
      if (isLightRight()==TRUE) { 
        state = 1;   // light on right of robot, go to state 1
      }
      else if (isLightLeft()==TRUE) { 
        state = 2; // light on left of robot, go to state 2
      }
      break;
    case 1:  // light is on right of robot
      doDriveRobot(+1);  // in this state curve right

      // state transition logic
      if (isLightRight()==FALSE) { 
        state = 0; // light no longer on right of robot, to to state 0
      }
      break;
    case 2:  // light is on left of robot
      doDriveRobot(-1);  // curve left
      //Serial.println(1);

      // state transition logic
      if (isLightLeft()==FALSE) { 
        state = 0; // light is no longer on left, to to state 0
      }
      break;
  }
  return(state);
}

///////////////////////////////////////////////////
// State machine for detecting if light is above or below
// center and moving the servos accordingly.
int fsmMoveLightSensor() {
  static int state = 0;
  switch (state) {
    case 0:

      // state transition logic
      if (isLightUp()==TRUE) { 
        state = 1; // Light is above sensor, go to state 1
      }
      if (isLightDown()==TRUE) { 
        state = 2;  // Light is below sensor, go to state 2 
      }
      break;
    case 1:  // light is above sensor
      doMoveServo(+1);  // move servo up

      // state transition logic
      if (isLightUp()==FALSE) { 
        state = 0; // Light is no longer above sensor, go to state 0
      }
      break;
    case 2:  // light is below sensor
      doMoveServo(-1);  // move servo down

      // state transition logic
      if (isLightDown()==FALSE) { 
        state = 0; // Light is no longer above sensor, go to state 0
      }
      break;
  }
  return(state);
}


/********************************************************************
 * functions that test different conditions
 ********************************************************************/
////////////////////////////////////////////////////////////////////
// Function that detects if there is an obstacle in front of robot
int isCollision() {
  // This is where you add code that tests if the BUTTON_COLLISION button 
  // has been pushed.  
  // In lab 6 you will add a sonar sensor to detect collision and 
  // the code for the sonar sensor will go in this function

  if (/* need a condition here*/) {  
    output = TRUE;
  }
  else {
    output = FALSE;
  }
  return( output );
}

////////////////////////////////////////////////////////////////////
// Function that detects if the light is to the left of center
int isLightLeft() {
  // This is where you add code that tests if the BUTTON_LIGHT_LEFT button 
  // has been pushed.  
  // In lab 5 you will add photo diodes to detect the light, and 
  // you will need to modify this function accordingly.

  if ( /* need a condition here*/ ) {
    return(TRUE);
  }
  else {
    return (FALSE);
  }  
}

////////////////////////////////////////////////////////////////////
// Function that detects if the light is to the right of center
int isLightRight() {
  // This is where you add code that tests if the BUTTON_LIGHT_RIGHT button 
  // has been pushed.  
  // In lab 5 you will add photo diodes to detect the light, and 
  // you will need to modify this function accordingly.

  if ( /* need a condition here*/ ) {
    return(TRUE);
  }
  else {
    return (FALSE);
  }  
}

////////////////////////////////////////////////////////////////////
// Function that detects if the light is above center
int isLightUp() {
  // This is where you add code that tests if the BUTTON_LIGHT_TOP button 
  // has been pushed.  
  // In lab 5 you will add photo diodes to detect the light, and 
  // you will need to modify this function accordingly.

  if ( /* need a condition here*/ ) {
    return(TRUE);
  }
  else {
    return (FALSE);
  }    
}

////////////////////////////////////////////////////////////////////
// Function that detects if the light is below center
int isLightDown() {
  // This is where you add code that tests if the BUTTON_LIGHT_BOTTOM button 
  // has been pushed.  
  // In lab 5 you will add photo diodes to detect the light, and 
  // you will need to modify this function accordingly.

  if ( /* need a condition here*/ ) {    return(TRUE);
  }
  else {
    return (FALSE);
  }  
}

////////////////////////////////////////////////////////////////////
// Function that drives the robot staight:
// Both wheels move at same speed.
void doDriveRobot(int curve) {
  if (curve==0) {  // go straight
    // this is where you add code to turn on the LED_STRAIGHT led
    // In lab 6, you will add code that makes the robot drive straight
  }
  else if (curve>0) {  // curve right
    // this is where you add code to turn on the LED_TURN_RIGHT led
    // In lab 6, you will add code that makes the robot curve right
  }
  else { // curve left
    // this is where you add code to turn on the LED_TURN_LEFT led
    // In lab 6, you will add code that makes the robot curve left
  }
}

////////////////////////////////////////////////////////////////////
// Function that causes that causes the robot to stop moving.
void doStopRobot() {
  // this is where you add code to turn on all of the leds
  // In lab 6, you will add code that makes the robot stop moving
}

////////////////////////////////////////////////////////////////////
// Function to read pin voltage
float getPinVoltage(int pin) {
  // This function can be used for many different tasks in the labs:
  // study this line of code to understand what is going on!!
  // What does analogRead(pin) do?
  // Why is (float) needed?
  // Why divide by 1024?
  // Why multiply by 5.0?
  return( 5.0 * ( (float) analogRead(pin) ) / 1024.0 );
}
