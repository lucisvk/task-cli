#include <iostream>
#include <string> 
#include "Time.h"
#include "Commands.h"

int main() {
    Time now;
    std::cout << now.toString() << "\n";
    std::cout << "Welcome to task-cli enter --help to get a list of available commands." << std::endl;
    std::cout << "Enter exit to close the application." << std::endl; 
    Commands cmd; 
    std::string userin; 
    bool running = true; 

    while (running) {
        std::cin >> userin; 

        if (userin == "--help" ) { 
                cmd.Help();  
            } else if (userin == "-v") { 
                    cmd.Version(); 
            } else if (userin == "add") {
                    cmd.Add(); 
            } else if(userin == "exit") {
                    running = false;
            } else { 
                std::cout << "Please enter a valid option or enter --help for a list of commands." << std::endl; 
            }
    }

    return 0;
}

