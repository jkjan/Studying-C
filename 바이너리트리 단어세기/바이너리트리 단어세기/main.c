#include "maximumeffort.h"

#define MAXWORD 100

tnode* addtree(tnode*, char*);  //predefinition of functions that are used in this main func
void treeprint(tnode*);
int getword(char*, int);
char* strdupli(char* s);
tnode* talloc();
void export(tnode* p);
tnode* load(tnode*, char*, int);

main() {
	tnode* root;                //declare a tnode
	char word[MAXWORD];

	root = NULL;

	FILE* fp = fopen("wordcount.dat", "r");

	if (fp != NULL) {
		int wc;
		char* ss;
		while ((fscanf(fp, "%d %s\n", &wc, ss)) != EOF) {
			root = load(root, ss, wc);
			printf("%d %s\n", wc, ss);
		}

		fclose(fp);
	}

	while (getword(word, MAXWORD) != EOF)  //get a word
		if (isalpha(word[0]))              //if it is an english word
			root = addtree(root, word);    //add tree
	treeprint(root); //print the whole tree nodes

	export(root);


}