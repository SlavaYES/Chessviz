#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conios.h"

const int n=9, m=9+1;

void swap(char *x, char *y);
void outBoard(char a[n][m], char *);
int check(char a[n][m], char *, int *, int);


int main()
{
    char a[n][m];
    int i;
    FILE *lone;
    
    lone=fopen("Chess.txt", "r");
    a[0][0]='\0';
    i=1;
    while (!feof(lone)) {
	fread(a[i], sizeof(a[1]), 1, lone);
	i++;
    }
    fclose(lone);
    
    char xod[6]="\0", ch='\0';
    int h[5];
    int flag=0;//Флаг 0- Белый, Флаг 1- Черный
    
    do {
	outBoard(a, xod);
	if (flag) {
	    printf("Ход Черного: ");
	} else printf("Ход Белого: ");
	scanf("%s", xod);
    
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
	if (check(a, xod, h, flag)) {
	    outBoard(a, xod);
	    flag=1-flag;
	} else printf("Попробуйте еще раз.");
	printf("\nЗакончить игру?(yy/n): ");
	getch();
	ch=getch();
    } while (ch!='y');
    getch();
    return 0;
}

void swap(char *x, char *y)
{
    char tmp=*x; *x=*y; *y=tmp;
}

void outBoard(char a[n][m], char *xod)
{
    int i, j;
    printf("\n");
    clrscr();
    printf("Предыдущий Ход:"); puts(xod);
    printf("    A B C D E F G H\n\n");
    for (i=1; i<n; i++) {
	printf("\x1b[0m%d", i);
	for (j=0; j<m; j++) {
	    if (a[i][j]>='A' && a[i][j]<='Z') printf("\x1b[37m");
		else printf("\x1b[30m");
	    printf("%2c", a[i][j]);
	}
    }
    printf("\x1b[0m\n");
}

int check(char a[n][m], char *xod, int *h, int flag)
{
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













