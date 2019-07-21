#ifndef avengers
#define avengers
#include <iostream>

using namespace std;

class tnode {
private:
	int num;
	tnode* lc;
	tnode* rc;
public:
	void init();
	tnode* addtree(tnode* p, int val, int l, int r);  //insert�� addtree�� addnode�� ���� �����߽��ϴ�
	tnode* addnode(int val);
	tnode* valid(tnode* p, int val, int l, int r);
	tnode* search(tnode *p, int val);

	bool checkrulethree(tnode* p, int l, int r);
	bool isleaf(tnode*p, int cval);

	void treeprint(tnode*p);
	int height(tnode*p);
	int width(tnode*p);

	void thanos(tnode* p);
};

bool verify(const std::string& filename);
int line(istream& fp);

#endif
#pragma once