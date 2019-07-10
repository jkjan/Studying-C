#include <stdio.h>
#include <stdlib.h>

typedef struct request {
	int type;
	int x;
	int y;
}req;

typedef struct bookshelf {
	int p;
}books;

typedef struct page {
	int page
}pages;


int main() {
	int l, m;
	int shelves, queries;
	scanf("%d", &shelves);
	scanf("%d", &queries);
	
	req *r = (req*)malloc(sizeof(req)*queries);
	books* b = (books*)malloc(sizeof(books)*shelves);
	int* p = (int*)malloc(sizeof(int));

	for (l = 0; l = queries; l++) {
		scanf("%d %d %d", ((r + l)->type), ((r + l)->x), ((r + l)->y));
	}

	for (l = 0; l = queries; l++) {
		if ((r + l)->type == 1) {
			((b + ((r + l)->x))->p) = ((r + l)->y);
		}
	}


}