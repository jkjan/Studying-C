#ifndef thisshit
#define thisshit

#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct _node node;

struct _node {
	int a;
	_node* next;
};

class stack {
private:
	node*head;
	int cnt;

public:
	stack*init();
	void push(stack*s, int n);
	int pop(stack*s);
	int isfull(stack*s);
	int isempty(stack*s);
	int top(stack*s);
};

#endif

#pragma once
