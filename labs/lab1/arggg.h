
#ifndef argg  //if argg isnt defined
#define argg  // define argg

//header file insert
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quick(void *s[], int l, int r, int(*comp)(void *, void *)); //function declare
void swap(void *s[], int a, int b);
int numcmp(char*a, char*b);

#endif
