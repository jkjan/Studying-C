#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) { //option input

	

	if (strcmp(*(++argv), "-r") == 0) {
		for (int i = argc - 2; i > 0; i--) {
			printf("%s ", *(argv+i)); //i should be added because its purpose is to print words 
		}                                 //backward
		printf("\n");
	}

	else {
		for (int i = 0; i < argc-1; i++)
			printf("%s ", *(argv+i));
		printf("\n");
	}

	return 0;
}
