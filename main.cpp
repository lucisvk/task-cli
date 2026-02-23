// g++ -std=c++17 main.cpp Time.cpp -o ~/bin/tasks
#include <iostream>
#include "Time.h"

int main() {
    Time now;
    std::cout << "Current time: " << now.toString() << "\n";
    

    return 0;
}