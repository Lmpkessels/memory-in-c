# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Source files
SRCS = src/malloc.c tests/test_malloc.c

# Output executable
TARGET = test_malloc

# Default target
all: $(TARGET)

# How to build the executable
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Clean generated files
clean:
	rm -f $(TARGET)