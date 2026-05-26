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

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: platform clean mkdir vector_unittest

vector_unittest: $(OBJ_DIR)/vector_unittest.o
	$(CC) $(CFLAGS) $^ -o $(OUT_DIR)/$@

.PHONY: platform clean mkdir test

platform:
	@echo "Detected PLATFORM: $(PLATFORM)"

test:
	$(OUT_DIR)/vector_unittest

mkdir:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OUT_DIR)

clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR)