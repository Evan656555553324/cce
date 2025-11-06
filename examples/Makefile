# Compiler
CC = gcc

# Build directory (from root)
BUILD_DIR = ../build
INCLUDE_DIR = $(BUILD_DIR)/include
LIB_DIR = $(BUILD_DIR)

# Compiler flags for tests
CFLAGS = -std=c99 -Wall -Wextra
LDFLAGS = -L$(LIB_DIR) -I$(INCLUDE_DIR) -lcce -Wl,-rpath,$(LIB_DIR) -lGL -lglfw

# Test targets
test-window:
	$(CC) test_window/main.c $(LDFLAGS) -o $(BUILD_DIR)/test_window.out
	$(BUILD_DIR)/test_window.out

# Run all tests
test-all: test-window test-glfw-only test-minimal

# Clean test binaries
clean:
	rm -f $(BUILD_DIR)/test_*.out

.PHONY: test-window test-glfw-only test-minimal test-all clean