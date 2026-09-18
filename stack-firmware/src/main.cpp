#ifdef ENV_TEENSY
#include <Arduino.h>
#endif

#include "pteryx_stack.h"
#include "networking/network_controller.h"

#include "time/time.h"

PteryxStack stack;
NetworkController networkController;

void setup() {
    stack.load_configuration();
    printf("%s\n", Time::getTimestampString());
    networkController.setup();
}

void loop() {
    stack.loop();
    networkController.loop();
    networkController.sendCommand(-1, (uint8_t)1);
}

#ifdef ENV_SIMULATE

// Libraries for adding a delay between loops
#include <thread>
#include <chrono>

/** The simulation environment has to manually call setup and loop in main()
 */
int main() {
    setup();

    while (1) {
        loop();

        // Delay between loop runs
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

#endif
