#include <Wire.h>  // I2C library
#include "SSD1306Ascii.h"  // libraries for SSD1306 display
#include "SSD1306AsciiAvrI2c.h"

#define I2C_ADDRESS 0x3C  // I2C address for screen
SSD1306AsciiAvrI2c screen; // class constructor for screen

void setup(void) {
  Serial.begin(9600);
  Wire.begin();  // begin I2C wire class

  // initialize and clear display
  screen.begin(&Adafruit128x32, I2C_ADDRESS);
  screen.setFont(Arial14);
  screen.clear();
  screen.setRow(0);
  screen.println("Hello World!");
}

void loop() {
}
