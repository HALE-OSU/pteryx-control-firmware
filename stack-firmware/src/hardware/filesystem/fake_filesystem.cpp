#include "fake_filesystem.h"
#include "time/time.h"
#include "version_info.h"

std::ofstream Filesystem::dataLog = nullptr;
std::ofstream Filesystem::errorLog = nullptr;
std::ofstream Filesystem::crashReport = nullptr;

void Filesystem::initialize() {
    std::string timestamp = Time::getTimestampString();

    // Define the directory path
    std::string logDir = "simulation/logs/" + timestamp;

    // Create the full folder structure if it doesn't exist
    std::filesystem::create_directories(logDir);

    // Open the separate files inside the created folder
    Filesystem::dataLog = std::ofstream(logDir + "/data.txt");
    Filesystem::errorLog = std::ofstream(logDir + "/error_log.txt");
    Filesystem::crashReport = std::ofstream(logDir + "/crash_report.txt");

    std::ofstream metadata = std::ofstream(logDir + "/metadata.txt");
    metadata << "FIRMWARE VERSION: " << FIRMWARE_VERSION << std::endl;
    metadata << "FIRMWARE BUILD/UPLOAD DATE: " << FIRMWARE_BUILD_DATE
             << std::endl;
    metadata << "FIRMWARE BUILD/UPLOAD TIME: " << FIRMWARE_BUILD_TIME
             << std::endl;

    Filesystem::dataLog << "HELLO";
}

std::string Filesystem::loadConfiguration() {
    std::ifstream file("simulation_data/test.txt");
    if (!file.is_open()) return "";
    return std::string((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());
}

void Filesystem::logError(std::string message) {
    if (!errorLog.is_open()) return;

    Filesystem::errorLog << Time::getTimestampString() << " | " << message
                         << std::endl;
}
