#ifndef seven
#define seven
#include <stdio.h>
#include <stdlib.h>
typedef struct _shorty {
	int name[9];
	int cur;
	int num;
} shorty;

typedef struct _no {
	int dont[2];
	int num;
}no;

int input(shorty* data, int n);
int first(shorty*data);
int next(shorty*data);
int remove(shorty*data);

#endif
#pragma once
