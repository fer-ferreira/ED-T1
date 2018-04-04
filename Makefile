CC = g++

IDIR = -I./src/include
CFLAGS = -Wall $(IDIR)

OBJ = src/*.cpp src/model/*.cpp

OUT = bin/main

all: makeDir compile

%.o: $.c
	$(CC) -c -o  $@ $< $(CFLAGS)

makeDir:
	@mkdir bin -p

compile: $(OBJ)
	$(CC) -o $(OUT) $^ $(CFLAGS)

run:
	@./$(OUT)
