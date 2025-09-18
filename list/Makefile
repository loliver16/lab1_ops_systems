# list/Makefile
#
# Makefile for list implementation and test file.
#
# <Author>
list: list.c main.c
	gcc list.c main.c -o list

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11 -g

# Target executable
TARGET = list

# Source files
SRCS = list.c main.c

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Clean up object files and executable
clean:
	rm -f $(TARGET)
