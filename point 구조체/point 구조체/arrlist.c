#include <stdio.h>
#include "arrlist.h"

void init(List *plist) {
	(plist->num = 0);	//배열 길이 0으로 초기화
	(plist->curposition) = -1;	//현재 위치(배열 인덱스)를 -1로
}

void insert(List *plist, Ldata data) {
	if ((plist->num) >= list_len) {
		printf("꽉 찼습니다");
		return;
	}

	plist->arr[plist->num] = data;
	plist->num++;
}

int first(List *plist, Ldata *data) {
	if (plist->num == 0)
		return 0;

	plist->curposition = 0;
	*data = plist->arr[0];
	return 1;
}

int next(List *plist, Ldata *data) {
	if (plist->curposition >= plist->num - 1)
		return 0;
	plist->curposition++;
	*data = plist->arr[plist->curposition];
	return 1;
}

Ldata remove(List *plist) {
	int rpos = plist->curposition;
	int num = plist->num;
	int i;
	Ldata rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	plist->num--;
	plist->curposition--;

	return rdata;
}

int count(List *plist) {
	return plist->num;
}