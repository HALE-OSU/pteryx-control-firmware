#ifdef ENV_FAKE
#include "serial_logger.h"
#include <iostream>

#if ENV_TEST
#undef UNITY_INCLUDE_CONFIG_H
#include <unity.h>
#endif

void SerialLogger::printLine(std::string text) {
    std::cout << text << std::endl;
}

void SerialLogger::printError(std::string text) {
    std::cout << "[ERROR]: " << text << std::endl;

#if ENV_TEST
    TEST_FAIL_MESSAGE(text.c_str());
#endif
}
#endif
