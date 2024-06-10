#pragma once

inline uint32_t mapBottomRightZigzag(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
  if (y % 2 == 0) return height * (height - 1 - y) + x;
  return height * (height - 1 - y) + (width - 1 - x);
}
