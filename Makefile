#Мой Макефайл
#Задаю компилятор
CC=gcc
#Задаю ключи компиляции
CFLAGS=-Wall -Werror -c

#Задаю путь src
SRC=src/
#Задаю исходники файлы
SOURCES=$(SRC)main.c $(SRC)conios.c

#Задаю путь build
dir=build/
#Задаю обьектные файлы
objects=$(dir)main.o $(dir)conios.o

#Задаю путь bin
BIN=bin/
#Задаю испольняемый файл
EXECUTABLE=$(BIN)main

#Задаю путь include
INCLUDE= -MM -I./include

all: bin build $(BIN)main

$(EXECUTABLE): $(objects)
	$(CC) $(objects) -o $@

$(dir)main.o: $(SRC)main.c $(SRC)conios.h
	$(CC) $(CFLAGS) $(SRC)main.c -o $@

$(dir)conios.o: $(SRC)conios.c $(SRC)conios.h
	$(CC) $(CFLAGS) $(SRC)conios.c -o $@

build:
	mkdir build
bin:
	mkdir bin
src:
	mkdir src
clean:
	-rm -rf build bin
