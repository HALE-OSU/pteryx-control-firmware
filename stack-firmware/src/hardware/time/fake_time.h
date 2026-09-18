#pragma once

#include <string>

class Time {
   public:
    static std::string getTimestampString();
    static long long getTimestampUnix();
};