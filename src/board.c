#include <stdio.h>
#include "board.h"

extern int n, m;

void swap(char *x, char *y)
{
    char tmp=*x; *x=*y; *y=tmp;
}

int check(char a[n][m], char *xod, int *h, int flag)
{
    int i; 
    for (i=0; i<5; i++) {
	switch (xod[i]) {
	case 'a':
	case '1':
	    h[i]=1;
	    break;

	case 'b':
	case '2':
	    h[i]=2;
	    break;

	case 'c':
	case '3':
	    h[i]=3;
	    break;

	case 'd':
	case '4':
	    h[i]=4;
	    break;

	case 'e':
	case '5':
	    h[i]=5;
	    break;
	
	case 'f':
	case '6':
	    h[i]=6;
	    break;
	
	case 'g':
	case '7':
	    h[i]=7;
	    break;
	
	case 'h':
	case '8':
	    h[i]=8;
	    break;
	
	case '-':
	    h[2]=-1;
	    break;
	case 'x':
	    h[2]=-2;
	    break;
	}
    }
    char tmp0=a[h[1]][h[0]];
    char tmp1=a[h[4]][h[3]];
    /*ПРОВЕРКА НА ЧЕРНОТУ*/
    if (!flag) {
	if (tmp0>='A' && tmp0<='Z') {
	    if (tmp0=='P') {
		if (h[0]==h[3]) {
		    if (h[2]==-1 && tmp1==' ') {
			swap(&a[h[1]][h[0]], &a[h[4]][h[3]]);
			return 1;
		    }
		}
	    }
	}
    } else {
	if (tmp0>='a' && tmp0<='z') {
	    if (tmp0=='p') {
		if (h[0]==h[3]) {
		    if (h[2]==-1 && tmp1==' ') {
			swap(&a[h[1]][h[0]], &a[h[4]][h[3]]);
			return 1;
		    }
		}
	    }
	}
    }
    return 0;
}
