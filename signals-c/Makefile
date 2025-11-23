# Makefile template
# Make sure to avoid unnecessary spaces

CC = gcc
CFLAGS = -g -Wall
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
PROJ_NAME = $(notdir $(CURDIR))

SRCS = $(wildcard $(INCLUDE_DIR)/*.h $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
BIN = $(BIN_DIR)/$(PROJ_NAME)

RM = rm
SUBMITNAME = $(PROJ_NAME).zip

all: $(BIN)

run:
	$(BIN)

release: CFLAGS=-Wall -O2 -DNDEBUG
release: clean
release: $(BIN)


$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -f -r $(BIN_DIR)/* $(OBJ_DIR)/*

submit:
	$(RM) $(SUBMITNAME)
	zip -r $(SUBMITNAME) ./

