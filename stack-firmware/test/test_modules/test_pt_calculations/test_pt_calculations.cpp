#undef UNITY_INCLUDE_CONFIG_H
#include <unity.h>

#include "pt_calculations.h"

void setUp(void) {}
void tearDown(void) {}

void test_current_to_pressure() {
    // All zeros (example)
    TEST_ASSERT_EQUAL(0.0, currentToPressure(0, 0, 0));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_current_to_pressure);
    return UNITY_END();
}