#include "maximumeffort.h"
#include <cstdlib>

static int stop; //������ ��������

void tnode::init() {  //�ִ��� �������� ���Ͻ� ��� �Ͽ����ϴ�.
	this->num = -1;
	this->lc = NULL;
	this->rc = NULL;
}

tnode* tnode:: addtree(tnode *p, int r, int lc, int rc) {  //insert�� ��ͷ� �ϰ� val... ?
	if (p->num == -1)									   //�������� �ֽ� �ذ� ����� �� �������� ���ؼ�
		p = addnode(r);									   //���� ���� ���� ������� �ذ��߽��ϴ�

	p->lc = addnode(lc);
	p->rc = addnode(rc);
	return p;
}

tnode* tnode::addnode(int val) {
	tnode* newnode = new tnode;			//��� ��� �ϳ� �ϳ� ����� �Լ��� �����
	newnode->num = val;					//������ ���� ��������� �� �ּҸ� �����ϴ� ������ �����߽��ϴ�
	newnode->lc = newnode->rc = NULL;
	return newnode;
}

tnode* tnode::search(tnode* p, int val) {
	stop = 0;

	if (p == NULL)
		return NULL;

	else {
		if (p->num == val) {   //���� ���´� treeprint�� ���� ��ȸ�ε� �̰� return p�� �Ͽ��� ������ �ʴ����ϴ�
			stop = 1;
			return p;
		}
		if (!stop)             //����Լ��� ������ �ʾƼ� ���������� ��µ�..
			search(p->lc, val);

		if (!stop)
			search(p->rc, val);
	}
}

tnode* tnode::valid(tnode* p, int val, int l, int r) {
	tnode* next;
	if ((next = search(p, val)) != NULL)
		//�̷��� �� ������ main���� search �Լ��� �� �� �� ȣ��Ǵ� ���� ���� ���ؼ��Դϴ�.
		if (isleaf(next, val) && checkrulethree(p, l, r))
			return next; //������ valid�ϴ� �ǴܵǸ� ���ٰ� ��带 ������ main���� ģ���ϰ� �˷��ִ� �ڵ��Դϴ�

	return NULL;
}

bool tnode::checkrulethree(tnode* p, int l, int r) {
	tnode* lv;
	tnode* rv;	//left child, right child �� �ĺ����� Ʈ���� �̹� �����ϴ��� �� �ϴ����� �˷��ִ� �Լ��Դϴ�.
	return ((lv = search(p, l)) == NULL) && ((rv = search(p, r)) == NULL) ? true : false;
	//���� valid�� ��ġ���� �ߴµ� ���������� �����ϴ�.
}

//�ϴ� p�� �����ϴ� �� Ȯ���ѵ� �װ� �ڽ��� �ִ��� �������� Ȯ�����ִ� �Լ��Դϴ�.
bool tnode::isleaf(tnode* temp, int val) {  
	return temp->lc == temp->rc ? (temp->lc == NULL ? true : false) : false;
}

void tnode:: treeprint(tnode*p) {   
	if (p != NULL) {
		treeprint(p->lc);         //in order ��ȸ�Դϴ�
		cout<< p->num<<' ';    
		treeprint(p->rc);            
	}
}

int tnode::height(tnode*p) {
	if (p == NULL)
		return 0;
	int lh = height(p->lc);
	int rh = height(p->rc);
	return 1 + (lh > rh ? lh : rh);
}

int tnode::width(tnode* p) {
	if (p == NULL)
		return 0;
	int lw = width(p->lc);
	int rw = width(p->rc);
	int ww = height(p->lc) + height(p->rc);
	return ww > lw ? (ww > rw ? ww : rw) : (lw > rw ? lw : rw); //lw�� rw, lh+hw �� �ִ밪�Դϴ�
}

void tnode::thanos(tnode* p) {
	if (p != NULL) {
		thanos(p->lc);
		thanos(p->rc);
		delete(p);
	}
}