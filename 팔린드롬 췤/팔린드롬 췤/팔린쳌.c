#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

char* strcut(char* s, int a, int b) {
	char* r = (char*)malloc(sizeof(b - a + 2));

	int i;
	for (i = 0; a + i <= b; i++) {
		r[i] = *(s + a + i);
	}

	r[i] = '\0';

	return r;
}

char* pullout(char* s) {

	int len = strlen(s);
	int cnt = 1;

	if (len % 2 == 0) {
		len /= 2;
		while (s[len + cnt - 1] == s[len - cnt]) {
			cnt++;
		}

		return cnt > 0 ? strcut(s, len - cnt + 1, len + cnt - 2) : NULL;
	}
	else {
		len /= 2;
		while (s[len + cnt] == s[len - cnt]) {
			cnt++;
		}
		return cnt > 0 ? strcut(s, len - cnt + 1, len + cnt - 1) : NULL;
	}
}

int main() {
	int num;
	int i, j;

	scanf("%d\n", &num);
	fflush(stdin);

	char pal[20000];

	char** pals = (char**)malloc(sizeof(char*) * num);

	for (i = 0; i < num; i++) {
		*(pals+i) = (char*)malloc(sizeof(char) * 10000);
	}

	for (i = 0; i < num; i++) {
		scanf("%s", pal);
		strcpy(*(pals + i), pullout(pal));
	}

	int max = strlen(*(pals));

	for (i = 0; i < num -1; i++) {
		if (abs(strlen(*(pals + i)) - strlen(*(pals + i + 1))) % 2 != 0 && *(pals + i) == NULL) {
			printf("%d", 0);
			for (int k = 0; k < num; k++)
				free(*(pals + k));
			free(pals);
			return 0;
		}
		else
			max = strlen(*(pals + i)) < max ? strlen(*(pals + i)) : max;
	}

	max = strlen(*(pals + i)) < max ? strlen(*(pals + i)) : max;

	int palcnt = 0;

	int exitOuterLoop = 0;

	if (strlen(*(pals)) % 2 != 0) {
			for (i = 0; i < num - 1; i++) {
				if (*(*(pals + i)+strlen(*(pals + i))/2) != *(*(pals + i + 1)+strlen(*(pals + i + 1))/2)) {
					printf("%d", 0);
					for (int k = 0; k < num; k++)
						free(*(pals + k));
					free(pals);
					return 0;
				}
			}
			
			for (j = 1; j < max; j++) {
				for (i = 0; i < num - 1; i++) {
					if ((*(*(pals + i)+strlen(*(pals + i))/2 - j) == *(*(pals + i + 1)+strlen(*(pals + i + 1))/2 - j)) &&
						(*(*(pals + i + 1) + strlen(*(pals + i + 1)) / 2 - j) == *(*(pals + i)+strlen(*(pals + i))/2 + j)) &&
						(*(*(pals + i) + strlen(*(pals + i)) / 2 + j) == *(*(pals + i+1)+strlen(*(pals + i+1))/2 + j))) {
						palcnt++;
					}
					else {
						exitOuterLoop = 1;
						break;
					}
				}
				if (exitOuterLoop == 1)
					break;
			}

			printf("%d", (j-1)*2+1);
			for (int k = 0; k < num; k++)
				free(*(pals + k));
			free(pals);
			return 0;
	}

	else {
		for (j = 1; j < max; j++) {
			for (i = 0; i < num - 1; i++) {
				if ((*(*(pals + i)+strlen(*(pals + i))/2 + j -1) == *(*(pals + i + 1)+strlen(*(pals + i + 1))/2 + j-1)) &&
					(*(*(pals + i + 1) + strlen(*(pals + i + 1)) / 2 + j - 1) == *(*(pals + i)+strlen(*(pals + i))/2 - j)) &&
					(*(*(pals + i) + strlen(*(pals + i)) / 2 - j) == *(*(pals + i+1)+strlen(*(pals + i+1))/2 - j))) {
					palcnt++;
				}
				else {
					exitOuterLoop = 1;
					break;
				}
			}
			if (exitOuterLoop == 1)
				break;
		}

		printf("%d", (j - 1) * 2);
		for (int k = 0; k < num; k++)
			free(*(pals + k));
		free(pals);
		return 0;
	}
}