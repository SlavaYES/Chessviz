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

int check(char chess[n][m], char *move_char, int flag)
{
    int i;
    int move_int[6];
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
	    /*PESHKA*/
	    if (temp_before == 'P') {
		/*EAT*/
		if (move_char[3] == 'x' && temp_after != ' '
			&& abs(move_int[1]-move_int[4]) == 1
				&& move_int[2]-move_int[5] == 1) {
		    eat(&chess[move_int[2]][move_int[1]], &chess[move_int[4]][move_int[5]]);
		    return 1;
		}
		/*MOVE*/
		if ((move_int[1] == move_int[4]
			&& move_int[2] > move_int[5]
				&& move_int[2]-move_int[5] == 1)
					|| (move_int[2]-move_int[5] == 2
						&& move_int[5] == 5
							&& move_char[3] == '-'
								&& temp_after == ' ')) {
		    swap(&chess[move_int[2]][move_int[1]],
			    &chess[move_int[5]][move_int[4]]);
		    return 1;
		}
	    }
	    /*HORSE*/
	    if (temp_before == 'N' && move_char[0] == 'N') {
		if ((abs(move_int[2]-move_int[5]) == 1
				&& abs(move_int[1]-move_int[4]) == 2)
					|| (abs(move_int[1]-move_int[4]) == 1
						&& abs(move_int[2]-move_int[5]) == 2)) {
		    /*EAT*/
		    if (move_char[3] == 'x' && temp_after != ' ') {
			eat(&chess[move_int[2]][move_int[1]], &chess[move_int[5]][move_int[4]]);
			return 1;
		    }
		    /*MOVE*/
		    if (move_char[3] == '-' && temp_after == ' ') {
			swap(&chess[move_int[2]][move_int[1]],
				&chess[move_int[5]][move_int[4]]);
			return 1;
		    }
		}
	    }
	    /*BISHOP*/
	    if (temp_before == 'B' && move_char[0] == 'B') {
		if (abs(move_int[2]-move_int[5]) == abs(move_int[1]-move_int[4])) {
		    /*EAT*/
		    if (move_char[3] == 'x' && temp_after != ' ') {
			eat(&chess[move_int[2]][move_int[1]], &chess[move_int[5]][move_int[4]]);
			return 1;
		}
		    /*MOVE*/
		    if (move_char[3] == '-' && temp_after == ' ') {
			swap(&chess[move_int[2]][move_int[1]],
				&chess[move_int[5]][move_int[4]]);
			return 1;
		    }
		}
	    }
	    /*ROOK*/
	    if (temp_before == 'R' && move_char[0] == 'R') {
		if (move_int[1] == move_int[4] || move_int[2] == move_int[5]) {
		    /*EAT*/
		    if (move_char[3] == 'x' && temp_after != ' ') {
			eat(&chess[move_int[2]][move_int[1]], &chess[move_int[5]][move_int[4]]);
			return 1;
		    }
		    /*MOVE*/
		    if (move_char[3] == '-' && temp_after == ' ') {
			swap(&chess[move_int[2]][move_int[1]],
				&chess[move_int[5]][move_int[4]]);
			return 1;
		    }
		}
	    }
	    /*KING*/
	    if (temp_before == 'K' && move_char[0] == 'K') {
		if ((abs(move_int[1]-move_int[4]) == 1
				|| abs(move_int[1]-move_int[4]) == 0)
					&& (abs(move_int[2]-move_int[5]) == 1
						|| abs(move_int[2]-move_int[5]) == 0)) {
		    /*EAT*/
		    if (move_char[3] == 'x' && temp_after != ' ') {
			eat(&chess[move_int[2]][move_int[1]], &chess[move_int[5]][move_int[4]]);
			return 1;
		    }
		    /*MOVE*/
		    if (move_char[3] == '-' && temp_after == ' ') {
			swap(&chess[move_int[2]][move_int[1]],
				&chess[move_int[5]][move_int[4]]);
			return 1;
		    }
		}
	    }
	    /*QUEEN*/
	    if (temp_before == 'Q' && move_char[0] == 'Q') {
		if (abs(move_int[2]-move_int[5]) == abs(move_int[1]-move_int[4])
			|| (move_int[1] == move_int[4] || move_int[2] == move_int[5])) {
		    /*EAT*/
		    if (move_char[3] == 'x' && temp_after != ' ') {
			eat(&chess[move_int[2]][move_int[1]], &chess[move_int[5]][move_int[4]]);
			return 1;
		    }
		    /*MOVE*/
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
	    /*PESHKA*/
	    if (temp_before == 'p' && move_char[0] == 'P') {
		/*EAT*/
		if (move_char[3] == 'x' && temp_after != ' '
			&& abs(move_int[1]-move_int[4]) == 1
				&& move_int[5]-move_int[2] == 1) {
		    eat(&chess[move_int[2]][move_int[1]], &chess[move_int[5]][move_int[4]]);
		    return 1;
		}
		/*MOVE*/
		if ((move_int[1] == move_int[4]
			&& move_int[2] < move_int[5]
				&& move_int[5]-move_int[2] == 1)
					|| (move_int[5]-move_int[2] == 2
						&& move_int[5] == 4
							&& move_char[3] == '-'
								&& temp_after == ' ')) {
		    swap(&chess[move_int[2]][move_int[1]],
			    &chess[move_int[5]][move_int[4]]);
		    return 1;
		}
	    }
	    /*HORSE*/
	    if (temp_before == 'n' && move_char[0] == 'N') {
		/*EAT*/
		if (move_char[3] == 'x' && temp_after != ' '
			&& ((abs(move_int[2]-move_int[5]) == 1
				&& abs(move_int[1]-move_int[4]) == 2)
					|| (abs(move_int[1]-move_int[4]) == 1
						&& abs(move_int[2]-move_int[5]) == 2))) {
		    eat(&chess[move_int[2]][move_int[1]], &chess[move_int[5]][move_int[4]]);
		    return 1;
		}
		/*MOVE*/
		if (move_char[3] == '-' && temp_after == ' '
			&& ((abs(move_int[2]-move_int[5]) == 1
				&& abs(move_int[1]-move_int[4]) == 2)
					|| (abs(move_int[1]-move_int[4]) == 1
						&& abs(move_int[2]-move_int[5]) == 2))) {
		    swap(&chess[move_int[2]][move_int[1]], 
				&chess[move_int[5]][move_int[4]]);
		    return 1;
		}
	    }
	    /*BISHOP*/
	    if (temp_before == 'b' && move_char[0] == 'B') {
		if (abs(move_int[2]-move_int[5]) == abs(move_int[1]-move_int[4])) {
		    /*EAT*/
		    if (move_char[3] == 'x' && temp_after != ' ') {
			eat(&chess[move_int[2]][move_int[1]], &chess[move_int[5]][move_int[4]]);
			return 1;
		}
		    /*MOVE*/
		    if (move_char[3] == '-' && temp_after == ' ') {
			swap(&chess[move_int[2]][move_int[1]],
				&chess[move_int[5]][move_int[4]]);
			return 1;
		    }
		}
	    }
	    /*ROOK*/
	    if (temp_before == 'r' && move_char[0] == 'R') {
		if (move_int[1] == move_int[4] || move_int[2] == move_int[5]) {
		    /*EAT*/
		    if (move_char[3] == 'x' && temp_after != ' ') {
			eat(&chess[move_int[2]][move_int[1]], &chess[move_int[5]][move_int[4]]);
			return 1;
		    }
		    /*MOVE*/
		    if (move_char[3] == '-' && temp_after == ' ') {
			swap(&chess[move_int[2]][move_int[1]],
				&chess[move_int[5]][move_int[4]]);
			return 1;
		    }
		}
	    }
	    /*KING*/
	    if (temp_before == 'k' && move_char[0] == 'K') {
		if ((abs(move_int[1]-move_int[4]) == 1
				|| abs(move_int[1]-move_int[4]) == 0)
					&& (abs(move_int[2]-move_int[5]) == 1
						|| abs(move_int[2]-move_int[5]) == 0)) {
		    /*EAT*/
		    if (move_char[3] == 'x' && temp_after != ' ') {
			eat(&chess[move_int[2]][move_int[1]], &chess[move_int[5]][move_int[4]]);
			return 1;
		    }
		    /*MOVE*/
		    if (move_char[3] == '-' && temp_after == ' ') {
			swap(&chess[move_int[2]][move_int[1]],
				&chess[move_int[5]][move_int[4]]);
			return 1;
		    }
		}
	    }
	    /*QUEEN*/
	    if (temp_before == 'q' && move_char[0] == 'Q') {
		if (abs(move_int[2]-move_int[5]) == abs(move_int[1]-move_int[4])
			|| (move_int[1] == move_int[4] || move_int[2] == move_int[5])) {
		    /*EAT*/
		    if (move_char[3] == 'x' && temp_after != ' ') {
			eat(&chess[move_int[2]][move_int[1]], &chess[move_int[5]][move_int[4]]);
			return 1;
		    }
		    /*MOVE*/
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
