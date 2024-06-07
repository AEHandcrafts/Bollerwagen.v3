#pragma once

#include "program.h"
#include <array>

template<unsigned long NUMBER_OF_PROGRAMS>
class renderer {
  public:
  explicit renderer(std::array<program *, NUMBER_OF_PROGRAMS> programs) : programs(programs) {
  }
  void next() {
    this->runningProgram = this->runningProgram + 1 % NUMBER_OF_PROGRAMS;
  }
  void render() {
    this->programs[runningProgram]->render(this->frame);
    this->frame++;
  }

  private:
  std::array<program *, NUMBER_OF_PROGRAMS> programs;
  int runningProgram = 0;
  unsigned long frame = 0;
};
