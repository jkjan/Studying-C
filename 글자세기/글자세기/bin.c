#include "6-3h.h"

#include <string.h>

key* binsearch(char* word, int n) {
	int cond;
	key* low = &keytab[0];
	key* high = &keytab[n];
	key* mid;

	while (low < high) {
		mid = low + (high - low) / 2;
		if ((cond = strcmp(word, mid->word)) < 0)
			high = mid;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}

	return NULL;

}