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

class info {
private:
	int num;
	int cnt;
	lib * library;

public:
	//Ŭ���� �� ����ü ����
	lib * create(info* list, int n);        

	//���� ���� Ȯ��
	bool verify(const std::string& filename);

	//���� �о�鿩�� Ŭ���� �� ����ü�� ����
	lib *load(istream& fp, info*list, int n);

	//���� �� ���� �ݺ� �� Ƚ�� ��������
	int line(istream& fp);

	//��ü ���
	void print(info*list);

	//������ �߰�
	int insert(info*list, lib* data);

	//������ ����
	int remove(info*data, char* rmv);

	//������ Ž��
	int search(char*sch, info* data, int n, int first, int last);

	//�� ������ ����
	int save(ofstream&fp, info*data);
};

#endif
#pragma once