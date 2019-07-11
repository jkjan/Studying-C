#ifndef pb
#define pb
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _pbook {
	char circle[30];
	char name[30];
	char number[15];
} pbook;

struct _node {
	pbook* info;
	struct _node* lc;
	struct _node* rc;
};

typedef struct _node node;

void infoprint(pbook* info);   //it prints data
void treeprint(node* p);       //in order print
int circleprint(node* p, char * circle);
node* addtree(node* p, pbook* w); //add
int eliminate(node* p, char* name);  //remove
node* getLeftMax(node* p);        //to help removing
node* talloc();                   //allocates a tree's memory
void export(node* root);          //export
void exportHelper(node* root, FILE* fp);  //write data on a file  
node* load(node* p, pbook* info);  //read data from a file
pbook* setInfo(char* circle, char* name, char* number);  //to get info

#endif
#pragma once
