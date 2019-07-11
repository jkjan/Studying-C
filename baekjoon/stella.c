#include <stdio.h>
#include <stdlib.h>

typedef struct _score {  
	int qs;   //solved questions
	int ps;   //penalty scores
}score;

void swap(score* a, score* b) {  //a typical swapping function
	score temp = *a;
	*a = *b;
	*b = temp;
}

bubble(score* a, int n) { //a typical bubble sorting function
	int sorted = 1;
	for (int i = n - 1; i >= 1; i--) {
		sorted = 0;
		for (int j = 0; j < i; j++) {
			if ((a + j)->qs < (a + j + 1)->qs) {
				swap(a + j, a + j + 1);
				sorted = 1;
			}
		}
		if (!sorted)
			break;
	}
}

int main() {
	int num;
	scanf("%d", &num);  //lines

	score *shake = (score*)malloc(sizeof(score)*num);
	
	for (int i = 0; i < num; i++)  //input
		scanf("%d %d", &((shake + i)->qs), &((shake + i)->ps));
	
	bubble(shake, num); //ascending order

	int cnt = 0;  //counting variable initiating

	int q = (shake + 4)->qs;

	for (int i = 4; i < num; i++)   //why i starts with 4? in case of the num is 5
		if ((shake + i)->qs == q)
			cnt++;

	printf("%d\n", cnt - 1);  //since the answer is the number of people who
                                  //is NOT 5 ranked but have same number of questions 					  //solved with that of 5 ranked one. 
	return 0;
}
