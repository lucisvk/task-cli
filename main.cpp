#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include "src/Commands.h"
#include "src/TaskManager.h"
#include "src/Time.h"

int getTaskIdFromUser(const std::string& prompt)
{
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);

    try
    {
        return std::stoi(input);
    }
    catch (const std::invalid_argument&)
    {
        std::cout << "Invalid input. Please enter a valid task ID.\n";
        return -1;
    }
    catch (const std::out_of_range&)
    {
        std::cout << "Input is too large. Please enter a valid task ID.\n";
        return -1;
    }
}

int main()
{
    TaskManager manager;
    Commands cmd;
    bool running = true;

    std::unordered_map<std::string, std::function<void()>> commandMap;

    commandMap["help"] = [&]() {
        Commands::Help();
    };

    commandMap["version"] = [&]() {
        Commands::Version();
    };

    commandMap["add"] = [&]() {
        cmd.Add(manager);
    };

    commandMap["list"] = [&]() {
        manager.listTasks();
    };

    commandMap["done"] = [&]() {
        
        if(manager.isEmpty() == true) { 
        std::cout << "No tasks available to mark as done.\n";
        return;

        }
        std::cout << "Which task would you like to mark as completed?\n";
        manager.listTasks();
        int taskId = getTaskIdFromUser("Option: ");
        if (taskId != -1)
        {
            manager.completeTask(taskId);
        }
    };

    commandMap["delete"] = [&]() {
        
        if(manager.isEmpty() == true) { 
            std::cout << "No tasks available to delete.\n";
            return;
        }

        std::cout << "Which task would you like to delete?\n";
        manager.listTasks();
        int taskId = getTaskIdFromUser("Option: ");
        if (taskId != -1)
        {
            manager.deleteTask(taskId);
        }
    };

    commandMap["exit"] = [&]() {
        std::cout << "Exiting TASK CLI. Goodbye!\n";
        running = false;
    };

    std::cout << "TASK-CLI v1.0\n";
    std::cout << "Type 'help' to see available commands.\n";

    while (running)
    {
        std::cout << "\ntasks> ";
        std::string command;
        std::getline(std::cin, command);

        if (command.empty())
            continue;

        auto it = commandMap.find(command);
        if (it != commandMap.end())
        {
            it->second();
        }
        else
        {
            std::cout << "Unknown command: " << command << "\n";
            std::cout << "Type 'help' to see available commands.\n";
        }
    }

    return 0;
}