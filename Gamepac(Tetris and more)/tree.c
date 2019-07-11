#include "treeheader.h"

extern int o;
extern WINDOW * recordboard;

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

int search(tnode* p, char*name) {
	int cond;
	if (p != NULL) {  //none searched
		search(p->left, name);
		if (strcmp(name, p->word) == 0)
			return 1;
		search(p->right, name);
	}
	//return 0;
}

tnode* addtree(tnode *p, char *w, int s, int speed) {

	if (p == NULL) {   //if theres no node
		p = talloc();  //make a new one
		p->word = strdupli(w);     //put a word 
		p->count = s;
		p->level = speed;
		p->left = p->right = NULL;
	}

	
	else if (s > p->count)
		p->left = addtree(p->left, w, s, speed);     //if the word precedes before the current word 
	else
		p->right = addtree(p->right, w, s, speed);   //if not

	return p;
}

tnode* load(tnode *p, char *w, int c, int l) {
	if (p == NULL) {   //if theres no node
		p = talloc();  //make a new one
		p->word = strdupli(w);     //put a word 
		p->count = c;              //count
		p->level = l;
		p->left = p->right = NULL;
	}

	else if (c > p->count)
		p->left = load(p->left, w, c, l);     //if the word precedes before the current word 
	else
		p->right = load(p->right, w, c, l);   //if not

	return p;
}

void treeprint(tnode *p) {   //recursive call
	if (p != NULL && o<=16) {
		treeprint(p->left);         //wont stop till it meets NULL
		mvwprintw(recordboard, o, 3, "%-2d    %-4s     %d    %-4d", o-6 ,  p->word, p->level ,p->count);    //if p->left stops, print p's members
		o++;
		treeprint(p->right);               //and then right, right doesnt stop till it meets NULL either
	}
	
}


void export(tnode *root) {
  FILE *fp;
  fp=fopen("tetrisscores.txt","w");

  exportHelper(root, fp);          //recursive call call

  fclose(fp);
}

void exportHelper(tnode *root, FILE *fp) {
  if(root!=NULL) { 
    exportHelper(root->left, fp);     //left
    fprintf(fp, "%s %d %d\n", root->word, root->level, root->count);   //print to file
    exportHelper(root->right, fp);    //right
  }
}
