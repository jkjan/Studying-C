#ifndef tarantino
#define tarantino

#include <iostream>
#include <cstdlib>

using namespace std;

class que {
private:
	int * num;
	int front;
	int back;
public :
	que* init();
	void in(que* q, int n);
	int de(que*q);
	int isfull(que*q);
	int isempty(que*q);
};

#endif
#pragma once
