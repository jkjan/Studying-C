#include "lordMin.h"

int main() {
	int i;
	int students;
	info std;
	char command[10];
	info*thelist;

	ifstream in, list;
	in.open("input.txt");


	if (in.is_open())
		cout << "The file has been successfully opened" << endl;
	else {
		cout << "Failed to open the file" << endl;
		return 0;
	}

	int many = std.line(in);
	printf("%d", many);
	in.clear();
	in.seekg(0);
	
	/*
		in >> command;
		cout << command << endl;
		if (strcmp(command, "CREATE") == 0) {
			thelist = std.create();    // 학생들 정보가 저장될 클래스 배열 크기 100짜리
		}

		//thelist = std.create();

		char filename[10];
		in >> command >> filename;
		cout << command << endl;
		cout << filename << endl;


		if (strcmp(command, "LOAD") == 0) {
			list.open(filename);
			if (list.is_open())
				cout << "The file has been successfully opened" << endl;
			else {
				cout << "Failed to open the file" << endl;
			}

			students = std.line(list);

			list.clear();
			list.seekg(0);
			std.load(list, thelist, students);

		}
		thelist->num = students;
		info temp;

		in >> command;
		cout << command << endl;

		
		if (strcmp(command, "PRINT") == 0) {
			std.print(thelist, students);
		}
		

		
		info * ga = new info[1];
		in >> command >> ga->name >> ga->sex >> ga->loc >>
			ga->major >> ga->score >> ga->height
			>> ga->weight;

		cout << command << endl;
		if (strcmp(command, "INSERT") == 0) {
			cout << ga->name << endl;

			std.insert(thelist, ga);
		}


		in >> command >> ga->name >> ga->sex >> ga->loc >>
			ga->major >> ga->score >> ga->height
			>> ga->weight;

		cout << command << endl;
		if (strcmp(command, "INSERT") == 0) {
			cout << ga->name << endl;

			std.insert(thelist, ga);
		}

		puts("\n");

		cout << thelist->num << endl;

		//std.print(thelist, students);
		char ddd[] = "김문희";

		std.search(ddd, thelist);
		puts("\n");
		std.remove(thelist, ddd);
		puts("\n");

		std.print(thelist, students);
		cout << thelist->num << endl;

		*/
		
	
	info*ga = new info[1];

	for (i = 0; i < many; i++) {
		in >> command;

		if (strcmp(command, "CREATE") == 0) {
			thelist = std.create();    // 학생들 정보가 저장될 클래스 배열 크기 100짜리

		}
		else if (strcmp(command, "LOAD") == 0) {
			in >> command;
			cout << command << endl;
			list.open(command);
			if (list.is_open())
				cout << "The file has been successfully opened" << endl;
			else {
				cout << "Failed to open the file" << endl;
				return 0;
			}
			
			students = std.line(list);
			cout << students << endl;
			list.clear();
			list.seekg(0);

			std.load(list, thelist);
		}

		else if (strcmp(command, "PRINT") == 0) {
			cout << command << endl;
			std.print(thelist);
		}
		
		else if (strcmp(command, "INSERT") == 0) {
			cout << command << endl;
			ga = std.load(in, ga);
			//cout << ga->name << endl;
			std.insert(thelist, ga);
		}

	else if (strcmp(command, "DELETE") == 0) {
			cout << command << endl;
		in >> command;
		std.remove(thelist, command);
	}

	else if (strcmp(command, "SEARCH") == 0) {
			cout << command << endl;
		in >> command;
		if ((i = std.search(command, thelist)) > -1) {
			std.print(thelist + i);
		}
		else
			puts("그런 사람 없습니다");
	}
}
	


		
	
	
	return 0;
	
}