#pragma once

#if defined(ENV_FAKE)
#include "fake_mcp23008.h"
#else
#include "real_mcp23008.h"
#endif