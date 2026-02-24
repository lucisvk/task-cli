#include "TaskManager.h"
#include "Time.h"
#include <iostream>
#include <iomanip>

void TaskManager::addTask(const std::string& desc, const std::string& topic,
                          std::chrono::system_clock::time_point dueTime)
{
    Task t;
    t.id = nextId++;
    t.description = desc;
    t.topic = topic;
    t.dueTime = dueTime;
    t.completed = false;

    tasks.push_back(t);
}

void TaskManager::listTasks() const
{
    if (tasks.empty())
    {
        std::cout << "No tasks found.\n";
        return;
    }

    std::cout << "ID  Status  Due Date & Time           Topic          Description\n";
    std::cout << "---------------------------------------------------------------\n";

    for (const auto& t : tasks)
    {
        std::cout << t.id << "   "
                  << (t.completed ? "[✓]" : "[ ]") << "   "
                  << Time::toString(t.dueTime) << "   "
                  << t.topic << "   "
                  << t.description << "\n";
    }
}

void TaskManager::completeTask(int id)
{
    for (auto& t : tasks)
    {
        if (t.id == id)
        {
            t.completed = true;
            std::cout << "Task " << id << " marked completed.\n";
            return;
        }
    }
    std::cout << "Task " << id << " not found.\n";
}

void TaskManager::deleteTask(int id)
{
    for (auto it = tasks.begin(); it != tasks.end(); ++it)
    {
        if (it->id == id)
        {
            tasks.erase(it);
            std::cout << "Task " << id << " deleted.\n";
            return;
        }
    }
    std::cout << "Task " << id << " not found.\n";
}