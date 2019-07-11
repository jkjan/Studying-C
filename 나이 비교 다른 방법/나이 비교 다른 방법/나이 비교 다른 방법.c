#include <stdio.h>
#include <string.h>


int main() {
	char ch1[100], ch2[100];
	fgets(ch1, sizeof(ch1), stdin); //이름과 나이 입력 받기
	fgets(ch2, sizeof(ch2), stdin);

	int len1 = strlen(ch1);  //길이 얻기
	int len2 = strlen(ch2);

	char cdec1[20], cdec2[20];  //숫자만 빼내서 저장하기 위함
	char *fp1 = cdec1;
	char *fp2 = cdec2;

	for (int i = 0; i < len1; i++) {         //ch1 배열을 처음부터 끝까지 뒤졌을 때
		if (ch1[i] == ' ') {				 //공백이 나오면
			for (int j = i + 1; j < len1 - 1; j++) {    //그 다음 문자부터 끝에까지를
				*fp1 = ch1[j];                          //fp1 주소값에 저장, 즉 cdec1 배열에 저장.
				fp1++;                                  //fp1 주소 이동. ch1의 다음 문자 받기 위함.
			}
		}
	}

	for (int i = 0; i < len2; i++) {       //위의 것을 ch2에도 동일 적용.
		if (ch2[i] == ' ') {
			for (int j = i+1; j < len2-1; j++) {
				*fp2 = ch2[j];
				fp2++;
			}
		}
	}

	*fp1 = '\0';							//cdec1, 2는 초기화된 배열 아니므로 비교시 문제가 생김 따라서 나이만 얻으면 바로 끊어버렸음.
	*fp2 = '\0'; 

	// int lenf1 = strlen(cdec1);               나는 이 프로그램을 진작 완성했음에도 불구하고 
	// int lenf2 = strlen(cdec2);				len을 계속 앞에다가만 둬서 오류 출력 때 잘리기 전의 cdec1 을 자꾸 불러서 틀린 줄 알았음.

/*	for (int i = 0; i < lenf1; i++)
		printf("%c ", cdec1[i]);
	printf("\n");
	for (int i = 0; i < lenf2; i++)
		printf("%c ", cdec2[i]); */

	printf("%d",strcmp(cdec1,cdec2));

	return 0;
}