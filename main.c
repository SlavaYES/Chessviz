#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conios.h"

const int n=9, m=9+1;

void swap(char *x, char *y);
void outBoard(char a[n][m]);

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
    
    outBoard(a);
    
    char xod[6];
    char tmp0, tmp1;
    int h[5];
    printf("\nХод: "); scanf("%s", xod);
    
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
    
    tmp0=a[h[1]][h[0]];
    tmp1=a[h[4]][h[3]];
    if (tmp0=='p' || tmp0=='P') {
	if (h[0]==h[3]) {
	    if (h[2]==-1 && tmp1==' ') {
		swap(&a[h[1]][h[0]], &a[h[4]][h[3]]);
	    }
	}
    }
    outBoard(a);
    printf("%s", xod);
    printf("\n");
    getch();
    return 0;
}

void swap(char *x, char *y)
{
    char tmp=*x; *x=*y; *y=tmp;
}

void outBoard(char a[n][m])
{
    int i, j;
    printf("\n");
    clrscr();
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













