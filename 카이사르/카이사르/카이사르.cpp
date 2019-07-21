#include <iostream>
#include <cstring>
int main() {
	char ca[1001];
	scanf(" %s", ca);
	int clen = strlen(ca);
	for (int i = 0; i < clen; i++) {
		printf("%c", ca[i] - (ca[i] <= 67? -23 : 3));
	}
	return 0;
}