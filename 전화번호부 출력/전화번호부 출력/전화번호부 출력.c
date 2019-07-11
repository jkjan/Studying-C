#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#define n 1000

typedef struct phonebook {
	char name[100000];
	char num[100000];
} pb;

typedef struct l {
	pb pbook[100];
	int cur;
}real;

typedef struct search {
	char scname[100000];
	char scnum[100000];
	int non;
} sch;

int main() {
	int n, i, j;
	srand(time(NULL));
	int cnt = 0;
	char a[8];
	scanf("%d", &n);
	pb * book = (pb*)malloc(sizeof(pb)*n);
	sch* find = (sch*)malloc(sizeof(sch)*n);

	for (i = 0; i < n; i++)
		scanf("%s %s", (book+i)->name, (book+i)->num);

	for (i = 0; i < n; i++)
		scanf("%s", (find + i)->scname);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (strcmp((book + i)->name, (find + j)->scname) == 0) {
				strcpy((find + j)->scnum, (book + i)->num);
				(find + j)->non = 1;
				//printf("%s=%s\n", (book + i)->name, (book + i)->num);
				break;
			}
		}
	}

	for (i = 0; i < n; i++) {
		if ((find + i)->non != 1)
			printf("Not found\n");
		else
			printf("%s=%s\n", (find + i)->scname, (find + i)->scnum);
	}





	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	free(book);
	free(find);
	return 0;
}
