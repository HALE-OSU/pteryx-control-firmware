#include "real_mcp23008.h"

void MCP23008::initialize(uint8_t address) {
    // TODO: Initialize the adafruitMcp23008 object
    // Hint adafruitMcp23008.being_I2C(address);
}

void MCP23008::pinMode(uint8_t pin, uint8_t mode) {
    // TODO: configure an MCP23008 pin
    // Hint: call adafruitMcp23008.pinMode()
}

void MCP23008::digitalWrite(uint8_t pin, bool state) {
    // TODO: Set a digital pin to either HIGH or LOW
}

bool MCP23008::digitalRead(uint8_t pin) {
    // TODO: Read the value of a pin (either HIGH or LOW) and return it
    return false;  // TODO: remove this
}