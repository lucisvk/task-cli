#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>
#include "Commands.h"


void Commands::Add() 
{ 
    std::cout << "Enter The specification about your task." << std::endl; 

    std::string description; 
    std::string dateInput;
    std::string timeInput;
    std::string topic; 
    
    std::cout << "Please Enter the task description: " << std::endl;
    std::getline(std::cin, description);

    std::cout << "Please Enter the task due date MM/DD/YYYY: ";
    std::getline(std::cin, dateInput);
    
    std::cout << "Please Enter the time the task is due (HH:MM 24 hour format:) ";
    std::getline(std::cin, timeInput);

    std::cout << "Lastly Enter the task topic: ";
    std::getline(std::cin, topic);
    

    std::tm due = {};
    std::stringstream ss(dateInput + " " + timeInput);

    ss >> std::get_time(&due, "%m/%d/%Y %H:%M");

    if (ss.fail())
    {
        std::cout << "Invalid date/time format.\n";
        return;
    }

    time_t dueTime = std::mktime(&due);

    time_t now = std::time(nullptr);

    if (dueTime <= now)
    {
        std::cout << "This task is already overdue!\n";
    }

};






void Commands::Help()
{
    std::cout << R"(Tasks CLI v1.0
A lightweight terminal-based task manager.

Usage:
    tasks <command> [options]

Core Commands:

    add <task_name>
        Create a new task.
        Example:
            tasks add "Finish senior project"

    list
        Display all tasks with ID, status, and creation time.

    done <task_id>
        Mark a task as completed.
        Example:
            tasks done 3

    delete <task_id>
        Permanently remove a task.

    edit <task_id> "<new_name>"
        Update the task description.

    find "<keyword>"
        Search for tasks containing a keyword.

    clear
        Remove all completed tasks.

Utility Commands:

    help
        Show this help message.

    version
        Display CLI version information.

Options:

    -h, --help
        Show help menu.

    -v, --version
        Show version number.

    -f, --file <filename>
        Specify a custom task storage file.

Output Format Example:

    ID  Status   Created At              Task
    ---------------------------------------------------------
    1   [ ]      02/23/2026 07:15 PM     Finish CLI project
    2   [✓]      02/22/2026 03:41 PM     Apply to internship
)";
}

void Commands::Version() { 
    double Ver = 1.0; 
    std::cout << "You are running task-cli Version " << Ver << std::endl; 
}