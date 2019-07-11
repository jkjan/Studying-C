#include <stdio.h>
#include "namecard.h"
#include "arrlist.h"

int main() {
	int i;
	List list;
	card* cardi;
	Ldata data;
	init(&list);
	char name[30], phone[30];
	
	cardi = make("이진수", "010-1111-2222");
	insert(&list, cardi);
	cardi = make("한지영", "010-2222-5555");
	insert(&list, cardi);
	cardi = make("조수진", "010-3333-7777");
	insert(&list, cardi);

	/*
	if (first(&list, &data))
		show(data);
	printf("\n");
	while (next(&list, &data)) {
		show(data);
		printf("\n");
	}
	*/
	

	//이진수 찾아서 출력
	if (first(&list, &data)) {           //받을 때는 &을 붙인다 왜? arr이 int형이므로. 받고나서는 구조체 변수 인식하므로
		i=comp(data, "이진수");          //더이상 &을 붙일 필요 없음.
		if (i == 0)
			show(data);
	}
	printf("\n");
	while (next(&list, &data)) {
		i = comp(data, "이진수");
		if (i == 0)
			show(data);
		printf("\n");
	}


	//한지영 찾아서 번호 변경
	if (first(&list, &data)) {
		i = comp(data, "한지영");
		if (i == 0)
			change(data,"010-4444-7777");
	}
	while (next(&list, &data)) {
		i = comp(data, "한지영");
		if (i == 0)
			change(data, "010-4444-7777");
	}


	//조수진 찾아서 삭제
	if (first(&list, &data)) {
		i = comp(data, "조수진");
		if (i == 0) {
			remove(&list);
			free(data);
		}
	}
	while (next(&list, &data)) {
		i = comp(data, "조수진");
		if (i == 0) {
			remove(&list);
			free(data);
		}
	}


	//전체 출력
	if (first(&list, &data))
		show(data);
	printf("\n");
	while (next(&list, &data)) {
		show(data);
		printf("\n");
	}





}