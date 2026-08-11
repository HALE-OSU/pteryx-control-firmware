#undef UNITY_INCLUDE_CONFIG_H
#include <unity.h>

#include "../../../src/modules/solenoid_module.h"

void setUp(void) {}
void tearDown(void) {}

SolenoidModule module;

void setup_module() {
    module.setup();
}

void run_module() {
    module.loop();
}

void solenoid_module_run_tests() {
    RUN_TEST(setup_module);
    RUN_TEST(run_module);
}

int main(void) {
    UNITY_BEGIN();
    solenoid_module_run_tests();
    return UNITY_END();
}