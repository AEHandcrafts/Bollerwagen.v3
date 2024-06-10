#pragma once

#include <FastLED.h>

#include "../matrix.h"
#include "../program.h"

class Fade : public Program {
  public:
  explicit Fade(Matrix &matrix) : matrix(matrix), color(CRGB::Black) {}
  ~Fade() override = default;
  void render(uint32_t frame) override {
    this->color.setHSV(frame % 255, 255, 255);
    this->matrix.fill(color);
  }

  private:
  const Matrix &matrix;
  CRGB color;
};