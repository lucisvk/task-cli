# TASK-CLI

![C++](https://img.shields.io/badge/language-C%2B%2B-blue)

A lightweight **command-line task manager written in C++** that allows users to create, list, complete, and delete tasks directly from the terminal.

TASK-CLI was built to practice **object-oriented programming, CLI command handling, and modular C++ project architecture** while creating a simple productivity tool.

---

## Features

- Add new tasks
- View all tasks
- Mark tasks as completed
- Delete tasks
- Input validation for task selection
- Modular project structure
- Interactive command-line interface

---

## Example Usage

TASK-CLI v1.0
Type ‘help’ to see available commands.

tasks> add
Enter task title: Finish homework
Task added successfully.

tasks> list
	1.	Finish homework [Incomplete]

tasks> done
Which task would you like to mark as completed?
	1.	Finish homework [Incomplete]
Option: 1

tasks> list
	1.	Finish homework [Completed]

tasks> delete
Which task would you like to delete?
	1.	Finish homework [Completed]
Option: 1
---

## Available Commands

| Command | Description |
|------|------|
| `help` | Display available commands |
| `version` | Display CLI version |
| `add` | Add a new task |
| `list` | Display all tasks |
| `done` | Mark a task as completed |
| `delete` | Delete a task |
| `exit` | Exit the program |

---

