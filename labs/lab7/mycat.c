#include <stdio.h>

int main (int argc, char *argv[]) {
	FILE * fp;
	void filecopy(FILE*, FILE*); 

	if (argc == 1)    //if argument count is 1, just repeat what a user types
		filecopy(stdin, stdout);
	else 
		while (--argc>0)              
			if ((fp = fopen(*++argv, "r")) == NULL) {  //if it cannot search the file which is given by argument
				printf("cat : can't open %s\n", *argv);   //print error
				return 1;
			}
			else {
				filecopy(fp, stdout);  //else, execute the function 
				fclose(fp);
			}
		return 0;
}

void filecopy(FILE *ifp, FILE *ofp) {    //file pointers, one is input and the other is output
	int c;
	while ((c = getc(ifp)) != EOF)       //read charcters from input file and
		putc(c, ofp);                //print them to output file
}

