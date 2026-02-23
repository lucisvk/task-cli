#pragma 
#ifndef TIME_H
#define TIME_H
#include <chrono>
#include <string>



class Time {
public:
    using TimePoint = std::chrono::system_clock::time_point;

    static TimePoint now();
    static std::string toString(const TimePoint& tp);
    static TimePoint fromString(const std::string& timeStr);
};

#endif