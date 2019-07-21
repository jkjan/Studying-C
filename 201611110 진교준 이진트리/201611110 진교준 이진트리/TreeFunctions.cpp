#include "MinIsTheBestProfInTheWorld.h"
#include <string.h>
#include <fstream>
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

/*
void node::init() {
	this->info = new sinfo;
	this->lc = NULL;
	this->rc = NULL;
}
*/

void node::treeprint() {
	if (this != NULL) {
		this->lc->treeprint();
		this->info->infoprint();
		this->rc->treeprint();
	}
}
node* node::addtree(node* p, sinfo* w) {
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

getReturn* node::search(char* name) {
	stop = 0;

	if (this == NULL)
		return NULL;

	if (strcmp(this->info->name, name) == 0)
		return setReturn(this, 2);

	if (this->lc != NULL && strcmp(this->lc->info->name, name) == 0) {
		stop = 1;
		return setReturn(this, 1);
	}

	else if (this->rc != NULL && strcmp(this->rc->info->name, name) == 0) {
		stop = 1;
		return setReturn(this, 0);
		
	}

	if (!stop) {
		this->lc->search(name);
	}

	if (!stop) {
		this->rc->search(name);
	}
}

int node::remove(char* name) {
	node* LeftMax = new node;
	node* whatwas = talloc();
	getReturn* returned = new getReturn;
	
	int cond;
	//x가 key와 같으면
	if ((cond = strcmp(name, this->info->name)) == 0) {

		//1: leaf 노드이면
		if (this->lc == NULL && this->rc == NULL)
			return 1;

		//2-1: 왼쪽만 null
		if (this->lc == NULL && this->rc != NULL) {
			this->info = this->rc->info;
			this->lc = this->rc->lc;
			this->rc = this->rc->rc;
			return 0;
		}

		//2-2: 오른쪽만 null
		if (this->lc != NULL && this->rc == NULL) {
			this->info = this->lc->info;
			this->lc = this->lc->lc;
			this->rc = this->lc->rc;
			return 0;
		}

		//3: 둘다 아님
		if (this->lc != NULL && this->rc != NULL) {
			this->info = getLeftMax(this->lc)->info;
			if (this->lc->remove(this->info->name) == 1)
				this->lc = NULL;
			return 0;
		}
	}

	//x가 key 보다 작으면
	else if (cond < 0) {
		if (this->lc != NULL) {
			if (this->lc->remove(name) == 1)
				this->lc = NULL;
		}
		return 0;
	}

	//x가 key보다 크면
	else {
		if (this->rc != NULL) {
			if (this->rc->remove(name) == 1)
				this->rc = NULL;
		}
		return 0;
	}
	
	/*
	if (strcmp(p->info->name, name) != 0) {
		returned = p->search(name);
	}

	else {
		if (p->lc != NULL) {
			whatwas = LeftMax = getLeftMax(p->lc);

			if (LeftMax->rc != NULL) {
				LeftMax = LeftMax->rc;
			}

			cout << LeftMax->info->name << endl;
			p->info = LeftMax->info;

			if (LeftMax->lc != NULL) {
				whatwas->rc = LeftMax->lc;
			}

			else
				whatwas->rc = NULL;
			return 1;
		}
		else {
			p = p->rc;
			return 1;
		}
	}

	if (returned == NULL)
		return 0;

	if (returned->lr == 1) {
		if (isleaf(returned->searched->lc) == 1) {
			returned->searched->lc = NULL;
			return 1;
		}

		if (returned->searched->lc->lc == NULL) {
			returned->searched->lc = returned->searched->lc->rc;
			return 1;
		}

		else {
			whatwas = LeftMax = getLeftMax(returned->searched->lc->lc);
			if (LeftMax->rc != NULL) {
				LeftMax = LeftMax->rc;
			}
		}

		//삭제 작업
		returned->searched->lc->info = LeftMax->info;

		if (whatwas->rc == NULL) {
			if (whatwas->lc != NULL)
				returned->searched->lc->lc = LeftMax->lc;
			else {
				returned->searched->lc->lc = NULL;
				return 1;
			}
		}
	}

	else {
		if (isleaf(returned->searched->rc) == 1) {
			returned->searched->rc = NULL;
			return 1;
		}

		if (returned->searched->rc->lc == NULL) {
			returned->searched->rc = returned->searched->rc->rc;
			return 1;
		}

		else {
			whatwas = LeftMax = getLeftMax(returned->searched->rc->lc);

			if (LeftMax->rc != NULL) {
				LeftMax = LeftMax->rc;
			}
		}

		returned->searched->rc->info = LeftMax->info;
		if (whatwas->rc == NULL) {
			if (whatwas->lc != NULL) {
				returned->searched->rc->lc = whatwas->lc;
			}
			else {
				returned->searched->rc->lc = NULL;
				return 1;
			}
		}
	}

	if (LeftMax->lc != NULL) {
		whatwas->rc = LeftMax->lc;
	}
	else
		whatwas->rc = NULL;

	return 1;
	*/
}

int node::isleaf(node * p) {
	if ((p->lc == NULL) && (p->rc == NULL))
		return 1;
	else
		return 0;
}

node * node::getLeftMax(node * p) {
	node* max = new node;
	max = p;

	while (p!= NULL) {
		max = p;
		p = p->rc;
	}
	return max;
}

node* node::talloc() {
	return (node*)malloc(sizeof(node));
}

getReturn* node::setReturn(node * p, int l) {
	getReturn* srched = new getReturn;
	srched->searched = p;
	srched->lr = l;
	return srched;
}