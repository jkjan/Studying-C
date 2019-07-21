#ifndef profMin
#define profMin
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

using namespace std;

class info {
private:
	char name[7];
	char sex;
	char loc[7];
	char major[13];
	float score;
	int height;
	int weight;
	int num=0;
public:

	int cur;
	info * create();

	//int verify(ifstream some);

	info* load(istream& fp, info*list);
	int line(istream& fp);
	void print(info*list);
	int insert(info*list, info* data);
	char* remove(info*data, char* rmv);
	int search(char*sch, info* data);
	info* first(info*data);
	info* next(info*data);
};




#endif#pragma once
