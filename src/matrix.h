#pragma once

class Matrix {
  public:
  Matrix(CRGB *leds, uint32_t width, uint32_t height) : width(width), height(height), leds(leds) {}
  void fill(CRGB color) {
    for (uint32_t i = 0; i < this->width * this->height; i++) {
      leds[i] = color;
    }
  }
  void clear() {
    this->fill(CRGB::Black);
  }

  public:
  const uint32_t width;
  const uint32_t height;

  private:
  CRGB *leds;
};