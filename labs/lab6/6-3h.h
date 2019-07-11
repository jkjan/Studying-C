#ifndef dave
#define dave

#include <stdio.h>   //used universally
#include <ctype.h>   //used in more than 2 files
#define MAXWORD 100

typedef struct _key {
		char *word;
		int count;
} key;

extern key keytab[32]; //to allow accessing from anywhere
extern int i;

#endif
