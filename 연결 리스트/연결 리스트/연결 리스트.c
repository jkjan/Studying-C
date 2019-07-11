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
		printf("���� �ڿ��� x");
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
		puts("�̹� ����ֽ��ϴ�.");

	else {
		node*delnode = head;
		node*delnext = head->next;
		printf("%d ����\n", head->data);
		free(head);

		while (delnext != NULL) {
			delnode = delnext;
			delnext = delnext->next;
			printf("%d ����\n", delnode->data);
			free(delnode);
		}


	}
	return 0;

}