#include "header.h"

int main() {
	int com, i;
	char coms[10];
	scanf("%d", &com);
	int n;


	node *head = NULL;

	for (i = 0; i < com; i++) {
		scanf("%s", coms);
		if (!strcmp(coms, "push")) {
			scanf("%d", &n);
			push(n, head);
		}
		/*
		else if (!strcmp(coms, "top"))
			printf("%d", top(head));

		else if (!strcmp(coms, "size"))
			printf("%d", size(head));

		else if (!strcmp(coms, "empty"))
			printf("%d", empty(head));

		else if (!strcmp(coms, "pop"))
			printf("%d", pop(head));
			*/



	}
}