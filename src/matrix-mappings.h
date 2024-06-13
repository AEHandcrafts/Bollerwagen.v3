#pragma once

inline uint32_t mapBottomRightZigzag(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
  uint32_t row = height - 1 - y;
  uint32_t col = (row % 2 == 0) ? (width - 1 - x) : x;
  return row * width + col;
}
