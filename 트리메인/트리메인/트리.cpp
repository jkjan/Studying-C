#include "maximumeffort.h"
#include <stdlib.h>

tnode* tnode:: talloc() {      //makes addtree func more shorter
	return (tnode*)malloc(sizeof(tnode));
}

tnode* tnode:: addtree(tnode *p, int r, int lc, int rc) {

	int cond;

	if (p == NULL) {   //if theres no node
		p = talloc();  //make a new one
		p->num = r;     //put a word 
		p->count = 1;
		p->left = p->right = NULL;
	}

	p->left = addtree(p->left, lc);     //if the word precedes before the current word 
	p->right = addtree(p->right, rc);   //if not

	return p;
}

void tnode:: treeprint() {   //recursive call
	if (this-> != NULL) {
		treeprint(p->left);         //wont stop till it meets NULL
		printf("%4d %s\n", p->count, p->word);    //if p->left stops, print p's members
		treeprint(p->right);               //and then right, right doesnt stop till it meets NULL either
	}
}
