/**
 * Project Ultrasonic Sensor Library
 * Description: Ultrasonic sensor library for Arduino
 * Version: v1.0
 * Programmer: Kompanets Konstantin (aka I2M)
 *
 * Hardware setup: Ultrasonic sensor module
 */

#include "Ultrasonic.h"

uint32_t previousMillis = 0xFFFFFF9C;

void Ultrasonic::begin(uint8_t trig_pin, uint8_t echo_pin, uint16_t max_dist) {
  _trig_pin = trig_pin;
  _echo_pin = echo_pin;
  _time_out = min(max_dist, 400) * 58;
  _max_dist = min(max_dist, 400);
  pinMode(_trig_pin, OUTPUT);
  pinMode(_echo_pin, INPUT);
}

uint16_t Ultrasonic::ranging() {
  uint32_t currentMillis = millis();

  if(currentMillis - previousMillis >= 100) {
    previousMillis = currentMillis;

    digitalWrite(_trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trig_pin, LOW);

    _duration = pulseIn(_echo_pin, HIGH, _time_out);
    _distance = _duration / 58;

    if (_distance >= _max_dist || _distance <= 0) {
      _distance = _max_dist;
    }
  }
  return _distance;
}
