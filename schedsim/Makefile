CC       := gcc
CFLAGS   := -Wall -Wextra -Iinclude -g
LDFLAGS  := 

SRC_DIR  := src
OBJ_DIR  := obj
BIN_NAME := schedsim

SRCS     := $(wildcard $(SRC_DIR)/*.c)
OBJS     := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(BIN_NAME)

build: all

$(BIN_NAME): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

PROCS    := "A:10:240,B:10:180,C:5:5"

runFCFS: all
	@./$(BIN_NAME) --algorithm=FCFS --processes=$(PROCS)

runSJF: all
	@./$(BIN_NAME) --algorithm=SJF --processes=$(PROCS)

runRR: all
	@./$(BIN_NAME) --algorithm=RR --processes=$(PROCS)

runSTCF: all
	@./$(BIN_NAME) --algorithm=STCF --processes=$(PROCS)

clean:
	@echo "removed object and program files"
	@rm -rf $(OBJ_DIR) $(BIN_NAME)

.PHONY: all build run runFCFS runSJF clean