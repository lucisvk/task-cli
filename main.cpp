// g++ -std=c++17 main.cpp Time.cpp -o ~/bin/tasks
#include <iostream>
#include <string> 
#include "Time.h"
#include "Commands.h"

int main() {
    Time now;
    std::cout << now.toString() << "\n";
    std::cout << "Welcome to task-cli enter --help to get a list of available commands." << std::endl;

    Commands cmd; 
    std::string userin; 
    std::cin >> userin; 
    if (userin == "--help" ) { 
            cmd.Help();  

    } else if (userin == "-v") { 
            cmd.Version(); 
    } else { 
        std::cout << "Please enter a valid option or enter --help for a list of commands."; 
    }

    return 0;
}

