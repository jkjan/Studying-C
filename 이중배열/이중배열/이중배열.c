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
		printf("%s ", *(s + i));   //각 단어 출력
	printf("\n");

	for (int i = 0; i < 4; i++)
		for (int j = 0; j< 2; j++)
		printf("%c ", *(s + i)[j]);  //각 단어들의 첫글자 출력 
	printf("\n");
}

int printnums(int *v) {
	for (int i = 0; i < 5; i++)
		printf("%d ", *(v+1*5 + i) );   //두번째 행의 모든 값 출력

	return 0;
}
