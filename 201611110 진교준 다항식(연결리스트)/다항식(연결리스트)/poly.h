#ifndef LINKED
#define LINKED
#include <stdio.h>

class hang {
public:
	int coef; //���
	int exp;  //����
	hang* next;
	void setHang(int c, int e, hang* next);
};

class poly {
private :
	hang* head; //�׵��� ���Ḯ��Ʈ
	hang* tail;
public :
	//void load(FILE*fp);
	void zero(); //0¥�� ����
	int isZero(); //0���� Ȯ�� (������ �ֳ� ����?)
	int coef(int e); //������ e�� ���� ��� ����
	int leadExp(); //�ְ������� ���� ����
	void append(int c, int e); //cx^e�� �������� �߰�
	void insert(int c, int e); //cx^e�� ������ ��ġ�� ����

	void add(poly *A, poly *B);
	void multi(poly* A, poly *B);
	void pprint();
};

void load(FILE*fp);

#endif