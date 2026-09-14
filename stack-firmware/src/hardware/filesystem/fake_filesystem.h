#include <cstdint>
#include <cstdlib>
#include <string>

class Filesystem {
   public:
    void initialize();

    std::string loadConfiguration();

    // void logData(String data);
    // void logData(uint32_t moduleId, uint8_t* data, size_t dataLength);
};