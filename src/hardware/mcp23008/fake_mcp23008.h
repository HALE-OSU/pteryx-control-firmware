#pragma once

#include "mcp23008.h"

// These definitions allow us to use INPUT, OUTPUT, etc with our simulated
// module the exact same way we do with the real one that uses the Arduino
// library
#define INPUT 0
#define OUTPUT 1
#define INPUT_PULLUP 2
#define INPUT_PULLDOWN 3

class MCP23008 {
    // The number of digital output pins on the
    static const int NUM_PINS = 8;

   private:
    bool pinStates[NUM_PINS] = {0};

    /**
     * Ensures a number corresponds to a valid MCP23008 pin number
     * @returns true if the pin exists, false if not
     */
    bool validatePinNumber(uint8_t pin);

   public:
    void initialize(uint8_t address);
    void pinMode(uint8_t pin, uint8_t mode);
    void digitalWrite(uint8_t pin, bool state);
    bool digitalRead(uint8_t pin);

    /**
     * Used to check the current state of a pin for unit testing
     * @returns the current state an output pin is set to
     */
    bool checkPinState(uint8_t pin);
};
