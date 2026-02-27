#include "Commands.h"
#include <iostream>
#include "Time.h"

void Commands::Help()
{
    std::cout << R"(Tasks CLI v1.0
A lightweight terminal-based task manager.

Usage:
    tasks <command> [options]

Core Commands:
    add
        Create a new task.

    list
        Display all tasks.

    done <task_id>
        Mark a task as completed.

    delete <task_id>
        Permanently remove a task.

Utility Commands:
    help
        Show this help message.

    version
        Display CLI version information.
    
    Check_U
        Will check for any new versions of task-cli. 
)" << std::endl;
}

void Commands::Version()
{
    std::cout << "Tasks CLI Version 1.0\n";
}

void Commands::Add(TaskManager& manager)
{
    std::string desc, topic, dateStr, timeStr;

    std::cout << "Task description: ";
    std::getline(std::cin, desc);

    std::cout << "Task topic: ";
    std::getline(std::cin, topic);

    std::cout << "Task due date (MM/DD/YYYY): ";
    std::getline(std::cin, dateStr);

    std::cout << "Task due time (HH:MM 24-hour): ";
    std::getline(std::cin, timeStr);

  
    auto dueTime = Time::fromString(dateStr + " " + timeStr);

    manager.addTask(desc, topic, dueTime);

    std::cout << "Task added successfully!\n";
}