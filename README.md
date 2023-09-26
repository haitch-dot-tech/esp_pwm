# esp_pwm
A very basic library intended to make using ledc functions easier.


## Installation
### Arduino IDE
1. Download .ZIP from Code dropdown on this repo's page
2. Open the Arduino IDE and go to Sketch > Include Library > Add .ZIP Library
3. If the Arudino IDE outputs "Library installed", you're all good to go!
4. Go back to Sketch > Include Library and click the library to include it.

### PlatformIO
1. WIP


## Usage
### Create Object
Between #include(s) and setup(), add:

esp_pwm object_name;

Where "object_name" shows how you will call the library in the sketch.

"object name" can be anything, but these are some good ones for simplicity and clarity:
1. pwm
2. led
3. esp_pwm
4. motor (if you are to be using one, yes it is compatible)

You can even have multiplt objects at once, such as:

esp_pwm led1;

esp_pwm led2;

In this case, make sure that you initialise both and both seperately!

### Initialisation
To initialise the library, you must call

object_name.init(channel, pin, resolution, frequency);

__Where:__

__channel__ = the PWM controller channel you wish to use. The ESP32 has 16 channels, referred to as 0-15, and they can be mapped to any output-capable pin.

__pin__ = the pin that you want the controller channel to be mapped to, aka. the output pin.

__resolution__ = the resolution of PWM output, 1-16 bits.

__frequency__ = The frequeny of which the PWM Output is. 5000Hz (5kHz) is a good starting point for LEDs

__Please Note:__

The frequency range of the ESP32 is 10Hz to 40MHz - however, higher frequencies require a smaller bit depth which means the output is not as accurate for frequencies above ~300kHz.

### Setting the PWM
You can set the Duty Cycle (LED Brightness, Motor Speed, etc.) by calling:

object_name.setOutput(duty);

__Where:__

__duty__ = the duty cycle of the PWM output

### Fading the signal On or Off
The esp_pwm library has the ability to dim an LED with ease. Just use:

object_name.fadeOn(duration);

object_name.fadeOff(duration);

__Where:__

__duration__ = the amount of time that it will take the output to fade from one state to the other (high-low or vice versa). Fading up or down from the current state is not yet available in this library.
