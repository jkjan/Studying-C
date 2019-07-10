//선행처리기 영역

#include <stdio.h> //이것도 매크로다. stdio.h라는 헤더파일의 코드를 여기다 갖다놓으라는 뜻이다. 참고로 코드가 겁.나.깁.니.다.
#define MAX(a, b) ((a>b) ? (a):(b))


//컴파일의 시작
int main() {
	int num1, num2, max;
	scanf("%d", &num1);
	scanf("%d", &num2);
	max = MAX(num1, num2);

	printf("%d", max);


}