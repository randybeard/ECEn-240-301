#include "Arduino.h"

// compiler define functions: the compiler replaces name with number
#define LED_TURN_RIGHT 5
#define LED_TURN_LEFT 3
#define LED_STOP 7
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
  pinMode(LED_TURN_RIGHT, OUTPUT);
  pinMode(LED_TURN_LEFT, OUTPUT);
  pinMode(LED_STOP, OUTPUT);  
 }

/********************************************************************
 * main loop - this gets executed in an infinite loop until power
 * off or reset.
 ********************************************************************/
void loop() {
  robotBrain();  // function that implements the robot's brain
}

/********************************************************************
 * main function for robot
 ********************************************************************/
void robotBrain() {
  fsmCollisionDetection();  // always check for collision. 
}

/********************************************************************
 * state machines
 ********************************************************************/
// state machine for collision avoidance
int fsmCollisionDetection() {  
  static int state = 0;
  //Serial.println(state);  // use this for debugging
  // There are two states in this state machine:
  //    state==0 means that the sensor does not detect a collision
  //    state==1 means that the sensor detects a collision
  switch (state) {
    case 0:  // no obstacle
      // state machine that steers robot:  only call this when there is no collision
      fsmSteerRobot();
      // state transition logic
      if (isCollision()==TRUE){
        state = 1; // if collision, go to obstacle state
      }
      break;
    case 1:  // obstacle in front of robot
      stopRobot();  // commands robot to stop
      // state transition logic
      if (isCollision()==FALSE){ 
        state = 0; // if no collision go to no-obstacle state
      }
      break;
  }
  return(state);
}

///////////////////////////////////////////////////
// State machine for steering the robot accordingly.
int fsmSteerRobot() {
  static int state = 0;
  // There are two states in this state machine:
  //    state==0 means that no light is detected
  //    state==1 means that the light is in front of the robot
  //    state==2 means that the light is to the right of the robot 
  //    state==3 means that the light is to the left of the robot
  switch (state) {
    case 0:  // no light detected in front of robot, don't move robot
      // Put your action code here

       // state transition logic
      if ((isLight(BUTTON_LIGHT_RIGHT)==TRUE)&&(isLight(BUTTON_LIGHT_LEFT)==TRUE)) {
        state = 1;  // light detected in front of robot, go to state 1
      }
      if (isLight(BUTTON_LIGHT_RIGHT)==TRUE) { 
        state = 2;   // light on right of robot, go to state 2
      }
      else if (isLight(BUTTON_LIGHT_LEFT)==TRUE) { 
        state = 3; // light on left of robot, go to state 3
      }
      break;
    case 1:  // light detected in front of robot
      // Put your action code here

      // add state transition logic
      if () {
        state = 0;  
      }
      else if () { 
        state = 2;   
      }
      else if () { 
        state = 3; 
      }
      break;
    case 2:  // light is on right of robot
      // Put your action code here

      // add state transition logic
      if () {
        state = 0;  
      }
      else if () { 
        state = 1;  
      }
      else if () { 
        state = 3; 
      }
      break;
    case 3:  // light is on left of robot
      // Put your action code here

      // add state transition logic
      if () {
        state = 0;  
      }
      else if () { 
        state = 1;  
      }
      else if () { 
        state = 2; 
      }
      break;
  }
  return(state);
}


/********************************************************************
 * functions that test different conditions
 ********************************************************************/
// Function that detects if there is an obstacle in front of robot
int isCollision() {
  // This is where you add code that tests if the BUTTON_COLLISION button 
  // has been pushed.  
  // In lab 6 you will add a sonar sensor to detect collision and 
  // the code for the sonar sensor will go in this function

  if (/* need a condition here*/) {  
    return( TRUE );
  }
  else {
    return( FALSE );
  }
}

////////////////////////////////////////////////////////////////////
// Function that detects if the light is present
int isLight(int pin) {
  // This is where you add code that tests if the BUTTON_LIGHT_LEFT (etc.) button 
  // has been pushed.  
  // In lab 5 you will add photo diodes to detect the light, and 
  // you will need to modify this function accordingly.

  if ( isButtonPushed(pin)==TRUE ) {
    return(TRUE);
  }
  else {
    return (FALSE);
  }  
}

////////////////////////////////////////////////////////////////////
// Function that drives the robot staight:
// Both wheels move at same speed.
void driveRobot(int curve) {
  if (curve==0) {  // go straight
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
void stopRobot() {
  // this is where you add code to turn on the collision led
  // In lab 6, you will add code that makes the robot stop moving
}

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
  // What does analogRead(pin) do?
  // Why is (float) needed?
  // Why divide by 1024?
  // Why multiply by 5.0?
  return( 5.0 * ( (float) analogRead(pin) ) / 1024.0 );
}
