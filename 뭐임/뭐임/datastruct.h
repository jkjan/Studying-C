#ifndef datastruct
#define datastruct

typedef struct phonebook {
	char name[100];
	char num[100];
} pb;

typedef struct l {
	pb* pbook;
	int cur;
	int total;
}real;

int makenew(real *plist, int numofdata);
pb* insert(real*plist, char*thename, char*thenum);
int first(real*plist, pb*data);
int next(real*plist, pb*data);
pb del(real *plist);
char* search(real*plist, pb*data, char*scname);

int i;
#endif
#pragma once
