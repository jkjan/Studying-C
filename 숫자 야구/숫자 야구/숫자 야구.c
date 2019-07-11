#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ball(int *usi, int *compi) {
	int balcnt = 0;
	int i, j;

	int **ptr = &usi;
	int **bts = &compi;

	for (i = 0; i < 3; i++) {
		for (j = 0; j<3; j++)
			if (*usi+j == *compi+i)
				balcnt++;
	}

	return balcnt;
}


int main() {
	srand((int)time(NULL));
	
	int comp[3];
	int i, win=0;
	int user[3];

	for (i = 0; i < 3; i++)
		comp[i] = rand() % 9;

	for (i = 0; i < 3; i++)
		printf("%d",comp[i]);

	
	scanf("%d", user);

	printf("%d", ball(&user, &comp));

	}
