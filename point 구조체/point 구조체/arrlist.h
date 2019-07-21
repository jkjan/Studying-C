#ifndef arrlist
#define arrlist

#define list_len 100

typedef struct arr {
	int arr[list_len];
	int num;
	int curposition;
} List;

typedef int Ldata;

void init(List* plist);
void insert(List*plist, Ldata data);

int first(List *plist, Ldata*data);
int next(List *plist, Ldata*data);
Ldata remove(List *plist);
int count(List *plist);
#endif
#pragma once
