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
    delay(5000);
  }

  private:
  Matrix &matrix;
  CRGB color;
};