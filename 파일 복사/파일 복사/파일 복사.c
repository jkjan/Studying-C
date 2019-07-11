#include <stdio.h>
int main() {
	FILE*fp1 = fopen("easy.txt", "rt");
	FILE*fp2 = fopen("easy copy.txt", "wt");
	char cop[100];

	while (fgets(cop, sizeof(cop), fp1) != NULL)
		fputs(cop, fp2);

	if (feof(fp1) != 0)
		puts("complete");
	else
		puts("failed");

	fclose(fp1);
	fclose(fp1);
	return 0;

}