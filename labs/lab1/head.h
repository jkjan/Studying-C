//to avoid macro crash, if the header file isn't defined
#ifndef _excitingc

//define it
#define _excitingc

//_excitingc says : 
#include <stdio.h>
#include <stdlib.h>

#define maxop 100 // max size of operand or operator
#define number '0'

//function declare
int getop(char[]);
void push(double);
double pop(void);

//the end of if
#endif
