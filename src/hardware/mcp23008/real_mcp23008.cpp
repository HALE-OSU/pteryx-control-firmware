#include "real_mcp23008.h"

void MCP23008::initialize(uint8_t address) {
    mcp.begin_I2C(address);
}

void MCP23008::pinMode(uint8_t pin, uint8_t mode) {
    mcp.pinMode(pin, mode);
}

void MCP23008::digitalWrite(uint8_t pin, bool state) {
    mcp.digitalWrite(pin, state);
}

bool MCP23008::digitalRead(uint8_t pin) {
    return mcp.digitalRead(pin);
}