#Мой Макефайл
#Задаю компилятор
CC=gcc
#Задаю ключи компиляции
CFLAGS=-Wall -Werror -c

#Задаю путь src
SRC=src/

#Задаю путь build
dir=build/
#Задаю обьектные файлы
objects=$(dir)main.o $(dir)conios.o $(dir)board_read.o $(dir)board_print_plain.o $(dir)board.o

#Задаю путь bin
BIN=bin/
#Задаю испольняемый файл
EXECUTABLE=$(BIN)main

.PHONY: all clean

all: bin build $(EXECUTABLE)

$(EXECUTABLE): $(objects)
	$(CC) $(objects) -o $@

$(dir)main.o: $(SRC)main.c $(SRC)conios.h
	$(CC) $(CFLAGS) $(SRC)main.c -o $@


$(dir)board_print_plain.o: $(SRC)board_print_plain.c $(SRC)board_print_plain.h $(SRC)conios.h 
	$(CC) $(CFLAGS) $(SRC)board_print_plain.c -o $@

$(dir)conios.o: $(SRC)conios.c $(SRC)conios.h
	$(CC) $(CFLAGS) $(SRC)conios.c -o $@
	
$(dir)board_read.o: $(SRC)board_read.c $(SRC)board_read.h
	$(CC) $(CFLAGS) $(SRC)board_read.c -o $@
	

$(dir)board.o: $(SRC)board.c $(SRC)board.h
	$(CC) $(CFLAGS) $(SRC)board.c -o $@

build:
	mkdir build
bin:
	mkdir bin
src:
	mkdir src
clean:
	-rm -rf build bin/main
