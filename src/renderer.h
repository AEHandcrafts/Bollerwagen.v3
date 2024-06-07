#pragma once

#include "array.h"
#include "program.h"

template<unsigned long NUMBER_OF_PROGRAMS>
class renderer {
  public:
  explicit renderer(array<program *, NUMBER_OF_PROGRAMS> programs) : programs(programs) {}
  void next() {
    this->runningProgram = this->runningProgram + 1 % NUMBER_OF_PROGRAMS;
  }
  void render() {
    this->programs[runningProgram]->render(this->frame);
    this->frame++;
  }

  private:
  array<program *, NUMBER_OF_PROGRAMS> programs;
  int runningProgram = 0;
  unsigned long frame = 0;
};
