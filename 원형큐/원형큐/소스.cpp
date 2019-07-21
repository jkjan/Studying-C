#include "Çì´õ.h"
cq* cq::init() {
	cq*real = new cq;
	real->q = new int(10);
	real->size = 10;
	real->cnt = 0;
	real->front = 0;
	real->back = 0;

	return real;
}

void cq:: in(cq* c, int n){
	c->q[c->back] = n;
	c->back = (c->back + 1) % (c->size);
	//c->back++;
	c->cnt++;
}

int cq::de(cq*c){
	int whatwas = c->q[c->front];
	c->front = (c->front + 1) % (c->size);
	//c->front++;
	c->cnt--;
	return whatwas;
}

int cq::isfull(cq*c){
	return c->cnt == c->size ? 1 : 0;
}

int cq::isempty(cq*c){
	return c->cnt == 0 ? 1 : 0;
}

void cq::printall(cq*c) {
	int i = c->front;
	int d = 0;

	while (d < c->cnt) {
		cout << c->q[i] << ' ';
		d++; 
		i++;
	}

	return;
}