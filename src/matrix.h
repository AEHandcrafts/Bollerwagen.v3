#pragma once

#include <FastLED.h>

#include "matrix-mappings.h"

enum class MatrixMapping {
  BOTTOM_RIGHT_ZIGZAG
};

class Matrix {
  public:
  Matrix(uint32_t width, uint32_t height, MatrixMapping mappingStrategy) : width(width), height(height), leds(new CRGB[width * height]), mappingStrategy(mappingStrategy) {}
  ~Matrix() {
    delete[] this->leds;
  }
  inline CRGB &operator()(uint32_t x, uint32_t y) const {
    // could hve used the strategy pattern with real virtual function calls
    // but this method is assumed to be called quite often, so we optimize it for performance
    // by inlining the strategy and comparing an enum value to choose the proper implementation
    if (this->mappingStrategy == MatrixMapping::BOTTOM_RIGHT_ZIGZAG) return this->leds[mapBottomRightZigzag(x, y, this->width, this->height)];
    panic();
  }
  inline void fillColumn(uint32_t x, CRGB color) const {
    for (uint32_t y = 0; y < this->height; y++) this->operator()(x, y) = color;
  }
  inline void fillRow(uint32_t y, CRGB color) const {
    for (uint32_t x = 0; x < this->width; x++) this->operator()(x, y) = color;
  }
  inline void fill(CRGB color) const {
    for (uint32_t i = 0; i < this->width * this->height; i++) leds[i] = color;
  }
  inline void clear() const {
    this->fill(CRGB::Black);
  }

  public:
  const uint32_t width;
  const uint32_t height;
  CRGB *const leds;

  private:
  const MatrixMapping mappingStrategy;
};