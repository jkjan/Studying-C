#ifndef _priority
#define _priority
#include <iostream>
#define log(x) macro_log(__LINE__, x)

void macro_log(int lineNum, char* msg) {
	printf("error :%d, %s", lineNum, msg);
}

using namespace std;

typedef struct _data {
	int pnum;
	char *name;
} node;

class pq {
private:
	node *pdata;
	int back;

public:
	void init();
	void enque(int pnum, char* name);
	char*deque();
	char* top();
	void printq();
	int isfull();
	int isempty();
};

void swap(node* a, node* b);


#endif

#pragma once
