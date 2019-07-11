#include "datastruct.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int todo;
	real* thelist = (real*)malloc(sizeof(real));;
	pb * thedata;
	char thename[100];
	int numofdata;
	char inname[100];
	char innumber[100];

	FILE * fp = fopen("phonebook.txt", "wt");

	puts("1. ������ �ʱ�ȭ");
	puts("2. ������ �Է�");
	puts("3. ������ ã��");
	puts("4. ������ ����");
	puts("5. ����\n");
	printf("������ �Ͻðڽ��ϱ�? ");
	scanf("%d", &todo);

	while (1) {
		if (todo == 1) {
			puts("�����͸� ���� ����ϴ�.");
			printf("�������� ũ�� : ");
			scanf("%d", &numofdata);
			makenew(thelist, numofdata);
			puts("�����͸� �ʱ�ȭ�߽��ϴ�.\n");
			printf("�� ������ �Ͻðڽ��ϱ�? ");
			scanf("%d", &todo);

		}
		
		if (todo == 2) {
			if (numofdata <= thelist->total) {
				puts("�����Ͱ� �̹� �� á���ϴ�.\n");
				printf("�� ������ �Ͻðڽ��ϱ�? ");
				scanf("%d", &todo);
			}
				
			else {
				printf("�̸��� �ּҸ� �Է����ּ���. (�̸� �ּ�) ");
				scanf("%s %s", inname, innumber);
				thedata = insert(thelist, inname, innumber);
				
				fputs(thedata->name, fp);
				fputs(" ", fp);
				fputs(thedata->num, fp);
				fputs("\n", fp);
				
				puts("�����͸� �����߽��ϴ�.");
				printf("���� �������� �� : %d\n\n", thelist->total);
				printf("�� ������ �Ͻðڽ��ϱ�? ");
				scanf("%d", &todo);
			}
		}

		if (todo == 3) {
			printf("ã������ ����� �̸��� �Է����ּ��� : ");
			scanf("%s", thename);
			puts(search(thelist, thedata, thename));
			printf("\n�� ������ �Ͻðڽ��ϱ�? ");
			scanf("%d", &todo);
			}

		if (todo == 4) {
			if (first(thelist, thedata)) {
				printf("%s %s\n", thedata->name, thedata->num);
				
				while (next(thelist, thedata)) 
					printf("%s %s\n", thedata->name, thedata->num);
			}

			printf("\n�� ������ �Ͻðڽ��ϱ�? ");
			scanf("%d", &todo);
		}

		if (todo == 5) {
			return 0;
		}
	}

	fclose(fp);
}