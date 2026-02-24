#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <string>
#include <vector>
#include <chrono>

struct Task
{
    int id;
    std::string description;
    std::string topic;
    std::chrono::system_clock::time_point dueTime;
    bool completed = false;
};

class TaskManager
{
private:
    std::vector<Task> tasks;
    int nextId = 1;

public:
    void addTask(const std::string& desc, const std::string& topic,
                 std::chrono::system_clock::time_point dueTime);
    void listTasks() const;
    void completeTask(int id);
    void deleteTask(int id);
};

#endif