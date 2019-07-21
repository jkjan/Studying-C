#ifndef _razor
#define _razor

#include <iostream>

using namespace std;

class stack {
private:
	char * gwal;
	int cnt;
	int size;
public:
	stack*init();
	void push(stack* loc, char g);
	char pop(stack* loc);
	char top(stack* loc);
	int isfull(stack*loc);
	int isempty(stack*loc);
};

#endif



#pragma once
