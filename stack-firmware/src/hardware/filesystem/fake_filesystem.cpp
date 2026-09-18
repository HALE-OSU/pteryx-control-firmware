#include "fake_filesystem.h"
#include "time/time.h"
#include "version_info.h"

std::ofstream Filesystem::dataLog = nullptr;
std::ofstream Filesystem::errorLog = nullptr;
std::string Filesystem::logDir = "";

void Filesystem::initialize() {
    std::string timestamp = Time::getTimestampString();

    // Define the directory path
    logDir = "simulation/logs/" + timestamp;

    // Create the log folder (and /logs/ directory) if it doesn't exist
    std::filesystem::create_directories(logDir);

    // Open the separate files inside the created folder
    dataLog = std::ofstream(logDir + "/data.csv");
    errorLog = std::ofstream(logDir + "/error_log.txt");

    // Log metadata
    std::ofstream metadata = std::ofstream(logDir + "/metadata.txt");
    metadata << "FIRMWARE VERSION: " << FIRMWARE_VERSION << std::endl;
    metadata << "FIRMWARE BUILT/UPLOADED: " << FIRMWARE_BUILD_DATE << " at "
             << FIRMWARE_BUILD_TIME << std::endl;
    metadata << "CODE EXECUTION TIME: " << timestamp << std::endl;
}

std::string Filesystem::loadConfiguration() {
    std::ifstream file("simulation_data/test.txt");
    if (!file.is_open()) return "";
    return std::string((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());
}

void Filesystem::logError(std::string message) {
    if (!errorLog.is_open()) return;

    errorLog << Time::getTimestampString() << " | " << message << std::endl;
}

void Filesystem::logCrash(std::string message) {
    std::ofstream crashReport = std::ofstream(logDir + "/crash_report.txt");

    if (!crashReport.is_open()) return;

    crashReport << Time::getTimestampString() << " | " << message << std::endl;

    crashReport.close();
}
