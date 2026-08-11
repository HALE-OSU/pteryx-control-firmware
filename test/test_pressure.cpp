#undef UNITY_INCLUDE_CONFIG_H
#include <unity.h>

#include "../src/pt.h"

void setUp(void) {}
void tearDown(void) {}

void example_passing_test(void) {
    TEST_ASSERT_EQUAL(0, analogInputToVoltage(0));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(example_passing_test);
    return UNITY_END();
}