#pragma once

class program {
  public:
  virtual ~program() = 0;
  virtual void render(unsigned long frame) = 0;
};