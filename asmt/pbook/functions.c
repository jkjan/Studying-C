#include "pb.h"

int cnt;
int ccnt;

void infoprint(pbook* info) {
	printf("%s %s %s\n", info->circle, info->name, info->number);     //to print info
}

void treeprint(node *p) {
	if (p != NULL) {
		treeprint(p->lc);
		printf("%s %s %s\n", p->info->circle, p->info->name, p->info->number);   //in order tree print
		treeprint(p->rc);
	}
}

int circleprint(node* p, char * circle) {
	if (p != NULL) {
		circleprint(p->lc, circle);
		if (strcmp(p->info->circle, circle) == 0) {   //if the person is in the circle
			printf("%s %s %s\n", p->info->circle, p->info->name, p->info->number);
			ccnt++;
		}
		circleprint(p->rc, circle);
	}

	return ccnt;
}


node* addtree(node* p, pbook* w) {
	if (p == NULL) {
		p = talloc();  //make a new one
		p->info = w;   
		p->lc = p->rc = NULL;  //had to make sure that i dont reference nptr
		cnt++;                  //data num
	}

	else if (strcmp(w->name, p->info->name) < 0)
		p->lc = addtree(p->lc, w);   //binary tree
	else
		p->rc = addtree(p->rc, w);

	return p;
}

node* search(node* p, char*name) {
	int cond;
	if (p == NULL) {  //none searched
		return NULL;
	}

	if ((cond = strcmp(p->info->name, name))==0) {  //searched
		return p;
	}

	else if (cond > 0)   //binary search tree
		search(p->lc, name);

	else
		search(p->rc, name);
}

int eliminate(node* p, char* name) {
	int cond;

	if ((cond = strcmp(name, p->info->name)) == 0) {
		if (p->lc == NULL && p->rc == NULL)  //if its leaf
			return 1;                        //kill me, parents!
		if (p->lc == NULL && p->rc != NULL) {           //if it doesnt have left child
			p->info = p->rc->info;                      //move data
			p->lc = p->rc->lc;							//connection renewal
			p->rc = p->rc->rc;
			return 0;
		}
		if (p->lc != NULL && p->rc == NULL) {			//with the same process
			p->info = p->lc->info;
			p->lc = p->lc->lc;
			p->rc = p->lc->rc;
			return 0;
		}

		if (p->lc != NULL && p->rc != NULL) {			//if it has both left and right
			p->info = getLeftMax(p->lc)->info;			//copy its left's right most data
			if (eliminate(p->lc, p->info->name) == 1)		//and remove it
				p->lc = NULL;
			return 0;
		}
	}

	else if (cond < 0) {								//if the target is on the left side
		if (p->lc != NULL) {
			if (eliminate(p->lc, name) == 1)				//repeat and the target is a leaf
				p->lc = NULL;							//cut it
		}
		return 0;
	}

	else {
		if (p->rc != NULL) {                           //if the target is on the right side
			if (eliminate(p->rc, name) == 1)				//do the same thing as above
				p->rc = NULL;
		}
		return 0;
	}
}

node *  getLeftMax(node * p) {
	node* max = (node*)malloc(sizeof(node));  
	max = p;

	while (p != NULL) {    //it is the right most element
		max = p;
		p = p->rc;
	}
	return max;
}

node*  talloc() {  //init
	return (node*)malloc(sizeof(node));
}

void export(node* root) {
	FILE* fp;
	fp = fopen("phonebook.txt", "w"); //open a file

	exportHelper(root, fp);          //calls recursive call 

	fclose(fp);
}

void exportHelper(node* root, FILE* fp) {
	if (root != NULL) {
		exportHelper(root->lc, fp);     //left
		fprintf(fp, "%s %s %s\n", root->info->circle, root->info->name, root->info->number);  //write on a file
		exportHelper(root->rc, fp);    //right
	}
}

node* load(node* p, pbook*info) {
	if (p == NULL) {   //if theres no node
		p = talloc();  //make a new one
		p->info = info;
		p->lc = p->rc = NULL;
		cnt++;
	}

	else if (strcmp(info->name, p->info->name) < 0)
		p->lc = load(p->lc, info);     //if the word precedes before the current word 
	else
		p->rc = load(p->rc, info);   //if not

	return p;
}

pbook* setInfo(char* circle, char* name, char* number) {
	pbook* info = (pbook*)malloc(sizeof(pbook));
	strcpy(info->circle, circle);    //get data and pack and return
	strcpy(info->name, name);
	strcpy(info->number, number);

	return info;
}
