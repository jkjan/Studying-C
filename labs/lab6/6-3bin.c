#include "6-3h.h"

#include <string.h>  //strcmp

key* binsearch(char* word, int n) {
	int cond;
	key* low = &keytab[0];
	key* high = &keytab[n];
	key* mid;

	while (low < high) {
		mid = low + (high - low) / 2;   //pointer operation
		if ((cond = strcmp(word, mid->word)) < 0)  //if the word i wanna find is lexicographically less than mid
			high = mid-1;           //set the limit as mid-1
		else if (cond > 0)
			low = mid + 1;        //if not, set the bottom as mid + 1
		else
			return mid;           //or if found, return mid - the address of the word
	}

	return NULL;

}
