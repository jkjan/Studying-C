#include <stdio.h>

typedef struct _node {
	int data;
	struct _node *next;
}node;

int main() {
	int i, num;
	node * head = NULL;
	node * cur = NULL;
	node*tail = NULL;

	while (1) {
		scanf("%d", &num);
		if (num < 1)
			break;
		node*newnode = (node*)malloc(sizeof(node));

		newnode->data = num;
		newnode->next = NULL;

		if (head == NULL)
			head = newnode;
		else
			//tail->next = newnode;
			newnode->next = head;

		//tail = newnode;
		head = newnode;
	}

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
}