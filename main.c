#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conios.h"


const int n=9, m=9+1;

int main()
{
    char a[n][m];
    char tmp, ch;
    int i, j;
    FILE *lone;
    
    lone=fopen("Chess.txt", "r");
    a[0][0]='\0';
    i=1;
    while (!feof(lone)) {
	fread(a[i], sizeof(a[1]), 1, lone);
	i++;
    }
    fclose(lone);
    
    printf("    A B C D E F G H\n\n");
    for (i=1; i<n; i++) {
	printf("%d", i);
	for (j=0; j<m; j++) {
	    printf("%2c", a[i][j]);
	}
    }
    int h[5+1];
    for (i=1; i<=5; i++) {
	ch=getch();
	switch (ch) {
	case 'a': h[i]=1; break;
	case 'b': h[i]=2; break;
	case 'c': h[i]=3; break;
	case 'd': h[i]=4; break;
	case 'e': h[i]=5; break;
	case 'f': h[i]=6; break;
	case 'g': h[i]=7; break;
	case 'h': h[i]=8; break;
	
	case '1': h[i]=1; break;
	case '2': h[i]=2; break;
	case '3': h[i]=3; break;
	case '4': h[i]=4; break;
	case '5': h[i]=5; break;
	case '6': h[i]=6; break;
	case '7': h[i]=7; break;
	case '8': h[i]=8; break;
	
	case '-': h[0]=-1; break;
	case 'x': h[0]=-2; break;
	}
    }
    tmp=a[h[1]][h[2]];
    a[h[1]][h[2]]=a[h[4]][h[5]];
    a[h[4]][h[5]]=tmp;
    
    printf("\n");
    system("clear");
    printf("    A B C D E F G H\n\n");
    for (i=1; i<n; i++) {
	printf("%d", i);
	for (j=0; j<m; j++) {
	    printf("%2c", a[i][j]);
	}
    }
    printf("\n");
    getch();
    return 0;
}