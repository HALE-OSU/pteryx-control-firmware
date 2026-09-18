#include <cstdint>
#include <cstdlib>
#include <string>
#include <fstream>
#include <filesystem>

class Filesystem {
    static std::ofstream dataLog;
    static std::ofstream errorLog;

    static std::string logDir;

   public:
    static void initialize();

    static std::string loadConfiguration();

    // void logData(String data);
    // void logData(uint32_t moduleId, uint8_t* data, size_t dataLength);
    static void logError(std::string message);
    static void logCrash(std::string message);
};