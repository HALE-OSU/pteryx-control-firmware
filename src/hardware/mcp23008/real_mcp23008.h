#pragma once

#include <Adafruit_MCP23X08.h>
#include "mcp23008.h"

class MCP23008 {
   private:
    Adafruit_MCP23X08 mcp;

   public:
    void initialize(uint8_t address);
    void pinMode(uint8_t pin, uint8_t mode);
    void digitalWrite(uint8_t pin, bool state);
    bool digitalRead(uint8_t pin);
};
