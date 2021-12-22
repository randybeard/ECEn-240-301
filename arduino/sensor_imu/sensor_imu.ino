#include <Wire.h>  // I2C library
#include <MPU6050_light.h> // MPU 6050 library (one of several)
#include "SSD1306Ascii.h"  // libraries for SSD1306 display
#include "SSD1306AsciiAvrI2c.h"

#define I2C_ADDRESS 0x3C  // I2C address for screen
SSD1306AsciiAvrI2c screen; // class constructor for screen
MPU6050 mpu(Wire);  // class constructor for mpu

void setup(void) {
  Serial.begin(9600);
  Wire.begin();  // begin I2C wire class

  // initialize and clear display
  screen.begin(&Adafruit128x32, I2C_ADDRESS);
  screen.setFont(Arial14);
  screen.clear();
  
  // initialize mpu with user selectable scale and range
  mpu.begin();
  delay(1000);
  mpu.calcOffsets(true,true);  // auto calibrate gyro and accels
    // IMU must be stationary and level during calibration
}

void loop() {
  mpu.update();  // get new measurements from IMU
  //printGyros();  // write gyro values to serial port
  printAccels();  // write accels to serial port
  displayAngles();  // write angles to OLED screen
}

void printGyros(){
  float gyroX = mpu.getGyroX();
  float gyroY = mpu.getGyroY();
  float gyroZ = mpu.getGyroZ();
  Serial.print(gyroX);
  Serial.print(",");
  Serial.print(gyroY);
  Serial.print(",");
  Serial.print(gyroZ); 
  Serial.println("");  
}

void printAccels(){
  float accelX = mpu.getAccX();
  float accelY = mpu.getAccY();
  float accelZ = mpu.getAccZ();  
  Serial.print(accelX);
  Serial.print(",");
  Serial.print(accelY);
  Serial.print(",");
  Serial.print(accelZ);
  Serial.println("");  
}

void displayAngles(){
  float rollAngle = mpu.getAccAngleY();
  float pitchAngle = mpu.getAccAngleX();
  screen.setRow(0);
  screen.print("Roll: ");
  screen.print(rollAngle, 0);
  screen.println("     ");
  screen.setRow(2);
  screen.print("Pitch: ");
  screen.print(pitchAngle, 0);
  screen.println("     ");
}
