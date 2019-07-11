#include "arggg.h"

int main (int argc, char *argv[] ) {

	int num = 0;

	if (strcmp(*(++argv), "-n") == 0)     //option
		 num = 1;

	char **what = (char**)malloc(sizeof(char*)*(argc-1-num)); //initializing a string array

	for (int i = 0; i < argc-1; i++)
		*(what+i) = (char*)malloc(sizeof(char)*100);   

	for (int i = 0; i < argc - 1-num; i++)           //making a same array w argv
		strcpy(*(what+i), *(argv+num+i));  

	quick((void**)what, 0, argc-2, (int(*)(void*, void*))(num ? numcmp : strcmp));    //quick sort, but with a function pointer

	for (int i = 0; i < argc-1-num; i++)  //printing sorted strings
		printf("%s ", *(what+i+num));
	printf("\n");

	return 0;
}


