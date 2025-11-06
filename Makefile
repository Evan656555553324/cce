CC = gcc

SRCS = \
	src/engine/window/window.c \
	src/engine/init/init.c \
	src/engine/render/render.c \

INCLUDES = \
	-Isrc \
	-Isrc/engine \
	-Isrc/engine/window \
	-Isrc/engine/init \
	-Isrc/engine/render \

CFLAGS = -std=c99 -Wall -Wextra -fPIC

LIBS = -lglfw -lGL -lm

TARGET = libcce.so

BUILD_DIR = build

PUBLIC_HEADERS = src/cce.h

all: $(BUILD_DIR)/$(TARGET) install_headers

$(BUILD_DIR)/$(TARGET): $(SRCS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -shared -o $@ $(LIBS)

install_headers: | $(BUILD_DIR)/include
	cp $(PUBLIC_HEADERS) $(BUILD_DIR)/include/

test-window: all
	$(MAKE) -C examples test-window

test-pixel-grid: all
	$(MAKE) -C examples test-pixel-grid

test: all
	$(MAKE) -C examples test-all

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/include: | $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/include

clean:
	rm -rf $(BUILD_DIR)
	$(MAKE) -C examples clean

.PHONY: all clean install_headers test-window test-all