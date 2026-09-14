#include "real_filesystem.h"

#include <fstream>

void Filesystem::initialize() {}

const char* Filesystem::loadConfiguration() {
    std::ifstream file("simulation_data/test.txt");

    if (!file.is_open()) {
        // std::cerr << "Failed to open file\n";
        // TODO: error
        return;
    }

    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());

    return content.c_str();
}
