#include "MinIsTheBestProfInTheWorld.h"
#include <string.h>

static int stop;

void sinfo::infoprint() {
	cout << this->name << ' ' <<
		this->sex << ' ' <<
		this->loc << ' ' <<
		this->major << ' ' <<
		this->score << ' ' <<
		this->height << ' ' <<
		this->weight << endl;
}

node*  node::init() {
	this->info = new sinfo;
	this->lc = NULL;
	this->rc = NULL;

	return this;
}

void node:: treeprint(){
	if (this != NULL) {
		this->lc->treeprint();
		this->info->infoprint();
		cout << isleaf(this) << endl;
		this->rc->treeprint();
	}
}
node* node:: addtree(node* p, sinfo* w){
	int cond;

	if (p == NULL) {
		p = talloc();
		p->info = w;
		p->lc = p->rc = NULL;
	}

	else if ((cond = strcmp(w->name, p->info->name)) < 0)
		p->lc = addtree(p->lc, w);
	else
		p->rc = addtree(p->rc, w);

	return p;
}

getReturn* node:: search(node*p, char * name){
	stop = 0;

	if (p==NULL)
		return NULL;

	if (p->lc != NULL && strcmp(p->lc->info->name, name) ==0) {   //원래 형태는 treeprint와 같은 순회인데 이게 return p를 하여도 멈추지 않더랍니다
		stop = 1;
		cout << "왼쪽의 것이 바로 타겟" << endl;
		getReturn *srched = setReturn(p, 1);
		return srched;
	}

	else if (p->rc != NULL && strcmp(p->rc->info->name, name) == 0) {
		stop = 1;
		cout << "오른쪽의 것이 바로 타겟" << endl;
		getReturn* srched = setReturn(p, 0);
		return srched;
	}

	if (!stop) {
		search(p->lc, name);
	}

	if (!stop) {
		search(p->rc, name);
	}
}

int node ::remove(node * p, char*name) {
	getReturn *returned = search(p, name);
	node* LeftMax = new node;
	cout << name << " 을 지워" << endl;
	if (returned == NULL)
		return 0;

	if (returned->lr == 1) {
		cout << "왼쪽에서 온 친구" << endl;
		LeftMax = getLeftMax(returned->searched->lc->lc);
		cout << "최대값 저장" << endl;
		
		returned->searched ->lc->info = LeftMax->rc->info;
		}

	else {
		cout << "오른쪽에서 온 친구" << endl;
		LeftMax = getLeftMax(returned->searched->rc->lc);
		cout << "최대값 저장" << endl;
		returned->searched->rc->info = LeftMax->rc->info;
		}
	
	LeftMax->rc = NULL;

	return 1;
}

int node::isleaf(node*p) {
	if ((p->lc == NULL) && (p->rc == NULL))
		return 1;
	else
		return 0;
}

node* node::getLeftMax(node* p) {
	node * max = new node;
	max = p;

	while (p->rc != NULL) {
		max = p;
		p = p->rc;
		
	}
	cout << max->info->name << "이 최대인가?" << endl;

	return max;
}

node* node::talloc() {
	return (node*)malloc(sizeof(node));
}

getReturn* node::setReturn(node* p, int l) {
	getReturn* srched = new getReturn;
	srched->searched = p;
	srched->lr = l;
	return srched;
}