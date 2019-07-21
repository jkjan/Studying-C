#include "sex.h"

stack* stack:: init() {
	stack*real = new stack;
	real->head = NULL;
	real->cnt = 0;

	return real;
}

void stack::push(stack* fuck, int what){
	node*newnode = new node;
	newnode->num = what;

	if (fuck->head == NULL)
		fuck->head = newnode;

	else
		newnode->next = fuck->head;

	fuck->head = newnode;

	fuck->cnt++;

	cout << '+' << endl;
}

int stack::pop(stack*fuck){

	node*delnode = fuck->head;
	int whatwas = delnode->num;
	fuck->head = fuck->head->next;

	delete(delnode);

	fuck->cnt--;

	cout << whatwas <<" -" << endl;

	return whatwas;
}

int stack::isfull(stack*fuck){
	return 0;
}

int stack::isempty(stack*fuck){
	return fuck->cnt == 0 ? 1 : 0;
}

int stack::top(stack*fuck){
	if (!isempty(fuck))
		return fuck->head->num;
	else
		return 0;
}

