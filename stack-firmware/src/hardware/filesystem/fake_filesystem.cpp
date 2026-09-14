#include "fake_filesystem.h"

#include <fstream>

void Filesystem::initialize() {}

std::string Filesystem::loadConfiguration() {
    std::ifstream file("simulation_data/test.txt");
    if (!file.is_open()) return "";
    return std::string((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());
}
