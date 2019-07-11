#include <stdio.h>
int main() {
	char*str = "Simple String";

	printf("1. puts test ------ \n");    
	puts(str);                                       //puts는 개행 이뤄지지만 fputs는 안 함.
	puts("So Simple String");

	printf("2. fputs test ----- \n");
	fputs(str, stdout); printf("\n");          //개행 해줘야 함.
	fputs("So Simple String", stdout /*모니터로 출력 */); printf("\n");

	printf("3. end of main -----\n");
	return 0;
}