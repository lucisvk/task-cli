#include "Time.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>

Time::TimePoint Time::now()
{
    return std::chrono::system_clock::now();
}

std::string Time::toString(const TimePoint& tp)
{
    std::time_t t = std::chrono::system_clock::to_time_t(tp);
    std::tm tm = *std::localtime(&t);

    std::ostringstream oss;
    int hour = tm.tm_hour;
    std::string ampm = "AM";
    if (hour >= 12)
    {
        ampm = "PM";
        if (hour > 12) hour -= 12;
    }
    if (hour == 0) hour = 12;

    oss << std::setw(2) << std::setfill('0') << tm.tm_mon + 1 << "/"
        << std::setw(2) << std::setfill('0') << tm.tm_mday << "/"
        << tm.tm_year + 1900 << " "
        << std::setw(2) << std::setfill('0') << hour << ":"
        << std::setw(2) << std::setfill('0') << tm.tm_min << " " << ampm;

    return oss.str();
}

Time::TimePoint Time::fromString(const std::string& str)
{
    std::tm tm = {};
    std::istringstream ss(str);
    ss >> std::get_time(&tm, "%m/%d/%Y %H:%M");
    if (ss.fail())
    {
        std::cerr << "Failed to parse date/time. Using current time instead.\n";
        return now();
    }
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}