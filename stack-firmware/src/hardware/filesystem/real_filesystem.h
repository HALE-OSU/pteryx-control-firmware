#include <cstdint>
#include <cstdlib>

class Filesystem {
   public:
    void initialize();

    const char* loadConfiguration();

    // void logData(String data);
    // void logData(uint32_t moduleId, uint8_t* data, size_t dataLength);
};