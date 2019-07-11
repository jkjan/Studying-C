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

	puts("1. 데이터 초기화");
	puts("2. 데이터 입력");
	puts("3. 데이터 찾기");
	puts("4. 데이터 삭제");
	puts("5. 종료\n");
	printf("무엇을 하시겠습니까? ");
	scanf("%d", &todo);

	while (1) {
		if (todo == 1) {
			puts("데이터를 새로 만듭니다.");
			printf("데이터의 크기 : ");
			scanf("%d", &numofdata);
			makenew(thelist, numofdata);
			puts("데이터를 초기화했습니다.\n");
			printf("또 무엇을 하시겠습니까? ");
			scanf("%d", &todo);

		}
		
		if (todo == 2) {
			if (numofdata <= thelist->total) {
				puts("데이터가 이미 꽉 찼습니다.\n");
				printf("또 무엇을 하시겠습니까? ");
				scanf("%d", &todo);
			}
				
			else {
				printf("이름과 주소를 입력해주세요. (이름 주소) ");
				scanf("%s %s", inname, innumber);
				thedata = insert(thelist, inname, innumber);
				
				fputs(thedata->name, fp);
				fputs(" ", fp);
				fputs(thedata->num, fp);
				fputs("\n", fp);
				
				puts("데이터를 저장했습니다.");
				printf("현재 데이터의 수 : %d\n\n", thelist->total);
				printf("또 무엇을 하시겠습니까? ");
				scanf("%d", &todo);
			}
		}

		if (todo == 3) {
			printf("찾으려는 사람의 이름을 입력해주세요 : ");
			scanf("%s", thename);
			puts(search(thelist, thedata, thename));
			printf("\n또 무엇을 하시겠습니까? ");
			scanf("%d", &todo);
			}

		if (todo == 4) {
			if (first(thelist, thedata)) {
				printf("%s %s\n", thedata->name, thedata->num);
				
				while (next(thelist, thedata)) 
					printf("%s %s\n", thedata->name, thedata->num);
			}

			printf("\n또 무엇을 하시겠습니까? ");
			scanf("%d", &todo);
		}

		if (todo == 5) {
			return 0;
		}
	}

	fclose(fp);
}