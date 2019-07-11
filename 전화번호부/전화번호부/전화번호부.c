#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phonebook {
	char name[10];
	char number[14];
}pb;

int i;

void insert();
void delete ();
void printall();
void search();

int main() {
	int choice;
	FILE*fp = fopen("phonebook.txt", "at");
	fclose(fp);

	printf("***** MENU *****\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Search\n");
	printf("4. Print All\n");
	printf("5. Exit\n");

	printf("Choose what you want to do : ");
	scanf("%d", &choice);

	switch (choice) {
	case 1: insert();
	case 2: delete();
	case 3: search();
	case 4: printall();
	case 5: return 0;
	}

}

void insert() {
	pb* pbt = (pb*)malloc(sizeof(pb));
	puts("[INSERT]\n");
	printf("Input Name : ");
	fgets(pbt->name, 10, stdin);
	printf("Input tel number : ");
	fgets(pbt->number, 14, stdin);

	FILE*fp = fopen("phonebook.txt", "at");
	fputs(pbt->name, fp);
	fputs(pbt->number, fp);
	fputs("\n", fp);

	fclose(fp);

}

void delete () {
	FILE*fp = fopen("phonebook.txt", "at");
	char deletename[10];
	printf("[DELETE]\n");
	printf("Delete Name : ");
	scanf("%s", deletename);

	char all[100];
	fgets(all, 100, fp);
	char *where = strstr(all, deletename);
	while (*where != '\n') {
		*where = ' ';
		where++;
	}

	fclose(fp);
}

void printall() {
	char all[1000];
	FILE*fp = fopen("phonebook.txt", "rt");
	fgets(all, 1000, fp);
	fputs(all, stdout);
	fclose(fp);
}


void search() {
	char all[1000];
	FILE*fp = fopen("phonebook.txt", "rt");
	fgets(all, 1000, fp);
	char searchname[10];
	printf("[SEARCH]\n");
	printf("Search Name : ");
	scanf("%s", searchname);
	char *where = strstr(all, searchname);
	printf("Tel : ");
	for (i = 10; i < 24; i++) {
		printf("%c", *(where+i));
	}
	fclose(fp);
}


