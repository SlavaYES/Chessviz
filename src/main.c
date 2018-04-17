#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conios.h"
#include "board_read.h"
#include "board_print_plain.h"
#include "board.h"

int n=9, m=9+1;

int main()
{
    char board[n][m];
    char step_char[7]="\0", exit=' ';
    int  step_int[6];
    int  color=1;//White is 1, Black is 0

    boardRead(board);
    do {
	outBoard(board, step_char);
	if (color) {
	    printf("Ход Белого: ");
	} else printf("Ход Черного: ");
	
	scanf("%s", step_char);
	
	if (check(board, step_char, step_int, color)) {
	    outBoard(board, step_char);
	    color=1-color;
	} else printf("Попробуйте еще раз.");
	printf("\nЗакончить игру?(yy/n): ");
	getch();
	exit=getch();
    } while (exit!='y');
    getch();
    return 0;
}












