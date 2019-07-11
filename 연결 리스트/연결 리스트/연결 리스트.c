#include <stdio.h>
#include <stdlib.h>

typedef struct nd {
	int data;
	struct nd * next;
} node;

int main() {
	node*head = NULL;
	node*cur = NULL;
	node*tail = NULL;
	int d;

	while (1) {
		node * newnode = (node*)malloc(sizeof(node));
		scanf("%d", &d);
		if (d < 1)
			break;

		newnode->data = d;
		newnode->next = NULL;

		if (head == NULL)
			head = newnode;
		else
			tail->next = newnode;

		tail = newnode;
	}

	if (head == NULL)
		printf("받은 자연수 x");
	else {
		cur = head;
		printf("%d ", cur->data);

		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	if (head == NULL)
		puts("이미 비어있습니다.");

	else {
		node*delnode = head;
		node*delnext = head->next;
		printf("%d 삭제\n", head->data);
		free(head);

		while (delnext != NULL) {
			delnode = delnext;
			delnext = delnext->next;
			printf("%d 삭제\n", delnode->data);
			free(delnode);
		}


	}
	return 0;

}