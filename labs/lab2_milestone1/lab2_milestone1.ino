#include "Arduino.h"

// compiler define functions: the compiler replaces name with number
#define LED_STOP 7
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
////////////////////////////////////////////////////////////////////
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
      driveRobot();
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

/********************************************************************
 * functions that test different conditions
 ********************************************************************/
////////////////////////////////////////////////////////////////////
// Function that detects if there is an obstacle in front of robot
int isCollision() {
  // This is where you add code that tests if the BUTTON_COLLISION button 
  // has been pushed.  
  // Later in the semester you will add a sonar sensor to detect collision and 
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
////////////////////////////////////////////////////////////////////
// Function that drives the robot staight:
// Both wheels move at same speed.
void driveRobot() {
  // add code here to turn off the LED
  // you will modify this code in milestone 2
  // Later in the semester, you will add code that moves the robot
}

////////////////////////////////////////////////////////////////////
// Function that causes that causes the robot to stop moving.
void stopRobot() {
  // this is where you add code to turn on all of the leds
  // Later in the semester, you will add code that makes the robot stop moving
}

////////////////////////////////////////////////////////////////////
// Function to turn LED on
void turnLedOn(int led_pin) {
  // add some code to turn LED on
}

////////////////////////////////////////////////////////////////////
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
