#Мой Макефайл
#Задаю компилятор
CC=gcc
#Задаю ключи компиляции
CFLAGS= -Wall -Werror -c -std=c99
FLAGS= -Wall -Werror -std=c99
#Задаю путь src
SRC=src/

#Задаю путь build
dir=build/
dirt=buildt/
#Задаю обьектные файлы
objects=$(dir)main.o $(dir)conios.o $(dir)board_read.o $(dir)board_print_plain.o $(dir)board.o
objects_test=$(dirt)main_test.o $(dirt)conios.o $(dirt)board_read.o $(dirt)board_print_plain.o $(dirt)board.o
#Задаю путь bin
BIN=bin/
#Задаю испольняемый файл
EXECUTABLE=$(BIN)main

.PHONY: all clean default test

all: bin build buildt default test

default: $(EXECUTABLE)

test: $(BIN)main_test
	$(BIN)main_test

$(EXECUTABLE): $(objects)
	$(CC) $(FLAGS) $(objects) -o $@

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

$(BIN)main_test: $(objects_test)
	$(CC) $(FLAGS) $(objects_test) -o $@

$(dirt)main_test.o: test/main.c thirdparty/ctest.h $(SRC)board.h $(SRC)board_read.h $(SRC)board_print_plain.h $(SRC)conios.h
	$(CC) $(CFLAGS) -I thirdparty -I src -c test/main.c -o $@

$(dirt)board_print_plain.o: $(SRC)board_print_plain.c $(SRC)board_print_plain.h $(SRC)conios.h 
	$(CC) $(CFLAGS) $(SRC)board_print_plain.c -o $@

$(dirt)conios.o: $(SRC)conios.c $(SRC)conios.h
	$(CC) $(CFLAGS) $(SRC)conios.c -o $@
	
$(dirt)board_read.o: $(SRC)board_read.c $(SRC)board_read.h
	$(CC) $(CFLAGS) $(SRC)board_read.c -o $@
	

$(dirt)board.o: $(SRC)board.c $(SRC)board.h
	$(CC) $(CFLAGS) $(SRC)board.c -o $@

build:
	mkdir build
buildt:
	mkdir buildt
bin:
	mkdir bin
clean:
	-rm -rf build buildt bin/main