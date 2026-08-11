#pragma once

#if defined(ENV_NATIVE)
#include "../hardware/mcp23008/fake_mcp23008.h"
#else
#include "../hardware/mcp23008/real_mcp23008.h"
#endif

class SolenoidModule {
   private:
    MCP23008 ioExpander;

   public:
    void setup();
    void loop();
};