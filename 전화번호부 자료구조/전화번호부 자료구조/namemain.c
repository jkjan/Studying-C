#include <stdio.h>
#include "namecard.h"
#include "arrlist.h"

int main() {
	int i;
	List list;
	card* cardi;
	Ldata data;
	init(&list);
	char name[30], phone[30];
	
	cardi = make("������", "010-1111-2222");
	insert(&list, cardi);
	cardi = make("������", "010-2222-5555");
	insert(&list, cardi);
	cardi = make("������", "010-3333-7777");
	insert(&list, cardi);

	/*
	if (first(&list, &data))
		show(data);
	printf("\n");
	while (next(&list, &data)) {
		show(data);
		printf("\n");
	}
	*/
	

	//������ ã�Ƽ� ���
	if (first(&list, &data)) {           //���� ���� &�� ���δ� ��? arr�� int���̹Ƿ�. �ް����� ����ü ���� �ν��ϹǷ�
		i=comp(data, "������");          //���̻� &�� ���� �ʿ� ����.
		if (i == 0)
			show(data);
	}
	printf("\n");
	while (next(&list, &data)) {
		i = comp(data, "������");
		if (i == 0)
			show(data);
		printf("\n");
	}


	//������ ã�Ƽ� ��ȣ ����
	if (first(&list, &data)) {
		i = comp(data, "������");
		if (i == 0)
			change(data,"010-4444-7777");
	}
	while (next(&list, &data)) {
		i = comp(data, "������");
		if (i == 0)
			change(data, "010-4444-7777");
	}


	//������ ã�Ƽ� ����
	if (first(&list, &data)) {
		i = comp(data, "������");
		if (i == 0) {
			remove(&list);
			free(data);
		}
	}
	while (next(&list, &data)) {
		i = comp(data, "������");
		if (i == 0) {
			remove(&list);
			free(data);
		}
	}


	//��ü ���
	if (first(&list, &data))
		show(data);
	printf("\n");
	while (next(&list, &data)) {
		show(data);
		printf("\n");
	}





}