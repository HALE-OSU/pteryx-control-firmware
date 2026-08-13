#include "limit_switch_module.h"
#include "serial_logger/serial_logger.h"

void LimitSwitchModule::setup() {
    // TODO: call the ioExpander.initialize() function
    // TODO: setup pins for all 4 channels of the limit switch module

    // Example: configure pin 2 on the MCP23008 to be an INPUT
    ioExpander.pinMode(2, INPUT);
}

void LimitSwitchModule::loop() {
    // TODO: read and print all 4 channels of the limit switch module

    // Example: read the state of pin 2 on the MCP23008, then print it
    bool limitSwitchState = ioExpander.digitalRead(2);
    SerialLogger::print("The limit switch state is: ");
    SerialLogger::printLine(std::to_string(limitSwitchState));
}
