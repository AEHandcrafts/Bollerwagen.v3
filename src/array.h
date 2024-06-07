#pragma once

template<typename T, unsigned long S>
class array {
  public:
  [[nodiscard]] constexpr unsigned long size() const {
    return S;
  }
  T &operator[](unsigned long index) {
    return this->data[index];
  }
  T data[S];
};
