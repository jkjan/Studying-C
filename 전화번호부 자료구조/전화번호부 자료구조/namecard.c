#include <stdio.h>
#include <string.h>
#include "namecard.h"

card*make(char*nm, char*ph) {
	card*joker = (card*)malloc(sizeof(card));
	//joker->name = nm;
	strcpy(joker->name, nm);
	//joker->phone = ph;
	strcpy(joker->phone, ph);
	return joker;
}

void show(card*pcard) {
	printf("%s, %s", pcard->name, pcard->phone);
}

int comp(card *pcard, char*nm){
	if (strcmp(pcard->name, nm) == 0)
		return 0;
	else
		return -1;
}

void change(card*pcard, char*ph){
	strcpy(pcard->phone, ph);
}

