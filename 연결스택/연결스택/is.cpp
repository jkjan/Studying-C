#include "this.h"

stack* stack::init(){
	stack* real = new stack;
	real->head = NULL;
	real->cnt = 0;
	return real;
}

void stack:: push(stack*s, int n){
	if (!isfull(s)) {
		node*newnode = new node;
		newnode->a = n;
		newnode->next = NULL;

		s->cnt++;

		if (isempty(s)) {
			s->head = newnode;
			return;
		}

		else
			newnode->next = s->head;
		s->head = newnode;
	}
}

int stack:: pop(stack*s){
	if (!isempty(s)) {
		node*delnode = s->head;
		int whatwas = delnode->a;

		s->head = s->head->next;

		delete(delnode);

		return whatwas;
	}
}

int stack:: isfull(stack*s){
	return 0;
}

int stack::isempty(stack*s){
	return s->cnt == 0 ? 1 : 0;
}

int stack:: top(stack*s){
	return s->head->a;
}