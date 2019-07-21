#include "linkedlist.h"

void link::init() {
	this->V = -1;
	this->next = NULL;
	cnt = 0;
}

void link::add(int v) {
	link* nnode = new link;
	nnode->V = v;
	nnode->next = NULL;

	if (cnt == 0) {
		this->next = nnode;
	}

	else {
		cur->next = nnode;
	}

	cur = nnode;
}

int link::rem(int r) {
	link* rcur = new link;
	rcur = this;
	while (rcur->next != NULL) {
		if (rcur->next->V == r)
			break;
		rcur = rcur->next;
	}

	link* dnode = rcur->next;
	int dV = dnode->V;

	rcur->next = dnode->next;
	delete(dnode);

	return dV;
}

int link::is_full() {
	return 0;
}

int link::is_empty() {
	return cnt == 0 ? 1 : 0;
}