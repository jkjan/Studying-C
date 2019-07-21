#include <iostream>
#include <cstring>

char* strcut(char* s, int a, int b) {
	char* r = (char*)malloc(sizeof(b - a + 2));
	int i;
	for (i = 0; a + i <= b; i++) {
		r[i] = *(s + a + i);
	}
	r[i] = '\0';
	return r;
}

int main() {
	char name[] = "baekjoon";
	int len = strlen(name);
	char** jeob = (char**)malloc(sizeof(char*) * len);
	int i;
	for (i = 0; i < len; i++) {
		*(jeob + i) = (char*)malloc(sizeof(char) * (len - i + 1));
	}

	

}