#include <stdio.h>
#include <stdlib.h>

typedef struct cor {
	char author[10];
	char title[30];
	int pages;
} books;

int main() {
	books * b;
	b = (books*)malloc(sizeof(books) * 3);

	int i;

	puts("���� ���� �Է�");

	for (i = 0; i < 3; i++) {
		printf("book %d\n", i + 1);
		printf("���� : ");
		scanf("%s", ((b + i)->author));
		printf("���� : ");
		scanf("%s", ((b + i)->title));
		printf("������ �� : ");
		scanf("%d", &((b + i)->pages));
		printf("\n\n");
	}

	puts("\n\n���� ���� ���");

	for (i = 0; i < 3; i++) {
		printf("book %d\n", i + 1);
		printf("���� : ");
		printf("%s", ((b + i)->author));
		printf("\n���� : ");
		printf("%s", ((b + i)->title));
		printf("\n������ �� : ");
		printf("%d", ((b + i)->pages));
		printf("\n\n");
	}

	free(b);
	return 0;

}