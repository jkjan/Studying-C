#ifndef dsda
#define dsda

#include <iostream>

using namespace std;

typedef struct _node node;

struct _node {
	int num;
	_node * next;
};

class ass {
private :
	node*head;
	node*cur;
	int cnt;

public:
	ass* init();
	void in(ass*s, int a);
	int out(ass*s, int a);
	node*search(ass*s, int a);
	int isfull(ass*s);
	int isempty(ass*s);
	void printall(ass*s);
};


#endif

#pragma once
