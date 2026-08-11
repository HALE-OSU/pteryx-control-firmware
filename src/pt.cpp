
#include "pt.h"

float analogInputToVoltage(int input) {
    // Divide by 4096 to scale between 0 and 1
    // Multipy by 3.3 to scale between 0V and 3.3V
    return (input / 4096.0f) * 3.3f;
}