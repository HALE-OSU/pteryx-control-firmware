#ifdef ENV_TEENSY
#include "serial_logger.h"
#include "Arduino.h"

void SerialLogger::printLine(std::string text) {
    Serial.println(text.c_str());
}

void SerialLogger::printError(std::string text) {
    Serial.print("[ERROR]: ");
    Serial.println(text.c_str());
}
#endif