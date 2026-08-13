#pragma once

#include "mcp23008/mcp23008.h"
#include "module.h"

class LimitSwitchModule : public Module {
   private:
    MCP23008 ioExpander;

   public:
    void setup() override;
    void loop() override;
};
