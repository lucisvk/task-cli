# Makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
SRC = main.cpp Time.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = ~/bin/tasks

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CXX) $(CXXFLAGS) -o $@ $^

clean:
    rm -f *.o $(TARGET)