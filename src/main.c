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
    char a[n][m];
    bread(a);
    char xod[6]="\0", ch='\0';
    int h[5];
    int flag=0;//Флаг 0- Белый, Флаг 1- Черный
    
    do {
	outBoard(a, xod);
	if (flag) {
	    printf("Ход Черного: ");
	} else printf("Ход Белого: ");
	
	scanf("%s", xod);
	
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












