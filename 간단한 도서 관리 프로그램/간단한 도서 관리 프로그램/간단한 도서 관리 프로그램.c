#include <stdio.h>

typedef struct cor {
	char author[100];
	char title[300];
	int pages;
} books;

int main() {
	books lib[3];

	int i;

	puts("���� ���� �Է�");

	for (i = 0; i < 3; i++) {
		printf("book %d\n", i + 1);
		printf("���� : ");
		scanf("%s", lib[i].author);
		printf("���� : ");
		scanf("%s", lib[i].title);
		printf("������ �� : ");
		scanf("%d", &lib[i].pages);
		printf("\n");
	}

	puts("\n���� ���� ���");

	for (i = 0; i < 3; i++) {
		printf("book %d\n", i + 1);
		printf("���� : ");
		printf("%s", lib[i].author);
		printf("\n���� : ");
		printf("%s", lib[i].title);
		printf("\n������ �� : ");
		printf("%d", lib[i].pages);
		printf("\n\n");
	}



}