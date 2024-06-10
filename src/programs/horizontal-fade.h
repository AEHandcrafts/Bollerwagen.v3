#pragma once

#include <FastLED.h>

#include "../matrix.h"
#include "../program.h"

class HorizontalFade : public Program {
  public:
  explicit HorizontalFade(Matrix &matrix) : matrix(matrix) {}
  ~HorizontalFade() override = default;
  void render(uint32_t frame) override {
    for (uint32_t x = 0; x < matrix.width; x++) {
      auto hue = static_cast<uint8_t>((static_cast<double>(x) / matrix.width) * 255 + frame);
      this->matrix.fillColumn(x, CRGB().setHSV(hue, 255, 255));
    }
  }

  private:
  const Matrix &matrix;
};