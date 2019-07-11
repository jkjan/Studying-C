#include <stdio.h>

int dayofmonth(int year, int month, int day, int** cal) {
	int y = 0;

	int days = 0;
	
	//determine if its a leap year 
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		y = 1;
	
	//adding month's days till the (n-1)th month
	for (int i = 1; i < month; i++)
		days = days + *(cal + y * 13 + i);

	//add remained day
	days += day;


	return days;
}

int monthday(int year, int day, int* cal) {
	int y = 0;
	int i = 1;

	int month = 0;

	//determine if its a leap year 
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		y = 1;


	//till it cannot substract from day 
	while (day > 0) {
		day -= *(cal + y * 13 + i);

		//month counts
		month++;
		i++;
	}

	day += *(cal + y * 13 + i - 1);  //because it substracted once more to compare day with 0

	printf("%d ", month);
	printf("%d\n", day);

	return 0;
}


int main() {
	int daytab[2][13] = {
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};

	int y = 0;

	//dayofmonth test printing
	printf("2019 4 15 is %d\n", dayofmonth(2019, 4, 15, daytab));
	printf("2000 4 15 is %d\n", dayofmonth(2000, 4, 15, daytab));




	//monthday test printing
	monthday(2019, 200, daytab);
	monthday(2000, 200, daytab);


	return 0;
}


