#include "razor.h"

stack* stack::init() {
	stack * real = (stack*)malloc(sizeof(stack));
	real->gwal = (char*)malloc(sizeof(char) * 100000);
	real->cnt = 0;
	real->size = 1000000;
	return real;
}

void stack::push(stack* loc, char g){
	if (!isfull(loc)) {
		*(loc->gwal + loc->cnt) = g;
		loc->cnt++;
	}

	else
		puts("error : stack full");
}

char stack::pop(stack* loc){
	if (!isempty(loc)) {
		return *(loc->gwal + loc->cnt - 1);
		loc->cnt--;
	}
	else
		puts("error : stack empty");
}
char stack::top(stack* loc){
	return *(loc->gwal + loc->cnt - 1);
}

int stack::isfull(stack*loc) {
	if (loc->cnt > loc->size)
		return 1;
	return 0;
}

int stack::isempty(stack*loc) {
	if (loc->cnt == 0)
		return 1;
	return 0;
}