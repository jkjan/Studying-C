#ifndef dave
#define dave

#include <stdio.h>
#include <ctype.h>
#define MAXWORD 100

typedef struct _key {
		char *word;
		int count;
} key;

extern key keytab[32];
extern int i;

#endif

#pragma once
