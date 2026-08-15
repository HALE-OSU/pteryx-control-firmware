#undef UNITY_INCLUDE_CONFIG_H
#include <unity.h>

#include "pt_calculations.h"

void setUp(void) {}
void tearDown(void) {}

void test_current_to_pressure() {
    // All zeros
    TEST_ASSERT_EQUAL(0.0, currentToPressure(0, 0, 0));

    // Linear only
    TEST_ASSERT_EQUAL(11.5, currentToPressure(2.3, 5, 0));

    // Constant only
    TEST_ASSERT_EQUAL(0.01, currentToPressure(14.3, 0, 0.01));

    // Varius others
    TEST_ASSERT_EQUAL(12.0048, currentToPressure(0.002, 2.4, 12));
    TEST_ASSERT_EQUAL(-995.3, currentToPressure(1, 4.7, -1000));
    TEST_ASSERT_EQUAL(57.44, currentToPressure(15.2, -2.8, 100));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_current_to_pressure);
    return UNITY_END();
}