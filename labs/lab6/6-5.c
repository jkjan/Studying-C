#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _pbook {  //phonebook structure
	char* name;
	char* num;
	char* etc;
}pbook;

pbook* bubble(pbook* list, int last); // used bubble sort

int main() {

	pbook* list = malloc(sizeof(pbook) * 5);  //phonebook array

	int i;

	for (i = 0; i < 5; i++) {  //memory allocate
		(list+i)->name = malloc(sizeof(char) * 10);  
		(list + i)->num = malloc(sizeof(char) * 20);
		(list + i)->etc = malloc(sizeof(char) * 10);
	}

	for (i = 0; i < 5; i++) {     //data input
		printf("input name : ");
		scanf("%[^\n]", (list+i)->name);

		printf("input number : ");
		scanf("%s", (list + i)->num);

		printf("input etc : ");
		scanf("%s", (list + i)->etc);
		puts("\n");

		getchar();
	}

	list = bubble(list, 5);

	for (i = 0; i < 5; i++) {
		printf("%6s %11s %4s\n", (list + i)->name, (list + i)->num, (list + i)->etc);
	}

	return 0;
}

pbook* bubble(pbook* list, int last) {  //bubble sort
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
