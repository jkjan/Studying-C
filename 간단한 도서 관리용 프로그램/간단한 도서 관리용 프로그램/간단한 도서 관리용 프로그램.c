#include <stdio.h> 

typedef struct book {
	char author;
	char title;
	int pages;
}books;

int main() {
	int i, j;
	books b1, b2, b3;
	
	fgets(b1.author, 100, stdin);
	fgets(b1.title, 100, stdin);
	fgets(b1.pages, 100, stdin);

	fgets(b2.author, 100, stdin);
	fgets(b2.title, 100, stdin);
	fgets(b2.pages, 100, stdin);

	fgets(b3.author, 100, stdin);
	fgets(b3.title, 100, stdin);
	fgets(b3.pages, 100, stdin);

	puts("\n\n");

	puts("book1");
	fputs(b1.author, 100, stdin);
	fputs(b1.title, 100, stdin);
	fputs(b1.pages, 100, stdin);

	puts("\n");

	puts("book2");
	fputs(b2.author, 100, stdin);
	fputs(b2.title, 100, stdin);
	fputs(b2.pages, 100, stdin);

	puts("\n");

	puts("book3");
	fputs(b3.author, 100, stdin);
	fputs(b3.title, 100, stdin);
	fputs(b3.pages, 100, stdin);
	
	return 0;


