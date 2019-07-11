#include "header.h"

int many = 0;

void push(int x, node *head){
	node*newnode = NULL;
	newnode = (node*)malloc(sizeof(node));
	newnode->num = x;
	newnode->next = NULL;

	if (head == NULL)
		head = newnode;
	else
		newnode->next = head;

	head = newnode;
	many++;
}

int pop(node *head) {
	int dd;
	if (head == NULL)
		return -1;
	else {
		node * delnode = head;

		dd = delnode->num;

		free(delnode);
	}
	many--;
	return dd;
}

int size(){
	return many;
}

int empty(node *head){
	if (head == NULL)
		return 1;
	else
		return 0;
}

int top(node *head){
	//cur = head;
	if (head == NULL)
		return -1;
	return head->num;
}
