#include <stdio.h>

int main () {
	struct node {
		int len;
		char *str;
	};

	struct node a = {10, "test"};
	struct node *p = &a;

	printf("a.len is %d\n", a.len);   //print node a's len
	printf("p->len is %d\n", p->len); // print node a's len (p pointing a)
	printf("++p->len is %d\n", ++p->len); // = ++(p->len), left to right, add 1 before print p->len
	printf("a.str is %s\n", a.str); // print node a's str
	printf("p->str is %s\n", p->str); // same
	printf("*p->str is %c\n", *p->str); // = *(p->str),  str's first character
	printf("*p->str++ is %c\n", *p->str++); // = print *(p->str) and then add 1 to str. *(p->(str++))
	printf("a.str is %s\n", a.str); // string , but starting from the second character
	
	return 0;
}
