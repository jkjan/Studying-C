#include "treengraph.h"
#include "queue.h"

int num;
int * visited;
graph*glist;

void dfsg(int n) {
	visited[n] = 1;
	printf("from %d ", n);
	(glist + n)->adjs->dfs();
}

int main() {
	FILE * fp = fopen("input.txt", "rt");

	if (fp == NULL) {
		printf("File not found\n");
		return 0;
	}

	int vs;
	int i;
	int a, b;

	fscanf(fp, "%d %d", &num, &vs);
	glist = (graph*)malloc(sizeof(graph)*(num));

	for (i = 1; i <= num; i++) {
		(glist + i)->ver = i;
		(glist + i)->adjs = (node*)malloc(sizeof(node));
		(glist + i)->adjs->init();
		(glist + i)->adjcnt = 0;
	}

	for (i = 0; i < vs; i++) {
		fscanf(fp, " %d %d", &a, &b);
		if ((glist + a)->adjs->search(b) == 0) {
			(glist + a)->adjs->addtree(b);
			(glist + a)->adjcnt++;

			(glist + b)->adjs->addtree(a);
			(glist + b)->adjcnt++;
		}
		else
			puts("duplicate edge");
	}

	puts("==============================");
	for (i = 1; i <= num; i++) {
		printf("vertex %d: ", i);
		(glist + i)->adjs->treeprint();
		//dfsg(i);
		printf("\n");
	}
	puts("==============================");
	puts("dfs =================");


	visited = (int*)malloc(sizeof(int)*(num+1));
	for (i = 0; i <= num; i++)
		*visited = 0;

	dfsg(1);


	puts("==================");


	puts("bfs =================");



	puts("==================");


	
	for (i = 1; i <= num; i++) {
		(glist + i)->adjs->thanos();
	}
	
	free(glist);

	return 0;
}