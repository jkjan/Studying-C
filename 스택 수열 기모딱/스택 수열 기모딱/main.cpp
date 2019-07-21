#include "sex.h"

int main() {

	stack mia;
	stack*acc = &mia;


	acc = mia.init();

	int till;
	int h = 1;
	int j;

	cin >> till;

	int shit[5]= {1,2,5,3,4};

	int * list = shit;

	//for (int i = 0; i < 8; i++)
	//	*(list + i) = i + 1;

	for (j = 1; j <= *list; j++)
		mia.push(acc, j);
	mia.pop(acc);

	for (h = 1; h < 5; h++) {
		if (*(list + h) < *(list + h - 1)) {
			while (mia.top(acc) >= *(list + h)) 
					mia.pop(acc);
		}

		else {
			while (j <= *(list + h)) {
				mia.push(acc, j);
				j++;
			}
			mia.pop(acc);
		}
	}

	return 0;
}