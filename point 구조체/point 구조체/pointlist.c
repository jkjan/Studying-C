#include <stdio.h>
#include "point.h"
#include "arrlist.h"

int main() {
	List list;
	Point compp;
	Point  *ppos;

	init(&list);

	ppos = (Point*)malloc(sizeof(Point));
	set(ppos, 2, 1);
	insert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	set(ppos, 2, 2);
	insert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	set(ppos, 3, 1);
	insert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	set(ppos, 3, 2);
	insert(&list, ppos);

	printf("저장된 데이터 수 : %d\n", count(&list));

	if (first(&list, &ppos)) {
		show(ppos);
		printf("\n");
		while (next(&list, &ppos)) {
			show(ppos);
			printf("\n");
		}
	}
	printf("\n\n\n");

	compp.xpos = 2;
	compp.ypos = 0;

	if (first(&list, &ppos) && comp(&compp, ppos) == 2) {
		remove(&list);
		free(ppos);
	}
	while (next(&list, &ppos)) {
		if (comp(&compp, ppos) == 2) {
			remove(&list);
			free(ppos);
		}
			
	}

	if (first(&list, &ppos)) {
		show(ppos);
		printf("\n");
		while (next(&list, &ppos)) {
			show(ppos);
			printf("\n");
		}
	}
}