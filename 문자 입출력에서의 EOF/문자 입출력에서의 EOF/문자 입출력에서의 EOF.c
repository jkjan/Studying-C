#include <stdio.h>

int main() {
	int ch;

	while (1) {
		ch = getchar();   //���� �Է�, ���ڿ��� ��. �ѹ��ھ� �ѹ��ھ� �޾Ƶ���
		if (ch == EOF) //EOF : End of File�� ����, ������ ���� ǥ���ϱ� ���� ������ ���� ���.
			break;   
		putchar(ch);  //���� ���ڸ� �״�� ���. 
	}
	return 0;
}

// fgetc(stdin); �� Ctrl + Z �� EOF ��ȯ (Windows ����) - ^Z
// �ֳ��ϸ� Ű���忣 EOF�� �����Ƿ�

//��¿��� �ڵ����� ������ �̷����� ����?
// Hi �ϰ� ���� �Է½� �Ȱ��� Hi ���͸� ����ϴϱ�.  ���͵� ���ڴ�.