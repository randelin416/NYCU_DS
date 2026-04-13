OS := $(shell uname -s 2>/dev/null || echo Windows)

ifeq ($(OS), Linux)
    PLATFORM = linux
	CC = g++
endif

ifeq ($(OS), Darwin)
    PLATFORM = macos
	CC = clang++
endif

ifeq ($(OS), Windows)
	CC = g++
    ifdef ComSpec
        PLATFORM = windows-cmd
    endif
    ifdef PSModulePath
        PLATFORM = windows-powershell
    endif
endif

ifneq (,$(findstring MINGW, $(OS)))
    PLATFORM = windows-gitbash
endif

CFLAGS := -Iinclude -std=c++11
OUT_DIR := out
SRC_DIR := src
OBJ_DIR := obj

CPP_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(CPP_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%_c.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@


all: platform clean mkdir bst_unittest main

bst_unittest: $(OBJ_DIR)/BinarySearchTree.o $(OBJ_DIR)/bst_unittest.o
	$(CC) $(CFLAGS) $^ -o $(OUT_DIR)/$@

main: $(OBJ_DIR)/BinarySearchTree.o $(OBJ_DIR)/main.o
	$(CC) $(CFLAGS) $^ -o $(OUT_DIR)/$@

.PHONY: platform clean mkdir test run

platform:
	@echo "Detected PLATFORM: $(PLATFORM)"

run:
	$(OUT_DIR)/main

test:
	$(OUT_DIR)/bst_unittest

mkdir:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OUT_DIR)

clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR)
