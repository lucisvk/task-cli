#include <iostream>
#include <string>
#include "src/Commands.h"
#include "src/TaskManager.h"
#include "src/Time.h"

int main()
{
    TaskManager manager;

    std::cout << "TASK-CLI v1.0\n";
    std::cout << "Type 'help' to see available commands.\n";

    while (true)
    {
        std::cout << "\ntasks> ";
        std::string command;
        std::getline(std::cin, command);

        if (command.empty())
            continue; // ignore empty input

        if (command == "help")
        {
            Commands::Help();
        }
        else if (command == "version")
        {
            Commands::Version();
        }
        else if (command == "add")
        {
            Commands cmd;
            cmd.Add(manager); 
        }
        else if (command == "list")
        {
            manager.listTasks();
        }
        else if (command.rfind("done ", 0) == 0) 
        {
            int taskId = std::stoi(command.substr(5));
            manager.completeTask(taskId);
        }
        else if (command.rfind("delete ", 0) == 0) 
        {
            int taskId = std::stoi(command.substr(7));
            manager.deleteTask(taskId);
        }
        else if (command == "exit")
        {
            std::cout << "Exiting TASK CLI. Goodbye!\n";
            break;
        }
        else
        {
            std::cout << "Unknown command: " << command << "\n";
            std::cout << "Type 'help' to see available commands.\n";
        }
    }

    return 0;
}