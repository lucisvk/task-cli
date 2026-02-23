#include "Time.h"
#include <iomanip>
#include <sstream>
#include <ctime>

// Default constructor = now
Time::Time() : timestamp(std::chrono::system_clock::now()) {}

// Constructor from TimePoint
Time::Time(const TimePoint& tp) : timestamp(tp) {}

// Getter
Time::TimePoint Time::getTimePoint() const {
    return timestamp;
}

// Convert stored timestamp to string in 12-hour format
std::string Time::toString() const {
    std::time_t t = std::chrono::system_clock::to_time_t(timestamp);
    std::tm* tmPtr = std::localtime(&t);

    int hour = tmPtr->tm_hour;
    std::string ampm = (hour >= 12) ? "PM" : "AM";
    hour = hour % 12;
    if (hour == 0) hour = 12; // midnight or noon = 12

    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << tmPtr->tm_mon + 1 << "/"  // month
        << std::setw(2) << tmPtr->tm_mday << "/"                          // day
        << tmPtr->tm_year + 1900 << " "
        << std::setw(2) << hour << ":"
        << std::setw(2) << tmPtr->tm_min << ":"
        << std::setw(2) << tmPtr->tm_sec << " "
        << ampm;

    return oss.str();
}

// Static: parse string into Time object
Time Time::fromString(const std::string& timeStr) {
    std::tm tm = {};
    std::istringstream iss(timeStr);

    // Expecting format "MM/DD/YYYY HH:MM:SS AM/PM"
    char slash1, slash2, colon1, colon2, space1;
    std::string ampm;
    iss >> tm.tm_mon >> slash1 >> tm.tm_mday >> slash2 >> tm.tm_year
        >> space1 >> tm.tm_hour >> colon1 >> tm.tm_min >> colon2 >> tm.tm_sec >> ampm;

    tm.tm_mon -= 1;       // months in tm are 0-11
    tm.tm_year -= 1900;   // years since 1900

    // Convert 12-hour to 24-hour
    if (ampm == "PM" && tm.tm_hour != 12) tm.tm_hour += 12;
    if (ampm == "AM" && tm.tm_hour == 12) tm.tm_hour = 0;

    std::time_t t = std::mktime(&tm);
    return Time(std::chrono::system_clock::from_time_t(t));
}