#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct test {
	char t1;
	int t2;
}ing ;

void seed() {
	srand((unsigned int)time(0));
}

char *rak() {
	char beta[9];
	char real[9];
	for (int i = 0; i < 8; i++) {
		sprintf(real, "%d", rand() % 90000000 +10000000);
	}
	strcpy(beta, real);
	return beta;
}

int main() { 
	char *arr;
	for (int i = 0; i < 8; i++) {
		arr = rak();
		printf("%s\n", *(arr+i));
	}
}