CC = gcc

BUILD_DIR = ../build
INCLUDE_DIR = $(BUILD_DIR)/include
LIB_DIR = $(BUILD_DIR)

CFLAGS = -std=c99 -Wall -Wextra
LDFLAGS = -L$(LIB_DIR) -I$(INCLUDE_DIR) -lcce -Wl,-rpath,$(LIB_DIR) -lGL -lglfw -lm

test-window:
	$(CC) $@/main.c $(LDFLAGS) -o $@/$@.out
	$@/$@.out

test-pixel-grid:
	$(CC) $@/main.c $(LDFLAGS) -o $@/$@.out
	$@/$@.out

test-all: test-window test-pixel-grid

clean:
	rm -f test_window/test_*.out

.PHONY: clean test-all test-window test-pixel-grid