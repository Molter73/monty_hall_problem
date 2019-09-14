TARGET = ./build/game
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall -Iinc/

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst ./src/%.c, ./build/%.o, $(wildcard ./src/*.c))
HEADERS = $(wildcard ./inc/*.h)


build/%.o: src/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f ./build/*.o
	-rm -f $(TARGET)