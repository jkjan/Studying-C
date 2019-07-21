#ifndef q
#define q

#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct _node node; 

struct _node {
	int card;
	_node* next;
};

class que {
private :
	node*head;
	node*cur;
	int cnt;

public : 
	que* init();
	void in(que* list, int data);
	int de(que*list);
	int isfull(que*list);
	int isempty(que*list);
};
#endif
#pragma once
