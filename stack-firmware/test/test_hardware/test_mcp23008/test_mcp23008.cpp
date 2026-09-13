#undef UNITY_INCLUDE_CONFIG_H
#include <unity.h>

// #include "mcp23008/mcp23008.h"

void setUp(void) {}
void tearDown(void) {}

void example_passing_test(void) {
    TEST_ASSERT_EQUAL(1, 1);
}

void run_tests() {
    RUN_TEST(example_passing_test);
}

int main(void) {
    UNITY_BEGIN();
    run_tests();
    return UNITY_END();
}
