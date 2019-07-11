#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

int main() {
	node*head = NULL;
	node*cur = NULL;

	node*newnode = NULL;
	int readdata;
	while (1) {
		scanf("%d", &readdata);
		if (readdata < 1)
			break;

		newnode = (node*)malloc(sizeof(node));
		newnode->data = readdata;
		newnode->next = NULL;

		if (head == NULL)
			head = newnode;
		else
			newnode->next = head;

		head = newnode;
	}

	puts("��� ����");
	
	if (head == NULL)
		puts("no data");
	else {
		cur = head;
		printf("%d ", head->data);
		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}

	puts("���� ����");

	if (head == NULL)
		puts("no data");
	else {
		node* delnode = head;
		node *nextarget = head->next;

		printf("%d ����", head->data);
		free(delnode);

		while (nextarget != NULL) {
			delnode = nextarget;
			nextarget = nextarget->next;
			printf("%d ����", delnode->data);
			free(delnode);

		}

	}
	return 0;
}

