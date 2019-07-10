#include "datastruct.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int makenew(real *plist, int numofdata){
	plist->pbook = (pb*)malloc(sizeof(pb)*numofdata);
	plist->cur = 0;
	plist->total = 0;
	return 1;
}

pb* insert(real*plist, char*thename, char*thenum){
	strcpy((plist->pbook + plist->total)->name, thename);
	strcpy((plist->pbook + plist->total)->num, thenum);

	//printf("%s %s", (plist->pbook + plist->total), (plist->pbook + plist->total));
	plist->total++;
	return plist->pbook + plist->total-1;
}

int first(real*plist, pb*data){
	if (plist->total <= 0) 
		return 0;

	plist->cur = 0;
	*data = *plist->pbook;
	return 1;
}

int next(real*plist, pb*data){
	if (plist->cur >= (plist->total)-1)
		return 0;

	plist->cur++;
	*data = *(plist->pbook+plist->cur);
	return 1;
}

pb del(real*plist){
	int rpos = plist->cur;
	int rnum = plist->total;
	pb temp = plist->pbook[rpos];

	for (i = rpos; i < rnum - 1; i++) {
		plist->pbook[i] = plist->pbook[i + 1];
	}

	(plist -> total)--;
	(plist->cur)--;

	return temp;
}

char* search(real*plist, pb*data, char*scname) {
	if (first(plist, data)) {
		if (strcmp(data->name, scname) == 0)
			return data->num;
		while (next(plist, data)) {
			if (strcmp(data->name, scname) == 0)
				return data->num;
		}
	}
}