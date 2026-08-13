#pragma once

#include "mcp23008.h"

class MCP23008 {
    static const int NUM_PINS = 8;

   private:
    uint8_t pinModes[NUM_PINS] = {2};
    bool pinStates[NUM_PINS] = {0};
    bool initialized = false;

    /** Ensures a number corresponds to a valid MCP23008 pin number */
    bool validatePinNumber(uint8_t pin);

    /** Ensures the initialize function has been called on the MCP23008  */
    bool validateInitialized();

    /** Ensures a pin has been configured to the proper mode */
    bool validatePinMode(uint8_t pin, uint8_t mode);

   public:
    void initialize(uint8_t address);
    void pinMode(uint8_t pin, uint8_t mode);
    void digitalWrite(uint8_t pin, bool state);
    bool digitalRead(uint8_t pin);

    /** Used to check the current state of a pin for unit testing */
    bool checkPinState(uint8_t pin);
};
