#pragma once

// Provides the uint8_t type, which is an 8 bit unsigned integer (a whole number
// 0-255). This is commonly used for pin numbers and configuration modes where
// large or negative numbers are not needed
#include <cstdint>

#ifdef ENV_FAKE
#include "fake_mcp23008.h"
#else
#include "real_mcp23008.h"
#endif