#include <stdio.h>
void ClearLineFromReadBuffer() {
	while (getchar() != '\n');  //입력버퍼가 문자열의 끝까지 읽고 그냥 지워버린다.
}								//왜냐면 int ch = getchar(); 라 안 하고 그냥 선언됐으므로
								//어디다가 저장돼야 하는지 안 나왔다. 따라서 아예 저장이 안 됨.

int main() {
	char perID[7];
	char name[10];

	fputs("주민번호 앞 6자리 입력: ", stdout);
	fgets(perID, sizeof(perID), stdin);
	ClearLineFromReadBuffer(); //입력버퍼 지우기.

	fputs("이름 입력: ", stdout);
	fgets(name, sizeof(name), stdin);

	printf("주민번호: %s \n", perID);
	printf("이름: %s \n", name);

}