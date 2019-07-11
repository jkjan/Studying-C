#include <stdio.h>
#include <stdlib.h>

typedef struct _test{
	int ttt;
	char eee[10];
	float sss;
	char t;
}test;

int main() {
	FILE*fp = fopen("testing.txt", "wt");

	test* smu = (test*)malloc(sizeof(test) * 3);

	fputs("333 cc 4.5 c\n", fp);
	fputs("444 dd 2.1 d\n", fp);
	fputs("555 ee 1.5 e", fp);

	fclose(fp);

	fp = fopen("testing.txt", "rt");

	for (int i = 0; i < 3; i++) {
		fscanf(fp, "%d %s %f %c", &smu->ttt, smu->eee, &smu->sss, &smu->t);
		printf("%d %s %.1f %c\n", smu->ttt, smu->eee, smu->sss, smu->t);
		smu++;
	}
	fclose(fp);
	free(smu);
	return 0;
}