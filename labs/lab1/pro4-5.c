#include <stdio.h>
#include <limits.h>

int main () {

	register int i, j;

	for ( i = 1; i < INT_MAX; i++) {
		j = i;
		i = j;
	}

	printf("register Done.\n");

	return 0;
}
