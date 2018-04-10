#include "board_read.h"
#include <stdio.h>
extern int n, m;

void bread(char a[n][m])
{
    FILE *lone;
    int i;
    lone=fopen("Chess.txt", "r");
    a[0][0]='\0';
    i=1;
    while (!feof(lone)) {
	fread(a[i], sizeof(a[1]), 1, lone);
	i++;
    }
    fclose(lone);
}
