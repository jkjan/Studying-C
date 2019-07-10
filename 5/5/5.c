#include <stdio.h>


char*expand(char* s1, char*s2);

int main() {

	char original[4];
	scanf("%s", original);

	char expanded[100];

	expand(original, expanded);

	printf("%s", expanded);
	

	return 0;
}

char*expand(char* s1, char*s2) {
	char s, e;
	int j =0;
	s = s1[0];
	e = s1[2];
	
	for (int i = s; i <= e; i++) {
		s2[j] = i;
		j++;
	}

	s2[j] = 0;

	return s2;

}

