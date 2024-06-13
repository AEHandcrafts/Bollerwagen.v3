#pragma once

#include <initializer_list>

#include "program.h"

class Renderer {
  public:
  Renderer(std::initializer_list<Program *> programs) : numberOfPrograms(programs.size()), programs(new Program *[programs.size()]) {
    std::copy(programs.begin(), programs.end(), this->programs);
  }
  ~Renderer() {
    delete[] this->programs;
  }
  void next() {
    this->runningProgram = this->runningProgram + 1 % this->numberOfPrograms;
  }
  inline void render() {
    // TODO: calculate and cap FPS
    this->programs[runningProgram]->render(this->frame);
    this->frame++;
  }

  private:
  const uint32_t numberOfPrograms;
  Program **const programs;
  uint32_t runningProgram = 0;
  uint32_t frame = 0;
};
