#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

	char s[10]="a11472o5t6";
	//fgets(s, sizeof(s), stdin);

	int nums[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int *ptr = nums;
	
	for (int i = 0; i < 10; i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			int a = s[i];
			//*(ptr + a) += 1;
			printf("%d", a);
		}
	}

	

	//for (int i = 0; i < 10; i++)
		//printf("%d ", nums[i]);

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}
