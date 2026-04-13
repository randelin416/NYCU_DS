OS := $(shell uname)

ifeq ($(OS), Darwin)
    CC = clang++
else
    CC = g++
endif

# TODO 1: Fill in the compiler flags (include directory, c++11 standard)
CFLAGS := 

OUT_DIR := out
SRC_DIR := src
OBJ_DIR := obj

CPP_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(CPP_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%_c.o)

# TODO 2: Write the rule to compile .cpp files to .o files (Hint: use $(CC), $(CFLAGS), $<, $@)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	

all: mkdir mystack_unitest mycalculator_unitest main

# TODO 3: Fill in the dependent files for mystack_unitest
mystack_unitest: 
	$(CC) $(CFLAGS) $^ -o $(OUT_DIR)/$@

# TODO 4: Fill in the dependent files for mycalculator_unitest
mycalculator_unitest:  
	$(CC) $(CFLAGS) $^ -o $(OUT_DIR)/$@

# TODO 5: Fill in the dependent files for main executable
main: 
	$(CC) $(CFLAGS) $^ -o $(OUT_DIR)/$@

.PHONY: clean mkdir

mkdir:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OUT_DIR)

# TODO 6: Write the command to clean up the compiled files (remove obj and out directories)
clean: