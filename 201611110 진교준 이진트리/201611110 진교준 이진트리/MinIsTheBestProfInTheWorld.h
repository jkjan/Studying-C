#ifndef MINisTHEbestPROFinTHEworld
#define MINisTHEbestPROFinTHEworld
#include <iostream>
#include <cstdlib>

using namespace std;


class sinfo {
public:
	char name[7];
	char sex;
	char loc[7];
	char major[13];
	float score;
	int height;
	int weight;
public :
	void infoprint();
};

class node;

typedef struct _getReturn {
	node* searched;
	int lr;
} getReturn;

class node {
public:
	sinfo* info;
	node* lc;
	node* rc;
public :
	void treeprint();
	node* addtree(node* p, sinfo*w);
	getReturn* search(char * name);
	int remove(char * name);
	int isleaf(node*p);
	node * getLeftMax(node*p);
	getReturn* setReturn(node* p, int l);
	node* talloc();
};



bool verify(const std::string& filename);
int line(istream& fp);


#endif

#pragma once
