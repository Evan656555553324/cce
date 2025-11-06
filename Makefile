# Compiler
CC = gcc

# Source files
SRCS = \
	src/engine/window/window.c \
	src/engine/init/init.c \

# Include directories
INCLUDES = \
	-Isrc \
	-Isrc/engine \
	-Isrc/engine/window \
	-Isrc/engine/init

# Compiler flags
CFLAGS = -std=c99 -Wall -Wextra -fPIC

# Libraries
LIBS = -lglfw -lGL

# Project name
TARGET = libcce.so

# Build directory
BUILD_DIR = build

# Public headers to copy
PUBLIC_HEADERS = src/cce.h

# Default target - build shared library and install headers
all: $(BUILD_DIR)/$(TARGET) install_headers

# Create shared library
$(BUILD_DIR)/$(TARGET): $(SRCS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -shared -o $@ $(LIBS)

# Install public headers to build/include
install_headers: | $(BUILD_DIR)/include
	cp $(PUBLIC_HEADERS) $(BUILD_DIR)/include/

# Delegate test commands to examples/Makefile
test-window: all
	$(MAKE) -C examples test-window

test: all
	$(MAKE) -C examples test-all

# Create build directories
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/include: | $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/include

# Clean (including examples)
clean:
	rm -rf $(BUILD_DIR)
	$(MAKE) -C examples clean

.PHONY: all clean install_headers test-window test-all