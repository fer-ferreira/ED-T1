CC = g++

IDIR = -I./src/include
CFLAGS = -Wall -std=c++14 $(IDIR)
LIBS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

OBJ = src/*.cpp src/model/*.cpp

OUT = bin/main

all: makeDir compile

%.o: $.c
	$(CC) -c -o  $@ $< $(CFLAGS)

makeDir:
	@mkdir bin -p

compile: $(OBJ)
	$(CC) -o $(OUT) $^ $(CFLAGS) $(LIBS)

run:
	@./$(OUT)
