#include "Çì´õ.h"

stack*stack::init() {
	stack* real = new stack;
	real->st = new int(10);
	real->top = 0;
	return real;
}

void stack::push(stack*s, int n){
	if (!isfull(s))
		s->st[(s->top)++] = n;
	return;
}

int stack::pop(stack*s){
	if (!isempty(s))
		return s->st[--(s->top)];
}

int stack::isfull(stack*s){
	return s->top == 10 ? 1 : 0;
}

int stack::isempty(stack*s){
	return s->top == 0 ? 1 : 0;
}

int stack::ipi(stack*s){
	if (!isfull(s)) {
		int dsd = s->st[--(s->top)];
		(s->top)++;
		return dsd;
	}
}
