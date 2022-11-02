#include "math.h"  // need this for log

#define OUT_PIN 6
#define FILTER_IN_PIN A0
#define FILTER_OUT_PIN A1

void setup() // setup function
{
  Serial.begin(9600);  // set up serial connection at 9600 Baud
  pinMode(OUT_PIN, OUTPUT);  // setup pins
  digitalWrite(OUT_PIN,HIGH);  // initially set output as high
}

void loop() // main loop
{
  float tau = fsmComputeTau();  // FSM to compute tau
  //Serial.println(tau);  // plot tau vs. time
  
  //float vin = pinVoltage(FILTER_IN_PIN); 
  //Serial.println(vin);  // plot vin vs. time
}

// function to compute tau
float computeTau(float time, float beta)
{
  float tau = fsmComputeTau();// this is where you compute tau
  return(tau);
}

// functions that returns voltage on pin
float pinVoltage(int pin)
{
  float v_pin = 5.0 * ( (float) analogRead(pin) / 1024.0 );
  return(v_pin);
}

float fsmComputeTau() // state machine to compute tau
{
  static int state = 0;
  static float tau=0;
  static unsigned long startTime = millis();  // for time in state
  unsigned long currentTime;
  float capVoltage = pinVoltage(FILTER_OUT_PIN);  // voltage across capacitor
  Serial.println(capVoltage); // plot cap voltage (debugging)

  float Vcc = 5;  // pin voltage when HIGH
  float beta = 0.1;  // beta: switching threshold
  
  switch (state) 
  {
    case 0: // charging capacitor (pin is HIGH)
      // in-state actions

      // state transition logic
      if (capVoltage >= (1-beta)*Vcc){
        state = 1; // next state
        // output actions
        currentTime = millis();
        float T = ((float)(currentTime-startTime))/1000.0;
        //Serial.println(T); // (debugging)
        startTime = currentTime;
        tau = computeTau(T, beta);  
        digitalWrite(OUT_PIN, LOW);
      }
      break;
    
    case 1: // discharging capacitor (pin is Low)
      // in-state actions

      // state transition logic
      if (capVoltage <= beta*Vcc){
        state = 0; // next state
        // output actions
        currentTime = millis();
        float T = ((float)(currentTime-startTime))/1000.0;
        //Serial.println(T);  // (debugging)
        startTime = currentTime;
        tau = computeTau(T, beta);
        digitalWrite(OUT_PIN, HIGH);
      }
      break;
    default:
      state=0;
      break;
  }
  return(tau);
}
