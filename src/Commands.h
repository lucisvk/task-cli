#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>
#include "TaskManager.h"

class Commands
{
public:
    static void Help();
    static void Version();
    void Add(TaskManager& manager); 
};

#endif