#include "board_read.h"
#include <stdio.h>
extern int n, m;

void boardRead(char a[n][m])
{
    FILE *file;
    int i;

    file=fopen("Chess.txt", "r");
    if (!file) printf("Error\n");
    a[0][0]='\0';
    i=1;
    while (!feof(file)) {
	fread(a[i], sizeof(a[1]), 1, file);
	i++;
    }
    fclose(file);
}
