#include <stdio.h>

int printsent(char**s);

int printnums(int *v);

int main() {

	char *s[] = { "This", "isdas", "aasa", "test" };

	int v[][5] = {{1, 2, 3, 4, 5},
				  {6, 7, 8, 9, 0}
	};


	printsent(s);

	printnums(v);

	return 0;
}

int printsent(char**s) {
	for (int i = 0; i < 4; i++)
		printf("%s ", *(s + i));   //�� �ܾ� ���
	printf("\n");

	for (int i = 0; i < 4; i++)
		for (int j = 0; j< 2; j++)
		printf("%c ", *(s + i)[j]);  //�� �ܾ���� ù���� ��� 
	printf("\n");
}

int printnums(int *v) {
	for (int i = 0; i < 5; i++)
		printf("%d ", *(v+1*5 + i) );   //�ι�° ���� ��� �� ���

	return 0;
}
