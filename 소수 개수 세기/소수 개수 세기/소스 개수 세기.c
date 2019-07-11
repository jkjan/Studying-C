#include <stdio.h>
#include <stdlib.h>

int main() {
	int totalnum, i;
	scanf("%d", &totalnum);
	int*numbers = (int*)malloc(sizeof(int)*totalnum);
	for (i = 0; i < totalnum; i++) {
		scanf("%d", numbers+i);
	}

	


}