#include <stdio.h>

int main() {
	FILE*scr = fopen("01 It's A Long Way To The Top (If You Wanna Rock 'N' Roll).mp3", "rb");
	FILE*des = fopen("howboutthis.mp3", "wb");
	char buf[20];
	int readCnt;

	if (scr == NULL || des == NULL) {
		puts("���Ͽ��� ����!");
		return -1;
	}

	while (1)
	{
		readCnt = fread((void*)buf, 1, sizeof(buf), scr);   //scr�� ���̳ʸ��� 1���ϱ� bufũ��(20)��ŭ ���� �ؼ� buf�� ����
		fwrite((void*)buf, 1, sizeof(buf), des);    //buf�� buf�� size ���ϱ� 1��ŭ des�� ����

		if (readCnt < sizeof(buf)) { //������ ���� ����Ʈ �о���̱� �� �ʿ� (20��ŭ �� �о��� ��. ���� 121�ε� 20��ŭ 6�� �а�)
			if (feof(scr) != 0) {		//���� ���� ��� 0�ƴ� �� ��ȯ	    	���� �����Ͱ� 1���� ��
				fwrite((void*)buf, 1, readCnt, des);   //���� ��ŭ(readCnt ũ�⸸ŭ) ����
				puts("���Ϻ��� �Ϸ�");
				break;
			}
			else
				puts("���Ϻ��� ����");

			break;
		}
		
	}	

	fclose(scr);
	fclose(des);
	return 0;
}