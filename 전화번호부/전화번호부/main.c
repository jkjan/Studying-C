#include <stdio.h>
#include <string.h>

typedef struct _pbook {
	char* name;
	char* num;
	char* etc;
}pbook;

#define _CRT_SECURE_NO_WARNINGS

pbook* bubble(pbook* list, int last);

int main() {

	pbook* list = malloc(sizeof(pbook) * 5);

	int i;

	for (i = 0; i < 5; i++) {
		(list+i)->name = malloc(sizeof(char) * 6);
		(list + i)->etc = malloc(sizeof(char) * 5);
	}

	for (i = 0; i < 5; i++) {
		scanf("%[^\n]", (list+i)->name);
		scanf("%s", (list + i)->num);
		scanf("%s", (list + i)->etc);
	}

	list = bubble(list, 5);

	for (i = 0; i < 5; i++) {
		printf("%s %11s %4s", (list + i)->name, (list + i)->num, (list + i)->etc);
	}

	return 0;
}

pbook* bubble(pbook* list, int last) {
	int i, j;
	int sorted;
	pbook  temp;

	for (i = last - 2; i >= 0; i--) {
		sorted = 0;
		for (j = 0; j <= i; j++) {
			if (strcmp((list + j)->name, (list + j + 1)->name) > 0) {
				temp = *(list + j);
				*(list + j) = *(list + j + 1);
				*(list + j + 1) = temp;
				sorted = 1;
			}
		}
		if (sorted == 0)
			break;
	}

	return list;
}