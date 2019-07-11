#include <stdio.h>
#include <string.h>

int main() {
	FILE*fp1 = fopen("d1.txt", "wt");
	FILE*fp2 = fopen("d2.txt", "wt");

	fputs("All work and no play makes Jack a dull boy.", fp1);
	fputs("All work and no play makes Jack a dull boy.", fp2);

	fclose(fp1);
	fclose(fp2);

	fp1 = fopen("d1.txt", "rt");
	fp2 = fopen("d2.txt", "rt");

	char text1[50], text2[50];

	fgets(text1, 50, fp1);
	fgets(text2, 50, fp2);

	if (strcmp(text1, text2) == 0)
		puts("같습니다");
	else
		puts("다릅니다");

	fclose(fp1);
	fclose(fp2);

	return 0;
}