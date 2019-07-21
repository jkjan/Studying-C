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

	//정렬할 코드??
	
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

	if (num < 100) {            //data가 꽉 차지 않았다면
		/*cin >> (temp + i)->name >> (temp + i)->sex >> (temp + i)->loc >>
			(temp + i)->major >> (temp + i)->score >> (temp + i)->height
			>> (temp + i)->weight; */ 
			
			//임시로 데이터 저장

		if (strcmp(list->name, data->name) > 0)  //만약 처음에 들어가야 할 놈이면
			i = -1;

		else {                 //아니면
			for (i = 0; i < num; i++) {
				if (strcmp((list + i)->name, data->name) > 0)
					break;
				}
			}

		//cout << i << endl;

		for (int j =(num) -1; j >= i; j--) //i 뒤에 있는 놈들을 다 한 칸씩 미루기
			*(list + 1+j) = *(list +j);  //이게 되나????

		*(list + i) = *data; //?????

		num++;

		cout << data->name << " 학생을 저장하였습니다." << endl;

		return 1;
	}
	else {
		cout << "다 찼습니다." << endl;
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

	printf("%d을(를) 삭제합니다\n", temp);
	
	data->num--;
	data->cur--;
	*/


	cout << rmv << " 학생을 삭제합니다." << endl;
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

