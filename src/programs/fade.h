#pragma once

#include <FastLED.h>

#include "../matrix.h"
#include "../program.h"

class Fade : public Program {
  public:
  explicit Fade(Matrix &matrix) : matrix(matrix) {}
  ~Fade() override = default;
  void render(uint32_t frame) override {
    this->matrix.fill(CRGB().setHSV(frame % 255, 255, 255));
  }

  private:
  const Matrix &matrix;
};