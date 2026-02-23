#include <iostream>
#include "Time.h"  // <-- corrected

// g++ -std=c++17 main.cpp Time.cpp -o ~/bin/tasks


int main() {
    auto createdAt = Time::now();
    std::string formatted = Time::toString(createdAt);
    std::cout << "Created at: " << formatted << "\n";

    auto parsed = Time::fromString(formatted);
    std::cout << "Parsed again: " << Time::toString(parsed) << "\n";
}