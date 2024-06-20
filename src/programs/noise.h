#pragma once

#include <FastLED.h>

#include "../matrix.h"
#include "../program.h"

class Noise : public Program {
  public:
  explicit Noise(Matrix &matrix, CRGB color) : matrix(matrix), color(color) {}
  ~Noise() override = default;
  void render(uint32_t frame) override {
    this->matrix.clear();
    for (uint8_t i = 0; i < 16; i++) {
      this->matrix(random(0, 37), random(0, 10), 0) = this->color;
      this->matrix(random(0, 37), random(0, 10), 1) = this->color;
    }
  }

  private:
  const Matrix &matrix;
  const CRGB color;
};