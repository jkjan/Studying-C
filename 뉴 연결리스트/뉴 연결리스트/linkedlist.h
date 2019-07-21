#pragma once
#include <iostream>

static int cnt;
class link;
static link* cur;

class link {
private:
	int V;
	link* next;
public:
	void init();
	void add(int v);
	int rem(int r);
	int is_full();
	int is_empty();
};