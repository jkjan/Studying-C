#include "datastruct.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int makenew(real *plist){
	puts("데이터를 새로 만듭니다.");
	int numofdata;
	plist->pbook = (pb*)malloc(sizeof(pb)*numofdata);
	plist->cur = 0;
	printf("데이터의 크기 : ");
	scanf("%d", &numofdata);
	plist->num = numofdata;

	return 1;
}

int insert(real*plist){
	char inname[100];
	char innumber[100];
	printf("이름과 주소를 입력해주세요. (이름 주소)");
	scanf("%s %s", inname, innumber);
	plist->pbook[plist->cur] = (pb) {*inname, *innumber };
	plist->cur++;

	return 0;
}

int first(real*plist, pb*data){
	if (plist->num < 0) 
		return 0;

	else {
		plist->cur = 0;
		*data = plist->pbook[0];
	}
	return 1;
}

int next(real*plist, pb*data){
	if (plist->cur >= plist->num-1)
		return 0;
	else {
		plist->cur++;
		*data = plist->pbook[plist->cur];
	}
	return 1;
}

pb del(real*plist){
	int rpos = plist->cur;
	int rnum = plist->num;
	pb temp = plist->pbook[rpos];

	for (i = rpos; i < rnum - 1; i++) {
		plist->pbook[i] = plist->pbook[i + 1];
	}

	(plist -> num)--;
	(plist->cur)--;

	return temp;
}

