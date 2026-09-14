#pragma once

#ifdef ENV_FAKE
#include "fake_filesystem.h"
#else
#include "real_filesystem.h"
#endif
