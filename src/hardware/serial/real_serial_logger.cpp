#ifdef ENV_TEENSY
#include "serial_logger.h"
#include "Arduino.h"

void SerialLogger::println(std::string text) {
    Serial.println(text.c_str());
}
#endif