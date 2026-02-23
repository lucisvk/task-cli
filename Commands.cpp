#include <iostream>
#include "Commands.h"

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