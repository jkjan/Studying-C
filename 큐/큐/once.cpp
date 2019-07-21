#include "quentin.h"

que* que::init(){
	que*real = new que;
	real->num = new int(10);
	real->front = 0;
	real->back = 0;

	return real;
}

void que::in(que* q, int n){
	if (!isfull(q))
		q->num[(q->back)++] = n;
}

int que::de(que*q){
	if (!isempty(q))
		return q->num[(q->front)++];
}

int que::isfull(que*q){
	return q->back == 10 ? 1 : 0;
}

int que::isempty(que*q){
	return q->front == q->back ? 1 : 0;
}