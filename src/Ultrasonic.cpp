/**
 * Project:     Ultrasonic Library
 * Description: Ultrasonic sensor library for Arduino
 * Version:     v1.0
 * Author:      Kompanets Konstantin (aka I2M)
 */

#include "Ultrasonic.h"

uint32_t previous_millis = 0xFFFFFF9C;

void Ultrasonic::begin(uint8_t trig_pin, uint8_t echo_pin, uint16_t max_dist) {
  _trig_pin = trig_pin;
  _echo_pin = echo_pin;
  _time_out = min(max_dist, 400) * 58;
  _max_dist = min(max_dist, 400);
  pinMode(_trig_pin, OUTPUT);
  pinMode(_echo_pin, INPUT);
}

uint16_t Ultrasonic::ping() {
  uint32_t current_millis = millis();

  if(current_millis - previous_millis >= TIME_DELAY) {
    previous_millis = current_millis;

    digitalWrite(_trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trig_pin, LOW);

    _duration = pulseIn(_echo_pin, HIGH, _time_out);
    _distance = _duration / 58;

    if (_distance > _max_dist || _distance == 0) {
      _distance = _max_dist;
    }
  }
  return _distance;
}
