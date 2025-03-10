# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -std=c11 -g
# Output executable
TARGET = BlackJack
# Source and build directories
SRC_DIR = src
BUILD_DIR = build
# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
# Object files (store in build directory)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Default rule
all: $(TARGET)

# Link the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets to prevent conflicts with files named "clean" or "all"
.PHONY: all clean run
