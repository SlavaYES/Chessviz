#include <stdio.h>
#include "board.h"
#include <math.h>
#include <stdlib.h>
extern int n, m;

void swap(char *x, char *y)
{
    char temp = *x; *x = *y; *y = temp;
}

void eat(char *x, char *y)
{
    *y=*x; *x=' ';
}

int check(char chess[n][m], char *move_char, int *move_int, int flag)
{
    int i;
    move_int[0]=move_int[3]=0;
    for (i = 1; i < 6; i++) {
	switch (move_char[i]) {
	case 'a':
	case '1':
	    move_int[i] = 1;
	    break;

	case 'b':
	case '2':
	    move_int[i] = 2;
	    break;

	case 'c':
	case '3':
	    move_int[i] = 3;
	    break;

	case 'd':
	case '4':
	    move_int[i] = 4;
	    break;

	case 'e':
	case '5':
	    move_int[i] = 5;
	    break;
	
	case 'f':
	case '6':
	    move_int[i] = 6;
	    break;
	
	case 'g':
	case '7':
	    move_int[i] = 7;
	    break;
	
	case 'h':
	case '8':
	    move_int[i] = 8;
	    break;
	}
    }
    char temp_before = chess[move_int[2]][move_int[1]];
    char temp_after = chess[move_int[5]][move_int[4]];
    /*ПРОВЕРКА НА ЧЕРНОТУ*/
    //flag=1 this is white
    //flag=0 this is black
    //0 1 2 3 4 5
    //p e 2 - e 4
    if (flag) {
	if (temp_before >= 'A' && temp_before <= 'Z') {
	    if (temp_before == 'P' && move_char[0] == 'P') {
		if (move_char[3] == 'x' && temp_after != ' '
			&& abs(move_int[1]-move_int[4]) == 1
				&& move_int[2]-move_int[5] == 1) {
		    eat(&chess[move_int[2]][move_int[1]], &chess[move_int[5]][move_int[4]]);
		    return 1;
		}
		if ((move_int[1] == move_int[4] && move_int[2] > move_int[5]
			&& move_int[2]-move_int[5] == 1)
				|| (move_int[2]-move_int[5] == 2 && move_int[5] == 5)) {
		    if (move_char[3] == '-' && temp_after == ' ') {
			swap(&chess[move_int[2]][move_int[1]], 
				&chess[move_int[5]][move_int[4]]);
			return 1;
		    }
		}
	    }
	}
    } else {
	if (temp_before >= 'a' && temp_before <= 'z') {
	    if (temp_before == 'p' && move_char[0] == 'P') {

		if (move_char[3] == 'x' && temp_after != ' '
			&& abs(move_int[1]-move_int[4]) == 1
				&& move_int[5]-move_int[2] == 1) {
		    eat(&chess[move_int[2]][move_int[1]], &chess[move_int[5]][move_int[4]]);
		    return 1;
		}
		if ((move_int[1] == move_int[4] && move_int[2] < move_int[5]
			&& move_int[5]-move_int[2] == 1)
				|| (move_int[5]-move_int[2] == 2 && move_int[5] == 4)) {
				
		    if (move_char[3] == '-' && temp_after == ' ') {
			swap(&chess[move_int[2]][move_int[1]],
				&chess[move_int[5]][move_int[4]]);
			return 1;
		    }
		}
	    }
	}
    }
    return 0;
}
