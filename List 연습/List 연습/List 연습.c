#include <stdio.h>
#include "ArrayList.h"

int main() {
	//ArrayList�� ���� �� �ʱ�ȭ //
	List list;
	int data;
	ListInit(&list);
	int i;
	int sum = 0;
	//5���� ������ ����//
	for (i = 1; i <= 9; i++)
		LInsert(&list, i);

	//����� �������� ��ü ���//
	printf("���� �������� �� : %d \n", LCount(&list));

	if (LFirst(&list, &data)) {        //ù��° ������ ��ȸ  LFirst�� LNext�� 1�̳� 0�� ��ȯ
		printf("%d ", data);
		sum += data;

		while (LNext(&list, &data)) {    //�ι�° ������ ������ ��ȸ
			printf("%d ", data);
			sum += data;
		}
	}
	printf("\n\n%d\n\n", sum);

	//���� 22�� Ž���Ͽ� ��� ����//
	if (LFirst(&list, &data)) {
		if (data %2== 0 || data%3 ==0)
			LRemove(&list);
		while (LNext(&list, &data)) {
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
		}
	}

	//���� �� ���� ������ ��ü ���
	printf("���� ���� �������� �� : %d \n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}