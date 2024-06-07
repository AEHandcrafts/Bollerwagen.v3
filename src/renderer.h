#pragma once

#include "array.h"
#include "program.h"

template<uint32_t NUMBER_OF_PROGRAMS>
class Renderer {
  public:
  explicit Renderer(Array<Program *, NUMBER_OF_PROGRAMS> programs) : programs(programs) {}
  void next() {
    this->runningProgram = this->runningProgram + 1 % NUMBER_OF_PROGRAMS;
  }
  void render() {
    this->programs[runningProgram]->render(this->frame);
    this->frame++;
  }

  private:
  Array<Program *, NUMBER_OF_PROGRAMS> programs;
  uint32_t runningProgram = 0;
  uint32_t frame = 0;
};
