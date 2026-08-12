#pragma once
#include <string>

class SerialLogger {
   private:
   public:
    static void printLine(std::string text);
    static void printError(std::string text);
};