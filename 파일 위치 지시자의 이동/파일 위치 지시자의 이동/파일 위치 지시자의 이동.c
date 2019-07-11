#include <stdio.h>
int main() {
	/*파일 생성*/
	FILE * fp = fopen("text.txt", "wt");
	fputs("123456789", fp);
	fclose(fp);

	/*파일 개방*/
	fp = fopen("text.txt", "rt");

	/* SEEK_END test */
	fseek(fp, -2, SEEK_END);   //끝에서 두 칸. 사실상 EOF 포함하므로 한 칸임.
	putchar(fgetc(fp));

	/* SEEK_SET test */        //맨 앞에서 두 칸.
	fseek(fp, 2, SEEK_SET);    
	putchar(fgetc(fp));        //출력하는 순간 4로 감. 한 칸 이동.

	/* SEEK_CUR test */        //현재 위치에서 두 칸.
	fseek(fp, 2, SEEK_CUR);
	putchar(fgetc(fp));

	fclose(fp);
	return 0;
}
