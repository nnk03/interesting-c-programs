CC = gcc
CFLAGS = -g -Wall
RELEASE_FLAGS = -Wall -O2 -DNDEBUG
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
PROJECT = hello-world-open-code

.PHONY: all clean dirs run release submit

all: dirs $(BIN_DIR)/$(PROJECT)

dirs:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BIN_DIR)/$(PROJECT): $(OBJ_DIR)/main.o
	$(CC) $(OBJ_DIR)/main.o -o $@

run: all
	./$(BIN_DIR)/$(PROJECT)

release: CFLAGS = $(RELEASE_FLAGS)
release: all

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

submit:
	mkdir -p submission
	cp -r src include Makefile .gitignore submission/
	cd submission && tar -czf ../$(PROJECT).tar.gz *