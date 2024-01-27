/*
  SetValue.ino

  A simple test of the core functionality of the esp_pwm library.
  When used correctly, this code will set an ESP32's pin 25 as a PWM output 
  with internal channel 0, a 10 bit resolution and 5kHz frequency.
  It then sets the pin to 50% duty cycle 
*/

#include <esp_pwm.h>

esp_pwm pwm; // Create a "pwm" object

void setup() {
    pwm.init(0, 25, 10, 5000); // Channel 0, Pin 25, 10 Bit Resolution, 5kHz Frequency
}

void loop() {
    pwm.setOutput(50); // 50% Duty Cycle
}
