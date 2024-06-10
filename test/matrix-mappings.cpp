#include <unity.h>

#include "matrix-mappings.h"

void testMapBottomRightZigzag(void) {
  auto WIDTH = 10, HEIGHT = 10;
  TEST_ASSERT_EQUAL(90, mapBottomRightZigzag(0, 0, WIDTH, HEIGHT));
  TEST_ASSERT_EQUAL(99, mapBottomRightZigzag(9, 0, WIDTH, HEIGHT));
  TEST_ASSERT_EQUAL(9, mapBottomRightZigzag(0, 9, WIDTH, HEIGHT));
  TEST_ASSERT_EQUAL(0, mapBottomRightZigzag(9, 9, WIDTH, HEIGHT));

  TEST_ASSERT_EQUAL(16, mapBottomRightZigzag(6, 8, WIDTH, HEIGHT));
  TEST_ASSERT_EQUAL(3, mapBottomRightZigzag(6, 9, WIDTH, HEIGHT));

  TEST_ASSERT_EQUAL(7, mapBottomRightZigzag(2, 9, WIDTH, HEIGHT));
  TEST_ASSERT_EQUAL(12, mapBottomRightZigzag(2, 8, WIDTH, HEIGHT));

  TEST_ASSERT_EQUAL(74, mapBottomRightZigzag(4, 2, WIDTH, HEIGHT));
  TEST_ASSERT_EQUAL(31, mapBottomRightZigzag(1, 6, WIDTH, HEIGHT));
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(testMapBottomRightZigzag);
  return UNITY_END();
}
