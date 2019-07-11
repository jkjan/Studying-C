#include <stdio.h>

int main (int argc, char *argv[]) {
	FILE * ifp = fopen(*++argv, "r");
	FILE * ofp = fopen(*++argv, "w");

	void filecopy(FILE*, FILE*);

	if (argc == 1)   //if argument count is just 1
		filecopy(stdin, stdout); //it just repeats what a user types
	else if (argc != 3) {  //argc should be 3 : command name, a file name which will be used as an input, and out an output
		puts("this commend needs two arguments");
		exit(1);
	}	

	else {
		if (ifp == NULL || ofp == NULL) {  //if failed to open the files
			puts("failed to open files");
			exit(2);
		}
		else
			filecopy(ifp, ofp);  //execute filecopy
	}
	exit(0);
}


void filecopy(FILE*ifp, FILE *ofp) {   //file pointers : one is input and the other is output
	int c;
	while ((c = getc(ifp)) != EOF)   //get charcters from input file
		putc(c, ofp);            //and print them to output file
}
