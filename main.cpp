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
        else if (command == "done") 
        {
            std::cout << "Which task would u like to mark as completed." << std::endl; 
            manager.listTasks();
            int taskId;
            std::string input;
            std::cout << "Option: ";
            std::getline(std::cin, input);
            try
            {
                taskId = std::stoi(input);
                manager.completeTask(taskId);
            }
            catch (const std::invalid_argument& e)
            {
                std::cout << "Invalid input. Please enter a valid task ID.\n";
            }
        }
        else if (command == "delete")
        {
            std::cout << "Which task would you like to delete?" << std::endl;
            manager.listTasks();
            std::string input;
            std::cout << "Option: "; 
            int taskId;
            std::getline(std::cin, input);
            try 
            {
               taskId = std::stoi(input); 
               manager.deleteTask(taskId); 
            } 
            catch (const std::invalid_argument& e)
            {
                std::cout << "Invalid input. Please enter a valid task ID.\n";
            }
          
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