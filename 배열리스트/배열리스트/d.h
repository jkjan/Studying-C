#pragma once
#ifndef dd
#define dd

#include <iostream>
#include <cstdlib>

using namespace std;

class ada {
private:
	int *num;
	int cnt;
	int size;

public:
	ada*init();
	void insert(ada*s, int a);
	int search(ada*s, int a, int l, int r);
	int remove(ada*s, int a);
	int isfull(ada*s);
	int isempty(ada*s);
	void printall(ada*s);
};


#endif