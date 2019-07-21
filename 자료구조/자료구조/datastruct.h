#ifndef datastruct
#define datastruct

typedef struct phonebook {
	char name[100000];
	char num[100000];
} pb;

typedef struct l {
	pb* pbook;
	int cur;
	int num;
}real;

int makenew(real *plist);
int insert(real*plist);
int first(real*plist, pb*data);
int next(real*plist, pb*data);
pb del(real *plist);

int i;
#endif
#pragma once
