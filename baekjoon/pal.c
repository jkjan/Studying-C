#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* strcut (char*s, int a, int b) {
	char *r = (char*)malloc(sizeof(b-a+1));
	int i;
	for (i= 0; a-i<=b; i++) {
		r[i] = *(s+a-i);
	}
	
	r[i] = '\0';

	return r;
}

int main () {
	int cnt = 0;

	int num;
	int c;
	scanf("%d\n", &num);
	fflush(stdin);

	char pal[100];

	char * name;

	for (int i = 0; i<num; i++) {
		c = 1;	
		cnt = 0;
		scanf("%s\n", pal);
		int len = strlen(pal)/2;
		while (pal[len+c] == pal[len-c]) {
			cnt++;
		}
		name = strcut(pal, len-cnt, len+cnt);
		printf("%s", name);		
	}
	return 0;
}


