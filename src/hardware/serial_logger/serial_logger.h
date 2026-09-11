#pragma once
#include <string>

class SerialLogger {
   private:
    inline static int indentation = 0;

   public:
    static void setup();
    static void blankLine();
    static void print(std::string text);
    static void printLine(std::string text);
    static void printError(std::string text);

    static void addIndent() {
        indentation += 1;
    }

    static void removeIndent() {
        indentation -= 1;
    }
};