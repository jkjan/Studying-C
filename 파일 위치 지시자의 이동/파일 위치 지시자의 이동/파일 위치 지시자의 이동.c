#include <stdio.h>
int main() {
	/*���� ����*/
	FILE * fp = fopen("text.txt", "wt");
	fputs("123456789", fp);
	fclose(fp);

	/*���� ����*/
	fp = fopen("text.txt", "rt");

	/* SEEK_END test */
	fseek(fp, -2, SEEK_END);   //������ �� ĭ. ��ǻ� EOF �����ϹǷ� �� ĭ��.
	putchar(fgetc(fp));

	/* SEEK_SET test */        //�� �տ��� �� ĭ.
	fseek(fp, 2, SEEK_SET);    
	putchar(fgetc(fp));        //����ϴ� ���� 4�� ��. �� ĭ �̵�.

	/* SEEK_CUR test */        //���� ��ġ���� �� ĭ.
	fseek(fp, 2, SEEK_CUR);
	putchar(fgetc(fp));

	fclose(fp);
	return 0;
}
