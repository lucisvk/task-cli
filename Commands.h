#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>
#include <chrono> 

class Commands {
    private: 
        std::string description; 
        std::string dateInput;
        std::string timeInput;
        std::string topic; 



public:
    static void Help();
    static void Version(); 
    static void Add(); 
};

#endif