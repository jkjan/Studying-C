#include "datastruct.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int todo;
	real* thelist;
	pb *thedata;

	FILE * fp = fopen("phonebook.txt", "wt");

	puts("1. ������ �ʱ�ȭ");
	puts("2. ������ �Է�");
	puts("3. ������ ã��");
	puts("4. ������ ����");
	puts("5. ����");

	while (1) {
		scanf("%d", &todo);
		if (todo == 1) {
			makenew(thelist);
			puts("�����͸� �ʱ�ȭ�߽��ϴ�.");
		}

		if (todo == 5) {
			return 0;
		}
	}


}