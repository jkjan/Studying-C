#include "seven.h"

int main() {
	shorty* nine = (shorty*)malloc(sizeof(shorty));

	nine->num = 0;
	nine->cur = 0;

	int sum = 0;
	int them;
	int data;
	int i, j;

	for (i = 0; i < 9; i++) {
		scanf("%d", &them);
		input(nine, them);
		sum += them;
	}
	
	/*
	input(nine, 20);
	input(nine, 0);
	input(nine, 23);
	input(nine, 17);
	input(nine, 12);
	input(nine, 15);
	input(nine, 25);
	input(nine, 8);
	input(nine, 20);
	*/
	int temp;
	
	for (i = 0; i < 8; i++) {
		for (j = 1; j < 9-i; j++) {
			if (nine->name[j-1] > nine->name[j]) {
				temp = nine->name[j-1];
				nine->name[j-1] = nine->name[j];
				nine->name[j] = temp;
			}
		}
	}


	//cout << "\n\n";
	/*
	if ((data = first(nine)) != -1) {
		cout << data << endl;
		while ((data = next(nine)) != -1)
			cout << data << endl;
	}
	*/

	shorty origin = *nine;

	sum = sum - 100;
	//cout << sum << endl;


	no* two = (no*)malloc(sizeof(no) * 36);
	two->num = 0;
	//int twocnt = 0;

	for (i = 0; i < 8; i++) {
		for (j = i + 1; j < 9; j++) {
			if (nine->name[i] + nine->name[j] == sum) {
				(two + two->num)->dont[0] = nine->name[i];

				(two + two->num)->dont[1] = nine->name[j];
				//printf("%d번째 경우 : (%d, %d)\n", two->num + 1, nine->name[i], nine->name[j]);
				two->num++;
			}
		}
	}

	//cout << two->dont[0] << endl;
	//cout << two->dont[1] << endl;

	/*
	if ((data = first(nine)) != -1) {
		if (data == 15 || data == 25)
			remove(nine);
		while ((data = next(nine)) != -1) {
			if (data == 15 || data == 25)
				remove(nine);
		}
	}

	if ((data = first(nine)) != -1) {
		cout << data << endl;
		while ((data = next(nine)) != -1)
			cout << data << endl;
	}
	*/
	for (i = 0; i < two->num; i++) {
		*nine = origin;
		//printf("i는 %d, num은 %d\n", i, two->num);

		if ((data = first(nine)) != -1) {
			//printf("i는 %d, num은 %d\n", i, two->num);
			if (data == (two + i)->dont[0] || data == (two + i)->dont[1])
				remove(nine);
			//cout << i << endl;
			while ((data = next(nine)) != -1) {
				//printf("i는 %d, num은 %d\n", i, two->num);
				if (data == (two + i)->dont[0] || data == (two + i)->dont[1])
					remove(nine);
				//cout << i << endl;
			}
		}

		//printf("i는 %d, num은 %d\n", i, two->num);

		if ((data = first(nine)) != -1) {
			printf("%d\n", data);
			while ((data = next(nine)) != -1)
				printf("%d\n", data);
		}

		printf("\n");
		
		//printf("i는 %d, num은 %d\n", i, two->num);
	}
	return 0;
}