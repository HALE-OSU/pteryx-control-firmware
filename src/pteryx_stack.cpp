#include "pteryx_stack.h"
#include "serial_logger/serial_logger.h"

#include <ArduinoJson.h>

#include <iostream>
#include <fstream>
#include <string>

void PteryxStack::load_configuration() {
    SerialLogger::printLine("[Pteryx Stack]: Configuration Begin");
    SerialLogger::addIndent();

    std::ifstream file("test.txt");

    if (!file.is_open()) {
        std::cerr << "Failed to open file\n";
        return;
    }

    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());

    JsonDocument doc;
    // const char* json =
    //     "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]"
    //     "}";

    // Deserialize the JSON document
    DeserializationError error = deserializeJson(doc, content.c_str());

    // Test if parsing succeeds
    if (error) {
        SerialLogger::print("deserializeJson() failed: ");
        SerialLogger::print(error.c_str());
        return;
    }

    // Fetch the values
    //
    // Most of the time, you can rely on the implicit casts.
    // In other case, you can do doc["time"].as<long>();
    const char* sensor = doc["sensor"];
    long time = doc["time"];
    double latitude = doc["data"][0];
    double longitude = doc["data"][1];

    // Print the values
    SerialLogger::printLine(sensor);
    SerialLogger::printLine(std::to_string(time));
    SerialLogger::printLine(std::to_string(latitude));
    SerialLogger::printLine(std::to_string(longitude));

    SerialLogger::printLine("[Example Module 1]: Configuring");
    SerialLogger::printLine("[Example Module 2]: Configuring");

    SerialLogger::removeIndent();
    SerialLogger::printLine("[Pteryx Stack]: Configuration End");
}

void PteryxStack::loop() {
    SerialLogger::printLine("[Pteryx Stack]: Loop Begin");
    SerialLogger::addIndent();

    SerialLogger::printLine("[Example Module 1]: Updating");
    SerialLogger::printLine("[Example Module 2]: Updating");

    SerialLogger::removeIndent();
    SerialLogger::printLine("[Pteryx Stack]: Loop End");
}
