#ifndef dd
#define dd
#include <iostream>
#include <cstdlib>
using namespace std;

class cq {
private:
	int *q;
	int size;
	int cnt;
	int front;
	int back;
public:
	cq* init();
	void in(cq* c, int n);
	int de(cq*c);
	int isfull(cq*c);
	int isempty(cq*c);
	void printall(cq*c);
};


#endif

#pragma once
