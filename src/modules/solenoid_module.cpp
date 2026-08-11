#include "solenoid_module.h"

void SolenoidModule::setup() {
    ioExpander.initialize(12);
    ioExpander.pinMode(2, INPUT);
}

void SolenoidModule::loop() {
    // Example: actuate solenoid on MCP23008 pin 2
    ioExpander.digitalWrite(2, true);
}
