/**
 * Project:     Ultrasonic Library
 * Description: Ultrasonic sensor library for Arduino
 * Version:     v1.0
 * Author:      Kompanets Konstantin (aka I2M)
 */

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "Arduino.h"

#define TIME_DELAY    100

class Ultrasonic {
public:
  void begin(uint8_t trig_pin, uint8_t echo_pin, uint16_t max_dist = 400);
  uint16_t ping();
private:
  uint8_t _trig_pin;
  uint8_t _echo_pin;
  uint16_t _time_out;
  uint16_t _max_dist;
  uint32_t _duration;
  uint32_t _distance;
};

#endif
