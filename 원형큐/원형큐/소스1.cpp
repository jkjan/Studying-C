#include "Çì´õ.h"

int main() {

	cq sex;
	cq* ass = &sex;

	ass = sex.init();

	sex.in(ass, 1);
	sex.in(ass, 2);
	sex.in(ass, 3); 
	sex.in(ass, 4); 
	sex.in(ass, 5);
	sex.in(ass, 6);
	sex.in(ass, 7);
	sex.in(ass, 8);
	sex.in(ass, 9);
	//sex.in(ass, 10);

	sex.de(ass);
	sex.de(ass);
	sex.de(ass);
	sex.de(ass);

	sex.in(ass, 100);
	sex.in(ass, 20);

	sex.printall(ass);

	return 0;



}