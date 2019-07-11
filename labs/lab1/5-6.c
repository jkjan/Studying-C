#include <stdio.h>

int main(int argc, char *argv[]) { //option input

	for (int i = argc - 1; i > 0; i--) {
		printf("%s ", *(argv+i)); //i should be added because its purpose is to print words 
	}                                 //backward
	printf("\n");

	return 0;
}
