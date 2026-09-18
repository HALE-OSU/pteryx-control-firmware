#include "time.h"

#include <chrono>
#include <format>
#include <iomanip>
#include <sstream>

std::string Time::getTimestampString() {
    // Get current time with system clock
    auto now = std::chrono::system_clock::now();

    // Get millisecond fraction of the current second
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                  now.time_since_epoch()) %
              1000;

    // Convert to time_t and then to tm struct
    auto timer = std::chrono::system_clock::to_time_t(now);
    std::tm bt = *std::localtime(&timer);

    // Format date and time
    std::ostringstream oss;
    oss << std::put_time(&bt, "%Y-%m-%d_%H-%M-%S");
    oss << '.' << std::setfill('0') << std::setw(3) << ms.count();

    return oss.str();
}

long long Time::getTimestampUnix() {
    // Get the current time point from the system clock
    auto now = std::chrono::system_clock::now();

    // Convert the time point to a duration since the epoch (Jan 1, 1970)
    auto duration = now.time_since_epoch();
    long long milliseconds =
        std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

    return milliseconds;
}