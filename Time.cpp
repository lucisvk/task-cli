#include "Time.h"
#include <iomanip>
#include <sstream>
#include <ctime>

Time::TimePoint Time::now() {
    return std::chrono::system_clock::now();
}

std::string Time::toString(const TimePoint& tp) {
    std::time_t t = std::chrono::system_clock::to_time_t(tp);
    std::tm* tmPtr = std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(tmPtr, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

Time::TimePoint Time::fromString(const std::string& timeStr) {
    std::tm tm = {};
    std::istringstream iss(timeStr);
    iss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");

    std::time_t t = std::mktime(&tm);
    return std::chrono::system_clock::from_time_t(t);
}