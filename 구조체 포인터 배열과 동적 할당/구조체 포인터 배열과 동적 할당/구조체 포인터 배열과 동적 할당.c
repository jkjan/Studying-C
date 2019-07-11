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

	puts("도서 정보 입력");

	for (i = 0; i < 3; i++) {
		printf("book %d\n", i + 1);
		printf("저자 : ");
		scanf("%s", ((b + i)->author));
		printf("제목 : ");
		scanf("%s", ((b + i)->title));
		printf("페이지 수 : ");
		scanf("%d", &((b + i)->pages));
		printf("\n\n");
	}

	puts("\n\n도서 정보 출력");

	for (i = 0; i < 3; i++) {
		printf("book %d\n", i + 1);
		printf("저자 : ");
		printf("%s", ((b + i)->author));
		printf("\n제목 : ");
		printf("%s", ((b + i)->title));
		printf("\n페이지 수 : ");
		printf("%d", ((b + i)->pages));
		printf("\n\n");
	}

	free(b);
	return 0;

}