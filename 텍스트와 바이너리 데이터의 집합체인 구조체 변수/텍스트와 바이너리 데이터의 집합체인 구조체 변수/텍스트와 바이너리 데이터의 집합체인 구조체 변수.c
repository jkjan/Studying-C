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
	printf("�̸�, ����, ���� �� �Է� : ");
	scanf("%s %c %d", myfriend1.name, &(myfriend1.sex), &(myfriend1.age));  //name �̰� sex�� �ϴ� �ؽ�Ʈ�� ��� ���̳ʸ��� ���
	fwrite((void*)&myfriend1, sizeof(myfriend1), 1, fp);                    //��, ���̳ʸ� �������� ����ü �ϳ��� ��°�� ����
	fclose(fp);                                                             //sizeof(myfriend1) * 1 �ϳ���ŭ�� �����͸� &myfriend1���� �о� fp�� ����

	/*** file read ***/
	fp = fopen("friend.bin", "rb");
	fread((void*)&myfriend2, sizeof(myfriend2), 1, fp);                     //&�� ���� ������ �ּҰ��� �ʿ��ϱ� ����. �տ��� �׳�
	printf("%s %c %d \n", myfriend2.name, myfriend2.sex, myfriend2.age);    //(void*)buf�� ������ buf�� ��ü�� �ּ��̱� ����. (�迭 �̸� = �ּҰ�)
	fclose(fp);
	return 0;
}