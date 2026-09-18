#pragma once

#ifdef ENV_FAKE
#include "fake_time.h"
#else
#include "real_time.h"
#endif