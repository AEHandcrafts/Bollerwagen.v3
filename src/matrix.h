#pragma once

#include <FastLED.h>

class Matrix {
  public:
  Matrix(uint32_t width, uint32_t height) : width(width), height(height), leds(new CRGB[width * height]) {}
  ~Matrix() {
    delete[] this->leds;
  }
  void fill(CRGB color) const {
    for (uint32_t i = 0; i < this->width * this->height; i++) {
      leds[i] = color;
    }
  }
  void clear() const {
    this->fill(CRGB::Black);
  }

  public:
  const uint32_t width;
  const uint32_t height;
  CRGB *const leds;
};