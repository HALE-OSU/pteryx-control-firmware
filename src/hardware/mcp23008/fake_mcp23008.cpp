#undef UNITY_INCLUDE_CONFIG_H
#include <unity.h>

#include "fake_mcp23008.h"

bool MCP23008::validateInitialized() {
    if (!initialized) {
        TEST_FAIL_MESSAGE("MCP23008 used before initialize() was called");
        return false;
    }

    return true;
}

bool MCP23008::validatePinNumber(uint8_t pin) {
    if (pin < 0 || pin >= NUM_PINS) {
        TEST_FAIL_MESSAGE("MCP23008 pin number out of range");
        return false;
    }

    return true;
}

bool MCP23008::validatePinMode(uint8_t pin, uint8_t mode) {
    // Output
    if (mode == OUTPUT && pinModes[pin] == OUTPUT) {
        return true;
    }

    // Input (MCP23008 accepts INPUT or INPUT_PULLUP)
    if (mode == INPUT &&
        (pinModes[pin] == INPUT || pinModes[pin] == INPUT_PULLUP)) {
        return true;
    }

    TEST_FAIL_MESSAGE("MCP23008 pin mode mismatch for requested operation");
    return false;
}

void MCP23008::initialize(uint8_t address) {
    initialized = true;
}

void MCP23008::pinMode(uint8_t pin, uint8_t mode) {
    validatePinNumber(pin);
    validateInitialized();

    pinModes[pin] = mode;
}

void MCP23008::digitalWrite(uint8_t pin, bool state) {
    validatePinNumber(pin);
    validateInitialized();
    validatePinMode(pin, OUTPUT);

    pinStates[pin] = state;
}

bool MCP23008::digitalRead(uint8_t pin) {
    validatePinNumber(pin);
    validateInitialized();
    validatePinMode(pin, INPUT);

    return pinStates[pin];
}

bool MCP23008::checkPinState(uint8_t pin) {
    validatePinNumber(pin);
    validateInitialized();

    return pinStates[pin];
}
