#include <iostream>
#include <cstring>
#include <cstdlib>

char cen[] = "ABCDEGIMR";

int isin(char a, int s, int e) {
	int m = (s + e) / 2;

	if (cen[m] == a) {
		return 1;
	}

	else if (s >= e && cen[m] != a) {
		return 0;
	}

	else if (cen[m] > a) {
		isin(a, s, m - 1);
	}

	else 
		isin(a, m + 1, e);
}

int main() {
	char cen[100];
	
	scanf(" %s", cen);
	int clen = strlen(cen);
	
	char* cened = (char*)malloc(sizeof(char) * clen);
	
	int cur = 0;

	for (int i = 0; i < clen; i++) {
		if (isin(cen[i], 0, 8) == 0) {
			cened[cur] = cen[i];
			cur++;
		}
	}
	cened[cur] = '\0';
	printf("%s", cened);

	free(cened);
	
	return 0;
}