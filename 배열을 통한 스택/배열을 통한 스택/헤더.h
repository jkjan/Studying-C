#ifndef a
#define a

#include <iostream>

using namespace std;

class stack {
private:
	int *st;
	int top;

public:
	stack*init();
	void push(stack*s, int n);
	int pop(stack*s);
	int isfull(stack*s);
	int isempty(stack*s);
	int ipi(stack*s);
};
#endif
#pragma once
