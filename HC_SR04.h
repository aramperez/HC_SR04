#ifndef HC_SR04_H
#define HC_SR04_H
/*
  A simple class for an HC_SR04 ultrasonic sensor, primarily for use with Arduinos.
  Written by Aram Perez, aramperez at mac dot com.

  Copyright © 2016 Aram Perez

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation   files (the “Software”), to
  deal in the Software without restriction, including without limitation the
  rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
  sell copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
  IN THE SOFTWARE.    
*/

#include <Arduino.h>

class HC_SR04 {
    uint8_t _trigPin;
    uint8_t _echoPin;
    unsigned long _delay;

    HC_SR04();
    unsigned long microSeconds()
    {
      digitalWrite(_trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(_trigPin, LOW);

      unsigned long ms = pulseIn(_echoPin, HIGH, _delay);
      if( ms == 0 ){
      	return (unsigned long) -1;
      }
      return ms;
    }

  public:
    HC_SR04(uint8_t trigPin, uint8_t echoPin, unsigned long delay = 1000) :
      _trigPin(trigPin),
      _echoPin(echoPin),
      _delay(delay)
    {
      pinMode(trigPin, OUTPUT);
      digitalWrite(trigPin, LOW);
      pinMode(echoPin, INPUT);
    }
    virtual ~HC_SR04() {};
    inline void setDelay(unsigned long delay){_delay = delay;}
    inline unsigned long inches()
    {
      return (unsigned long) (microSeconds() / 148);  //Per data sheet
    }
    inline unsigned long centimeters()
    {
      return (unsigned long) (microSeconds() / 58);  //Per data sheet
    }
};

#endif //HC_SR04_H

