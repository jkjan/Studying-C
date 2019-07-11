#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char*line, int max);

/* find : print lines that match pattern from 1st arg */

int main (int argc, char *argv[]) {
	char line[MAXLINE];

	int found = 0;

	//argc has to be 2
	if (argc != 2) 
		printf("Usage : find pattern\n");
	else
		while (getline(line, MAXLINE) > 0 )
			if (strstr(line, argv[1]) != NULL ) {   
                       //does the string B exist in the string A? if so, where?
				printf("%s", line);
				found++;
			}
	return found;
}


int getline(char*line, int max) {
	
}


//ls -l -a
//ls -la
//ls -a -l   options
