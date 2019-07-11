#include <stdio.h>
typedef struct fren {
	char name[10];
	char sex;
	int age;
} friend;

int main() {
	FILE *fp;
	friend myfriend1;
	friend myfriend2;

	/*** file write ***/
	fp = fopen("friend.bin", "wb");
	printf("이름, 성별, 나이 순 입력 : ");
	scanf("%s %c %d", myfriend1.name, &(myfriend1.sex), &(myfriend1.age));  //name 이고 sex고 하는 텍스트를 모두 바이너리로 취급
	fwrite((void*)&myfriend1, sizeof(myfriend1), 1, fp);                    //즉, 바이너리 형식으로 구조체 하나를 통째로 저장
	fclose(fp);                                                             //sizeof(myfriend1) * 1 하나만큼의 데이터를 &myfriend1에서 읽어 fp에 저장

	/*** file read ***/
	fp = fopen("friend.bin", "rb");
	fread((void*)&myfriend2, sizeof(myfriend2), 1, fp);                     //&이 붙은 이유는 주소값이 필요하기 때문. 앞에서 그냥
	printf("%s %c %d \n", myfriend2.name, myfriend2.sex, myfriend2.age);    //(void*)buf인 이유는 buf그 자체가 주소이기 때문. (배열 이름 = 주소값)
	fclose(fp);
	return 0;
}