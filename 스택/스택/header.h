#ifndef stack
#define stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodes {
	int num;
	struct nodes* next;
}node;

void push(int x, node *a);
int pop(node *a);
int size();
int empty(node *a);
int top(node *a);

#endif

#pragma once
