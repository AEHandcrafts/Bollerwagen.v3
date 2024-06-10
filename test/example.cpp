#include <unity.h>

void testA(void) {
  TEST_ASSERT_EQUAL(13, 13);
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(testA);
  return UNITY_END();
}
