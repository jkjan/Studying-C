#include "priority.h"


#include <string.h>
#define MAX 10

void pq::init() {
	this->pdata = (node*)malloc(sizeof(node) * MAX+1);
	for (int i = 0; i < MAX+1; i++) {
		this->pdata[i] = { 5000, NULL };
	}
	this->back = 1;
}

void pq::enque(int pnum, char* name) {
	if (this->isfull()) {
		cout << "error : queue full" << endl;
		return;
	}

	int t = this->back;
	this->pdata[t] = { pnum, name };
	int p;

	while ((p = this->pdata[t / 2].pnum) != 5000) {
		if (p > pnum)
			swap(this->pdata+t, this->pdata + t / 2);	
		t /= 2;
	}
	this->back++;
}

char*pq::deque() {
	if (this->isempty()) {
		cout << "error : queue empty" << endl;
		char error[] = "error";
		cout << "WARNING : DO NOT TRY TO PRINT THIS. IT IS A NPTR" << endl;
		log(error);
		return NULL;
	}

	char* name = (this->pdata+1)->name;

	this->pdata[1] = this->pdata[this->back -1];

	this->pdata[this->back - 1] = { 5000, NULL };

	this->back--;
	int index = 1;

	while ((index*2 < MAX && (this->pdata + index * 2)->pnum != 5000) || ((index * 2 + 1 < MAX)&& (this->pdata + index * 2 + 1)->pnum != 5000)) {
		if ((this->pdata + index)->pnum > (this->pdata + index * 2)->pnum || (this->pdata + index)->pnum > (this->pdata + index * 2 + 1)->pnum) {
			if ((this->pdata + index * 2)->pnum > (this->pdata + index * 2 + 1)->pnum) {
				swap((this->pdata + index * 2 + 1), (this->pdata + index));
				index = index * 2 + 1;
			}
			else {
				swap((this->pdata + index * 2), (this->pdata + index));
				index *= 2;
			}
		}
		else
			break;
	}
	return name;
}

void pq:: printq() {
	for (int i = 1; i < this->back; i++)
		cout << (this->pdata+i)->name << endl;
}

char* pq::top() {
	return (this->pdata + 1)->name;
}

void swap(node* a, node* b) {
	node temp = *a;
	*a = *b;
	*b = temp;
}

int pq:: isempty() {
	return this->back-1 <= 0 ? 1:0;
}

int pq::isfull() {
	return this->back - 1 >= MAX ? 1 : 0;
}