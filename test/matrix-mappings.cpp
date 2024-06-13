#include <unity.h>

#include "matrix-mappings.h"

void testMapBottomRightZigzag(void) {
  auto WIDTH = 37, HEIGHT = 9;
  TEST_ASSERT_EQUAL(332, mapBottomRightZigzag(0, 0, WIDTH, HEIGHT));
  TEST_ASSERT_EQUAL(296, mapBottomRightZigzag(36, 0, WIDTH, HEIGHT));
  TEST_ASSERT_EQUAL(36, mapBottomRightZigzag(0, 8, WIDTH, HEIGHT));
  TEST_ASSERT_EQUAL(0, mapBottomRightZigzag(36, 8, WIDTH, HEIGHT));
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(testMapBottomRightZigzag);
  return UNITY_END();
}
