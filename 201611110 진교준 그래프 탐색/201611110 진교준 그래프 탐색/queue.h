#ifndef metallica
#define metallica
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct _node qnode;

struct _node {
	int who;
	_node*next;
};

class jo {
private:
	qnode*people;
	qnode*cur;
	int cnt;

public:
	jo*init();
	int isempty(jo*que);
	int isfull(jo* que);
	int enque(jo*que, int what);
	int deque(jo*que);
};
#endif
#pragma once