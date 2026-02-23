#ifndef TIME_H
#define TIME_H

#include <chrono>
#include <string>

class Time {
public:
    using TimePoint = std::chrono::system_clock::time_point;

private:
    TimePoint timestamp; // The stored date/time

public:
    // Constructors
    Time(); // default = current time
    Time(const TimePoint& tp); // initialize with a specific time

    // Getters
    TimePoint getTimePoint() const;

    // Convert this Time to string
    std::string toString() const;

    // Static helper to convert string to Time object
    static Time fromString(const std::string& timeStr);
};

#endif