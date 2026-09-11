#include "serial_logger.h"
#include <iostream>

#if ENV_TEST
#undef UNITY_INCLUDE_CONFIG_H
#include <unity.h>
#endif

void SerialLogger::setup() {
    // C++ iostream is automatically set up
}

void SerialLogger::blankLine() {
    std::cout << std::endl;
}

void SerialLogger::print(std::string text) {
    for (int i = 0; i < indentation; i++) {
        std::cout << "  ";
    }

    std::cout << text;
}

void SerialLogger::printLine(std::string text) {
    for (int i = 0; i < indentation; i++) {
        std::cout << "  ";
    }

    std::cout << text << std::endl;
}

void SerialLogger::printError(std::string text) {
    for (int i = 0; i < indentation; i++) {
        std::cerr << "  ";
    }

    std::cerr << "[ERROR]: " << text << std::endl;

#if ENV_TEST
    TEST_FAIL_MESSAGE(text.c_str());
#endif
}
