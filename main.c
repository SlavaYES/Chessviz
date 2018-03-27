#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int n=8, m=8+1;


int main()
{
    char a[n][m];
    char ch, tmp;
    int i, j;
    FILE *lone;
    lone=fopen("Chess.txt", "r");
    i=0;
    while (!feof(lone)) {
	fgets(a[i++], 9, lone);
	printf("%s", a[i]);
    }
    fclose(lone);
    return 0;
}