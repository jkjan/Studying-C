#include <stdio.h>

typedef struct cor {
	char author[100];
	char title[300];
	int pages;
} books;

int main() {
	books lib[3];

	int i;

	puts("도서 정보 입력");

	for (i = 0; i < 3; i++) {
		printf("book %d\n", i + 1);
		printf("저자 : ");
		scanf("%s", lib[i].author);
		printf("제목 : ");
		scanf("%s", lib[i].title);
		printf("페이지 수 : ");
		scanf("%d", &lib[i].pages);
		printf("\n");
	}

	puts("\n도서 정보 출력");

	for (i = 0; i < 3; i++) {
		printf("book %d\n", i + 1);
		printf("저자 : ");
		printf("%s", lib[i].author);
		printf("\n제목 : ");
		printf("%s", lib[i].title);
		printf("\n페이지 수 : ");
		printf("%d", lib[i].pages);
		printf("\n\n");
	}



}