#include "serial_logger.h"
#include "Arduino.h"

void SerialLogger::setup() {
    Serial.begin(9600);
}

void SerialLogger::blankLine() {
    Serial.println("");
}

void SerialLogger::print(std::string text) {
    for (int i = 0; i < indentation; i++) {
        Serial.print("  ");
    }

    Serial.print(text.c_str());
}

void SerialLogger::printLine(std::string text) {
    for (int i = 0; i < indentation; i++) {
        Serial.print("  ");
    }

    Serial.println(text.c_str());
}

void SerialLogger::printError(std::string text) {
    for (int i = 0; i < indentation; i++) {
        Serial.print("  ");
    }

    Serial.print("[ERROR]: ");
    Serial.println(text.c_str());
}