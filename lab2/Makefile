.PHONY: all run clean

# Detect c++, otherwise c
SRC_CPP = $(wildcard main.cpp)
BIN_PATH = ../bin

ifneq ($(SRC_CPP),)
	SRC = main.cpp
	CC = g++
else
	SRC = main.c
	CC = gcc
endif

all:
	$(CC) $(SRC) -o $(BIN_PATH)/main

run: all
	./$(BIN_PATH)/main

clean:
	rm -rf $(BIN_PATH)
