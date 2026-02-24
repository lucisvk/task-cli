CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
SRC = main.cpp src/Commands.cpp src/TaskManager.cpp src/Time.cpp
TARGET = $(HOME)/bin/tasks

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)