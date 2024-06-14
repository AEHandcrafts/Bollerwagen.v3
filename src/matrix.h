#pragma once

#include <FastLED.h>

#include "matrix-mappings.h"

enum class MatrixMapping {
  BOTTOM_RIGHT_ZIGZAG
};

class Matrix {
  public:
  Matrix(uint32_t width, uint32_t height, MatrixMapping mappingStrategy) : width(37), height(9), ledsLeft(new CRGB[37 * 9 + 35 + 14]), ledsRight(new CRGB[37 * 9 + 35 + 14]), ledsCountLeft(37 * 9 + 35 + 14), ledsCountRight(37 * 9 + 35 + 14), mappingStrategy(mappingStrategy) {}
  ~Matrix() {
    delete[] this->leds;
  }
  inline CRGB &operator()(uint32_t x, uint32_t y, uint32_t left) const {
    // could hve used the strategy pattern with real virtual function calls
    // but this method is assumed to be called quite often, so we optimize it for performance
    // by inlining the strategy and comparing an enum value to choose the proper implementation
    if (this->mappingStrategy == MatrixMapping::BOTTOM_RIGHT_ZIGZAG) {
      if (left == 1)
        return this->ledsLeft[mapBottomRightZigzag(x, y, this->width, this->height)];
      else
        return this->ledsRight[mapBottomRightZigzag(36-x, y, this->width, this->height)];
    }
    panic();
  }
  inline void fillColumn(uint32_t x, CRGB color) const {
    for (uint32_t y = 0; y < this->height; y++) {
      this->operator()(x, y, 0) = color;
      this->operator()(x, y, 1) = color;
    }

    if (x == 0)
      for (uint32_t i = this->width * this->height + 35; i < this->width * this->height + 35 + 15; i++)
        this->ledsLeft[i] = color;
    else if (x == 36)
      for (uint32_t i = this->width * this->height + 35; i < this->width * this->height + 35 + 15; i++)
        this->ledsRight[i] = color;
    else {
      this->ledsLeft[this->width * this->height + x] = color;
      this->ledsRight[this->width * this->height + 36-x] = color;
    }
  }
  inline void fillRow(uint32_t y, CRGB color) const {
    for (uint32_t x = 0; x < this->width; x++) {
      this->operator()(x, y, 0) = color;
      this->operator()(x, y, 1) = color;
    }
  }
  inline void fill(CRGB color) const {
    for (uint32_t i = 0; i < this->ledsCountLeft; i++) {
      this->ledsLeft[i] = color;
      this->ledsRight[i] = color;
    }
  }
  inline void clear() const {
    this->fill(CRGB::Black);
  }

  public:
  const uint32_t width;
  const uint32_t height;
  CRGB *const ledsLeft;
  CRGB *const ledsRight;
  const uint32_t ledsCountLeft;
  const uint32_t ledsCountRight;

  private:
  const MatrixMapping mappingStrategy;
};