#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ca {
	char s[10000];
	char even[10000];
	char odd[10000];
} ch;

int main() {
	int many, i, j;
	int ec = 0;
	int oc = 0;

	scanf("%d", &many);

	if (many < 1 || 10 < many)
		return 0;

	ch *eod = (ch*)malloc(sizeof(ch)*many);

	for (i = 0; i < many; i++) {
		scanf("%s", (eod + i)->s);
		if (strlen((eod + i)->s) < 2 || 10000 < strlen((eod + i)->s))
			return 0;
			for (j = 0; j < strlen((eod + i)->s) + 1; j++) {
				if (j % 2 == 0) {
					strcpy((eod + i)->even + ec, (eod + i)->s + j);
					ec++;
				}
				else {
					strcpy((eod + i)->odd + oc, (eod + i)->s + j);
					oc++;
				}
			}
			ec = 0;
			oc = 0;
	}

	for (i = 0; i < many; i++)
		printf("%s %s\n", (eod + i)->even, (eod+i)->odd);
		//printf("%d\n", strlen((eod+i)->odd));

	free(eod);
	return 0;
}