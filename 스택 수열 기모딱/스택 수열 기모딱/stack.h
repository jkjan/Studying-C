#ifndef sex
#define sex


#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct _node node; 

struct _node {
	int num;
	_node*next;
};

class stack {
private:
	node*head;
	int cnt;

public:
	stack* init();
	void push(stack* fuck, int what);
	int pop(stack*fuck);
	int isfull(stack*fuck);
	int isempty(stack*fuck);
	int top(stack*fuck);
};


#endif



#pragma once
