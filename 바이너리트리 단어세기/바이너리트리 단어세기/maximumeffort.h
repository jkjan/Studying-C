#ifndef sss
#define sss
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct _tnode {     //the tree node
	char* word;   //points to the text
	int count;     //number of occurrences
	struct _tnode* left;     //left child
	struct _tnode* right;    //right child
};

typedef struct _tnode tnode; //to make easy and quick when using this struct next time
#endif
#pragma once
