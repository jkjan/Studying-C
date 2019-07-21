#include "Çì´õ.h"

ass* ass::init(){
	ass*real = new ass;
	real->head = NULL;
	real->cnt = 0;
	return real;
}

void ass::in(ass*s, int a){
	if (isfull(s))
		return;

	node*newnode = new node;
	newnode->num = a;

	if (s->head == NULL) {
		s->head= newnode;
		s->cur = newnode;
	}

	else if (s->head->num > a) {
		newnode->next = s->head;
		newnode = s->head;
	}

	else {
		node*cal = s->head;
		while (s->cur->next != NULL) {
			if (s ->cur->next->num > a) {
				newnode->next = cur->next;
				cur->next = newnode;
				break;
			}
			s->cur = s->cur->next;
		}

		if (s->cur->next == NULL) {
			cur->next = newnode;
		}

	}

	s->cnt++;

}

int ass::out(ass*s, int a){
	node* wherewas = search(s, a);
	node*delnode = wherewas->next;
	int whatwas = delnode->num;

	wherewas->next = delnode->next;

	delete(delnode);

	s->cnt--;

	return whatwas;
}

node*ass::search(ass*s, int a){
	node*cal = s->head;

	while (cal->next != NULL) {
		if (cal->next->num == a)
			return cal;
		cal = cal->next;
	}
}

int ass::isfull(ass*s){
	return 0;
}

int ass::isempty(ass*s){
	return s->head == NULL ? 1 : 0;
}

void ass :: printall(ass*s) {
	node*cal = s->head->next;

	for (int i = 0; i < s->cnt; i++) {
		cout <<cal->num << ' ';
		cal = cal->next;
	}
}