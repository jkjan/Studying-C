#include <stdio.h>
int main() {
	char*str = "Simple String";

	printf("1. puts test ------ \n");    
	puts(str);                                       //puts�� ���� �̷������� fputs�� �� ��.
	puts("So Simple String");

	printf("2. fputs test ----- \n");
	fputs(str, stdout); printf("\n");          //���� ����� ��.
	fputs("So Simple String", stdout /*����ͷ� ��� */); printf("\n");

	printf("3. end of main -----\n");
	return 0;
}