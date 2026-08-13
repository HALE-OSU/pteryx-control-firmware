#include "fake_mcp23008.h"
#include "serial_logger/serial_logger.h"

void MCP23008::initialize(uint8_t address) {}

void MCP23008::pinMode(uint8_t pin, uint8_t mode) {
    validatePinNumber(pin);
}

void MCP23008::digitalWrite(uint8_t pin, bool state) {
    // TODO: validate the pin number, then
}

bool MCP23008::digitalRead(uint8_t pin) {
    return false;  // TODO: remove this
}

bool MCP23008::checkPinState(uint8_t pin) {
    // TODO: remove this
}
