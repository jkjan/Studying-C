#include "6-3h.h"  //a new header file made by myself
#define NKEYS (sizeof keytab / sizeof(key))

int getword(char*, int);
key* binsearch(char*, int);

key keytab[32] = {           //full keytab table
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,

	"const", 0,
	"continue", 0,
	"default", 0,
	"do", 0,

	"double", 0,
	"else", 0,
	"enum", 0,
	"extern", 0,

	"float", 0,
	"for", 0,
	"goto", 0,
	"if", 0,

	"int", 0,
	"long", 0,
	"register", 0,
	"return", 0,

	"short", 0,
	"signed", 0,
	"sizeof", 0,
	"static", 0,

	"struct", 0,
	"switch", 0,
	"typedef", 0,
	"union", 0,

	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
};

int main() {
	char word[MAXWORD];
	key* p;

	while (getword(word, MAXWORD) != EOF)  //till the word meets EOF
		if (isalpha(word[0]))          //if it's made of an english word, not of numbers
			if ((p = binsearch(word, NKEYS)) != NULL)  //and the word is on the keytab
				p->count++;      //add one

	for (p = keytab; p < keytab + NKEYS; p++)
		if (p->count > 0)          //if the counted number is more than 0
			printf("%4d %s\n", p->count, p->word);      //print it
	return 0;
}




