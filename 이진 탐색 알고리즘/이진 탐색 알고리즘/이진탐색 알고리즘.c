#include <stdio.h>
#include <stdlib.h>
#include "testing.h"

int main() {
	int tar, result;
	int*test = input();

	bubble(test, quan);

	printf("\n�� ã�����? : ");
	scanf("%d", &tar);

	result = binsch(test, quan, tar, 0, quan-1);

	for (i = 0; i < quan; i++)
		printf("%d ", *(test + i));

	if (result == -1)
		puts("\n\n�׷� ���� �����ϴ�");
	else
		printf("\n\nã���ô� ���ڴ� %d��°�� �ֽ��ϴ�.", result+1);
}