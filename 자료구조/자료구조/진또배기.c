#include "datastruct.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int todo;
	real* thelist;
	pb *thedata;

	FILE * fp = fopen("phonebook.txt", "wt");

	puts("1. 데이터 초기화");
	puts("2. 데이터 입력");
	puts("3. 데이터 찾기");
	puts("4. 데이터 삭제");
	puts("5. 종료");

	while (1) {
		scanf("%d", &todo);
		if (todo == 1) {
			makenew(thelist);
			puts("데이터를 초기화했습니다.");
		}

		if (todo == 5) {
			return 0;
		}
	}


}