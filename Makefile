CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
SRC = main.cpp Commands.cpp Time.cpp
TARGET = $(HOME)/bin/tasks

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
