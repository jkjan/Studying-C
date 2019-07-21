#pragma once
#ifndef _MinTheGreat
#define _MinTheGreat
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

using namespace std;

typedef struct _lib {
	char name[7];
	char sex;
	char loc[7];
	char major[13];
	float score;
	int height;
	int weight;
}lib;

typedef struct _node node;

struct _node {
	lib* library;
	_node*lnext;
	_node*rnext;
};

class link {
private:
	int cnt;
	node* nodes;

public:
	//Ŭ���� �� ����ü ����
	link * create();

	//���� ���� Ȯ��
	bool verify(const std::string& filename);

	//���� �о�鿩�� Ŭ���� �� ����ü�� ����
	node *load(istream& fp, link*list, int n);

	//���� �� ���� �ݺ� �� Ƚ�� ��������
	int line(istream& fp);

	//��ü ���
	void print(link*list);
	
	//������ �߰�
	int insert(link*list, node* data);
	
	//������ ����
	int remove(link*list, char* rmv);

	//������ Ž��
	node* search(char*sch, link*list);

	//�� ������ ����
	int save(ofstream&fp, link*data);
};

#endif
#pragma once