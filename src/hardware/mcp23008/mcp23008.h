#pragma once

#include <cstdint>

#define INPUT 0
#define OUTPUT 1
#define INPUT_PULLUP 2
#define INPUT_PULLDOWN 3

class BASE_MCP23008 {
   private:
   public:
    virtual void initialize(uint8_t address) = 0;
    virtual void pinMode(uint8_t pin, uint8_t mode) = 0;
    virtual void digitalWrite(uint8_t pin, bool state) = 0;
    virtual bool digitalRead(uint8_t pin) = 0;
};