#include <stdio.h>
int main() {
	FILE * fp = fopen("cal.txt", "wt");
	fputs("this is it?", fp);
	fclose(fp);

	fp = fopen("cal.txt", "rt");
	long fpos;
	int whe;
	int cnt = 0;
	while (1) {
		fpos = ftell(fp);
		fseek(fp, fpos, SEEK_SET);
		

		if (fgetc(fp) == EOF)
			break;

		fpos++;
		cnt++;
	}

	fseek(fp, 1, SEEK_SET);
	printf("%d", cnt);

	fclose(fp);
	return 0;
}