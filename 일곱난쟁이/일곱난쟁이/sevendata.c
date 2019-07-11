#include "seven.h"

int input(shorty* data, int n) {
	if (data->num < 9) {
		data->name[data->num] = n;
		data->num++;
		return 1;
	}
	else
		return 0;
}

int first(shorty*data) {
	if (data->num > 0) {
		data->cur = 0;
		return data->name[data->cur];
	}
	else
		return -1;
}

int next(shorty*data) {
	if (data->num > 1 && data->cur < data->num - 1) {
		data->cur++;
		return data->name[data->cur];
	}
	else
		return -1;
}

int remove(shorty*data) {
	//data->cur = what;
	int i;
	int del = data->name[data->cur];

	for (i = 0; i < data->num - data->cur - 1; i++)
		data->name[data->cur + i] = data->name[data->cur + i + 1];

	//printf("%d을(를) 삭제합니다\n", del);

	data->num--;
	data->cur--;

	return del;
}