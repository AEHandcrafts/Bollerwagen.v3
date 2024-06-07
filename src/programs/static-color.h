#pragma once

#include "../program.h"

class static_color : public program {
  public:
  ~static_color() override = default;
  void render(unsigned long frame) override {
  }
};