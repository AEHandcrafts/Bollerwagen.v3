#pragma once

template<typename T, uint32_t S>
class Array {
  public:
  [[nodiscard]] constexpr uint32_t size() const {
    return S;
  }
  T &operator[](uint32_t index) {
    return this->data[index];
  }
  T data[S];
};
