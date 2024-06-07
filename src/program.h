#pragma once

class Program {
  public:
  virtual ~Program() = default;
  virtual void render(uint32_t frame) = 0;
};