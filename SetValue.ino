/*
  SetValue.ino

  A simple test of the core functionality of the esp_pwm library.
  When used coorrectly, this code will set pin 25 on an ESP32 to 50% duty cycle at 5kHz.
*/

#include <esp_pwm.h>

esp_pwm pwm; // Create a "pwm" object

void setup() {
  pwm.init(0, 25, 10, 5000); // Channel 0, Pin 25, 10 Bit Resolution, 5kHz Frequency
}

void loop() {
  pwm.setOutput(50); // 50% Duty Cycle
}