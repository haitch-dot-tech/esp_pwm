/* File: esp_pwm.cpp */

#include <Arduino.h>
#include "esp_pwm.h"

/* Object (nothing) */
esp_pwm::esp_pwm() {}

/* Setup LEDs */
void esp_pwm::init(int chan, int pin, int res, int freq) {
    /* Link Private Variables */
    _chan = chan;
    _pin = pin;
    _res = res;
    _freq = freq;
    _max_duty = (int)(pow(2, res) - 1);
    
    /* Setup */
    ledcSetup(_chan, _freq, _res);
    ledcAttachPin(_pin, _chan);
}

/* Set LED Brightness */
void esp_pwm::setOutput(int duty) {
    _duty = duty;
    ledcWrite(_chan, duty);
}

/* Fade the LED on over a specified duration */
void esp_pwm::fadeOn(int duration) {
    _duration = duration;
    for(_duty = 0; _duty <= _max_duty; _duty++) {
        ledcWrite(_chan, _duty);
        delay(_duration / _max_duty);
    }
}

/* Fade the LED off over a specified duration */
void esp_pwm::fadeOff(int duration) {
    _duration = duration;
    for(_duty = _max_duty; _duty >= 0; _duty--) {
        ledcWrite(_chan, _duty);
        delay(_duration / _max_duty);
    }
}