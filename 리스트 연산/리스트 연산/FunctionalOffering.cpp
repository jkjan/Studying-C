#include "lordMIn.h"
info * info::create(){
		info * infoarray = new info[100];
		cout << "the list has been made" << endl;
		return infoarray;
}

int info::line(istream& fp) {
	int lines = 0;
	char enter[255];

	while (!fp.eof()) {
		fp.getline(enter, 255);
		lines++;
	}
	num = lines;
	return lines;
}

info* info::load(istream& fp, info*list){
	int i=0;
	int j;
	cout << num << endl;
	info temp;
	while (i < num) {
		fp >> (list + i)->name >> (list + i)->sex >> (list + i)->loc >>
			(list + i)->major >> (list + i)->score >> (list + i)->height
			>> (list + i)->weight;
		i++;
	}

	//������ �ڵ�??
	
	for (i = 0; i < (num)-2; i++) {
		for (j = 0; j < (num)-i-1; j++) {
			if (strcmp((list + j)->name, (list + j+1)->name) > 0) {
				temp = *(list + j);
				*(list + j) = *(list + j + 1);
				*(list + j + 1) = temp;
			}
		}
	}
	
	

	return list;
}

void info::print(info*list){
	cout << fixed;
	cout.precision(2);
	for (int i = 0; i < num; i++) {
		cout << (list + i)->name << ' ' << (list + i)->sex << ' ' << (list + i)->loc << ' ' <<
			(list + i)->major << ' ' << (list + i)->score << ' ' << (list + i)->height << ' ' << (list + i)->weight << endl;
	}
}

int info::insert(info*list, info* data){
	int i;
	//info* temp;

	if (num < 100) {            //data�� �� ���� �ʾҴٸ�
		/*cin >> (temp + i)->name >> (temp + i)->sex >> (temp + i)->loc >>
			(temp + i)->major >> (temp + i)->score >> (temp + i)->height
			>> (temp + i)->weight; */ 
			
			//�ӽ÷� ������ ����

		if (strcmp(list->name, data->name) > 0)  //���� ó���� ���� �� ���̸�
			i = -1;

		else {                 //�ƴϸ�
			for (i = 0; i < num; i++) {
				if (strcmp((list + i)->name, data->name) > 0)
					break;
				}
			}

		//cout << i << endl;

		for (int j =(num) -1; j >= i; j--) //i �ڿ� �ִ� ����� �� �� ĭ�� �̷��
			*(list + 1+j) = *(list +j);  //�̰� �ǳ�????

		*(list + i) = *data; //?????

		num++;

		cout << data->name << " �л��� �����Ͽ����ϴ�." << endl;

		return 1;
	}
	else {
		cout << "�� á���ϴ�." << endl;
		return 0;
	}
}

info* info::first(info*data) {
	if (data->num > 0) {
		data->cur = 0;
		return data;
	}
	else
		return NULL;
}

info* info::next(info*data) {
	if (data->num > 1 && data->cur < data->num - 1) {
		data->cur++;
		return (data+(data->cur));
	}
	else
		return NULL;
}


char* info::remove(info*data, char* rmv){
	int i;
	int index;
	if ((index = search(rmv, data)) > -1) {
		for (i = 0; i < data->num - index - 1; i++)
			data[index + i] = data[index + i + 1];
		data->num--;
	}

	/*
	char *temp;
	strcpy(temp,(data+(data->cur))->name);
		for (i = 0; i < data->num - data->cur - 1; i++)
			data[data->cur + i] = data[data->cur + i + 1];

	printf("%d��(��) �����մϴ�\n", temp);
	
	data->num--;
	data->cur--;
	*/


	cout << rmv << " �л��� �����մϴ�." << endl;
	return rmv;
}

int info::search(char*sch, info*data) {
	int i;
	for (i = 0; i < data->num; i++) {
		if (strcmp((data + i)->name, sch) == 0)
			return i;

		else
			return -1;

		/*
		if ((data = first(data)) != NULL) {
			if (strcmp(data->name, sch) == 0)
				return data;
			while ((data = next(data)) != NULL) {
				if (strcmp(data->name, sch) == 0)
					return data;
			}
			*/


	}
}

