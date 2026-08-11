#if defined(ENV_TEENSY)
#include <Arduino.h>
#include "pt.h"
#include "modules/solenoid_module.h"

void setup() {
    analogInputToVoltage(0);
}

void loop() {}
#endif