#include <stdio.h>
#include "arrlist.h"

int main() {
	List multi;

	init(&multi);

	int i; 
	int data; 
	int sum = 0;
	for (i = 1; i < 10; i++)
		insert(&multi, i);

	if (first(&multi, &data) == 1)
		sum += data;
	while (next(&multi, &data))
		sum += data;

	printf("%d\n\n", sum);

	if ((first(&multi, &data) == 1) && ((data % 2 == 0) || data % 3 == 0))
		remove(&multi);
	while (next(&multi, &data)) {
		if (data % 2 == 0 || data % 3 == 0)
			remove(&multi);
	}

	if (first(&multi, &data) == 1)
		printf("%d ", data);
	while (next(&multi, &data))
		printf("%d ", data);

}