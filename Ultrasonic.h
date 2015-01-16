/**
 * Project Ultrasonic Sensor Library
 * Description: Ultrasonic sensor library for Arduino
 * Version: v1.0
 * Programmer: Kompanets Konstantin (aka I2M)
 *
 * Hardware setup: Ultrasonic sensor module
 */

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "Arduino.h"

class Ultrasonic {
public:
  void begin(uint8_t trig_pin, uint8_t echo_pin, uint16_t max_dist = 400);
  uint16_t ranging();
private:
  uint8_t _trig_pin;
  uint8_t _echo_pin;
  uint16_t _time_out;
  uint16_t _max_dist;
  uint32_t _duration;
  uint32_t _distance;
};

#endif
