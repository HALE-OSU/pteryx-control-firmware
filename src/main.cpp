#ifdef ENV_TEENSY
#include <Arduino.h>
#endif

#include "modules/solenoid_module.h"
#include "hardware/serial/serial_logger.h"

void setup() {}

void loop() {
    SerialLogger::printLine("Hello, World");
}

#ifdef ENV_SIMULATE
int main() {
    setup();

    while (1) {
        loop();
    }
}
#endif