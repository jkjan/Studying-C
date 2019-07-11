#ifndef sss
#define sss

#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

struct tnode {     //the tree node
	char *word;   //points to the text
	int count;     //number of occurrences
	int level;
	struct tnode *left;     //left child
	struct tnode *right;    //right child
};

typedef struct tnode tnode; //to make easy and quick when using this struct next time

tnode* talloc();
char *strdupli(char *s);
tnode* addtree(tnode *p, char *w, int score, int level) ;
tnode* load(tnode *p, char *w, int c, int level);
void treeprint(tnode *p);
void export(tnode *root);
void exportHelper(tnode *root, FILE *fp);
int search(tnode* p, char*name);

#endif
