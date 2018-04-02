#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conios.h"


const int n=9, m=9+1;

int main()
{
    char a[n][m];
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
    
    char xod[6], tmp;
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
    tmp=a[h[1]][h[0]];
    a[h[1]][h[0]]=a[h[4]][h[3]];
    a[h[4]][h[3]]=tmp;
    
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