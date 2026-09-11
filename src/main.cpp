#ifdef ENV_TEENSY
#include <Arduino.h>
#endif

#include "serial_logger/serial_logger.h"
#include "pteryx_stack.h"

PteryxStack stack;

void setup() {
    stack.load_configuration();
}

void loop() {
    stack.loop();
}

#ifdef ENV_SIMULATE

// Libraries for adding a delay between loops
#include <thread>
#include <chrono>

/** The simulation environment has to manually call setup and loop in main() */
int main() {
    setup();

    while (1) {
        loop();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

#endif