#include "maximumeffort.h"
#include <stdlib.h>

tnode* talloc() {      //makes addtree func more shorter
	return (tnode*)malloc(sizeof(tnode));
}


char *strdupli(char *s) {
	char *p;
	p = (char*)malloc(strlen(s) + 1);    //make a new space that can holds characters
	if (p != NULL) 
		strcpy(p, s);                    //put a word in it
	return p;
}

tnode* addtree(tnode *p, char *w) {

	int cond;

	if (p == NULL) {   //if theres no node
		p = talloc();  //make a new one
		p->word = strdupli(w);     //put a word 
		p->count = 1;
		p->left = p->right = NULL;
	}

	else if ((cond = strcmp(w, p->word)) == 0)  //if the word already exists
		p->count++;

	else if (cond < 0)
		p->left = addtree(p->left, w);     //if the word precedes before the current word 
	else
		p->right = addtree(p->right, w);   //if not

	return p;
}

void treeprint(tnode *p) {   //recursive call
	if (p != NULL) {
		treeprint(p->left);         //wont stop till it meets NULL
		printf("%4d %s\n", p->count, p->word);    //if p->left stops, print p's members
		treeprint(p->right);               //and then right, right doesnt stop till it meets NULL either
	}
}


void export(tnode *root) {
  FILE *fp;
  fp=fopen("wordcount.dat","w");

  exportHelper(root, fp);          //recursive call call

  fclose(fp);
}

void exportHelper(tnode *root, FILE *fp) {
  if(root!=NULL) { 
    exportHelper(root->left, fp);     //left
    fprintf(fp, "%4d %s\n", root->count, root->word);   //print to file
    exportHelper(root->right, fp);    //right
  }
}


