#pragma once

class program {
  public:
  virtual ~program() = default;
  virtual void render(unsigned long frame) = 0;
};