#include "lunatic.h"

void node::treeprint() {
	if (this != NULL) {
		this->lc->treeprint();
		printf("%d ", this->adjnode);
		this->rc->treeprint();
	}
}

void node::addtree(int adj) {
	printf("%d �߰� ��\n", adj);
	if (this->adjnode == -1) {
		this->adjnode = adj;
	}

	else if (this->adjnode > adj) {
		printf("�������� ����");
		this->lc->init();
		this->lc->addtree(adj);
	}
	else {
		printf("���������� ����");
		this->rc->init();
		this->rc->addtree(adj);
	}
}

void node::init() {
	printf("init called\n");
	this->adjnode = -1;
	this->lc = NULL;
	this->rc = NULL;
	printf("init done\n");
}

int node::search(int v) {
	if (this == NULL)
		return 0;
	if (this->adjnode == v)
		return 1;
	else if (this->adjnode > v)
		this->lc->search(v);
	else
		this->rc->search(v);
 }