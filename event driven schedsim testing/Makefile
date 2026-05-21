# Compiler and Flags
CC       := gcc
CFLAGS   := -Wall -Wextra -Iinclude -g
LDFLAGS  := 

# Directories and Names
SRC_DIR  := src
OBJ_DIR  := obj
BIN_NAME := schedsim

# Find all source files in src/ (based on image_9d6aa2.png)
SRCS     := $(wildcard $(SRC_DIR)/*.c)
OBJS     := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Testing
PROCS    := "A:0:240,B:10:180,C:20:150"

all: $(BIN_NAME)

build: all

# Link the executable
$(BIN_NAME): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# --- Execution Targets ---

run: all
	@./$(BIN_NAME) --algorithm= --processes=$(PROCS)

runFCFS: all
	@./$(BIN_NAME) --algorithm=FCFS --processes=$(PROCS)

runSJF: all
	@./$(BIN_NAME) --algorithm=SJF --processes=$(PROCS)

# runTest: all
# 	@./lab1 tester.txt

# --- Maintenance ---

clean:
	@echo "removed object and program files"
	@rm -rf $(OBJ_DIR) $(BIN_NAME)

.PHONY: all build run runFCFS runSJF clean