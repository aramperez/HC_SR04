# ElapsedTimer
A simple class for an HC SR04 ultrasonic sensor, primarily for use with Arduinos.

# Description
## HC\_SR04(_trigPin_, _echoPin_, _delay_)
Creates an HC_SR04 object (constructor).
### Arguments
* uint8_t _trigPin_: number of the pin connected to the trigger.
* uint8_t long _echoPin_: number of the pin where the echo delay comes back on.
* unsigned long _delay_: the delay, in milliseconds, to wait for the echo. Default is 1000 ms.

## void setDelay(_delay_)
Sets a new delay for listening for the echo.
### Arguments
* unsigned long _delay_: delay in milliseconds.

## unsigned long inches()
Returns distanced measured by the ultrasonic sensor in inches. If no echo was received in the _delay_ time, then (unsigned long) -1 is returned.

## unsigned long centimeters()
Returns distanced measured by the ultrasonic sensor in centimeters. If no echo was received in the _delay_ time, then (unsigned long) -1 is returned.
