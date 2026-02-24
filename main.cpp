#include <iostream>
#include <string>
#include "Commands.h"
#include "Time.h" 
#include "TaskManager.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "TASK-CLI START UP.\n";
        std::cout << "Type 'tasks help' for available commands.\n";
        return 0;
    }

    std::string command = argv[1];

    if (command == "help" || command == "-h" || command == "--help")
    {
        Commands::Help();
    }
    else if (command == "version" || command == "-v" || command == "--version")
    {
        Commands::Version();
    }
    else if (command == "add")
    {
        Commands cmd;   
        cmd.Add();
    }
    else
    {
        std::cout << "Unknown command: " << command << "\n";
        std::cout << "Type 'tasks help' to see available commands.\n";
    }

    return 0;
}