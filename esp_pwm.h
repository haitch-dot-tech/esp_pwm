/* File: esp_pwm.h */

/*
    ESP32 PWM Library
    Created By Henry Hall (HH-au)

    Description:
    A simple library that can be easily used to 
    run PWM output on all pins of the ESP32.
*/

#ifndef ESP_PWM_H
#define ESP_PWM_H

#include <Arduino.h>

class esp_pwm {
    public:
        esp_pwm();
        void init(int chan, int pin, int res, int freq);
        void setOutput(int duty);
        void fadeOn(int duration);
        void fadeOff(int duration);
    private:
        int _chan;
        int _pin;
        int _res;
        int _freq;
        int _max_duty;

        int _duty;

        int _duration;
};


#endif