#include <stdio.h>
#include "board_print_plain.h"
#include "conios.h"

extern int n, m;

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