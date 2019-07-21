#include "Çì´õ.h"

que* que::init() {
	que* real = new que;
	real->head = NULL;
	real->cur = NULL;
	real->cnt = 0;

	return real;
}

void que::in(que* list, int data){
	node*newnode = new node;
	newnode->card = data;
	newnode->next = NULL;

	if (list->head == NULL)
		list->head = newnode;

	else
		list->cur->next = newnode;

	list->cur = newnode;

	list->cnt++;
}

int que::de(que*list){
	if (!isfull(list)) {
		node*delnode = list->head;
		int whatwas = delnode->card;
		list->head = list->head->next;

		delete (delnode);

		list->cnt--;

		return whatwas;
	}

	return -1;
}

int que::isfull(que*list){
	return 0;
}


int que::isempty(que*list){
	return list->cnt == 0 ? 1 : 0;
}

