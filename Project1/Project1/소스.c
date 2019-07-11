#include <stdio.h>
#include <stdlib.h>

char t_block[4][4][4] = {
			1, 0, 0, 0,  1, 1, 0, 0,  1, 0, 0, 0,  0, 0, 0, 0,
			1, 1, 1, 0,  0, 1, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
			0, 0, 1, 0,  0, 1, 1, 0,  0, 0, 1, 0,  0, 0, 0, 0,
			0, 0, 0, 0,  0, 1, 0, 0,  1, 1, 1, 0,  0, 0, 0, 0
};

char *next = t_block;

int main() {
	int i, j;
	
	for (j = 0; j < 4; j++) {
		for (i = 0; i < 4; i++) {
			if (i % 4 == 0)
				printf("\n");
			if (*(next+j*4+i+(16)*2) == 1)
				printf("x");
			else
				printf("o");
		}
	}

}