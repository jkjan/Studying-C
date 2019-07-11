#include <stdio.h>

typedef struct _score {
	int qs;
	int ps;
}score;


void swap(score* a, score* b) {
	score temp = *a;
	*a = *b;
	*b = temp;
}

bubble(score* a, int n) {
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			if ((a + j)->qs < (a + j + 1)->qs) {
				swap(a + j, a + j + 1);
			}
		}
	}
}

int main() {
	int num=5;
	scanf("%d", &num);

	score *shake = (score*)malloc(sizeof(score)*num);
	
	for (int i = 0; i < num; i++) 
		scanf("%d %d", &((shake + i)->qs), &((shake + i)->ps));
	
	bubble(shake, num);

	int cnt = 0;

	int q = (shake + 4)->qs;

	for (int i = 4; i < num; i++)
		if ((shake + i)->qs == q)
			cnt++;

	printf("%d", cnt - 1);

	return 0;
}