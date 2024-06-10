#pragma once

#include <Arduino.h>
#include <FastLED.h>

#include "../program.h"

class StaticColor : public Program {
  public:
  StaticColor(Matrix &matrix, CRGB color) : matrix(matrix), color(color) {}
  ~StaticColor() override = default;
  void render(uint32_t frame) override {
    this->matrix.fill(this->color);
    this->matrix(0, 0) = CRGB::White;// TODO remove this line. This is just for testing purposes
    this->matrix(9, 9) = CRGB::White;// TODO remove this line. This is just for testing purposes
  }

  private:
  const Matrix &matrix;
  const CRGB color;
};