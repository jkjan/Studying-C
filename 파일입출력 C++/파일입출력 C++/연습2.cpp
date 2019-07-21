#include <iostream>
#include <fstream>
#include <cstdlib>


using namespace std;

int i=0;

//학생 정보를 저장할 클래스 선언
class info {
private :
	char name[7];
	char sex;
	char loc[7];
	char major[13];
	float score;
	int height;
	int weight;

public: 
		int line(istream& fp);
		info* alloc(int lines);
		void scan(istream& fp, info*list, int lines);
		void print(info*list, int lines);
		//void error(istream& fp, info*list, int what);
};

//파일의 줄 수 세기
int info::line(istream& fp) {
	int lines = 0;
	char enter[255];
	
	//int lines = 0;

	while (!fp.eof()) {
		fp.getline(enter, 255);
		lines++;
	}

	return lines;
}

//(클래스 멤버 함수로) 클래스 배열 동적 메모리 할당하기
info* info::alloc(int lines) {
	info * infoarray = new info[lines];
	return infoarray;
}

//(클래스 멤버 함수로) 입력받기
void info::scan(istream& fp, info*list, int lines) {
	int what;

	try {
		while (i < lines) {
			what = 1;
			fp >> (list + i)->name;
			
			what = 2;
			fp >> (list + i)->sex;
			
			what = 3;
			fp >> (list + i)->loc;
			
			what = 4;
			fp >> (list + i)->major;
			
			what = 5;
			fp >> (list + i)->score;
			
			what = 6;
			fp >> (list + i)->height;
			
			what = 7;
			fp >> (list + i)->weight;
			
			i++;
		}

		if (fp.fail()) {
			cout << "file contents error" << endl;
			switch (what) {
			case 1: throw 1;
			case 2: throw 2;
			case 3: throw 3;
			case 4: throw 4;
			case 5: throw 5;
			case 6: throw 6;
			case 7: throw 7;
			}
		}
	}
	catch (int expn) {
		if (expn == 1) {
			char name[7];
			cin >> (list + i)->name;
		}

		else if (expn == 2) {
			char sex;
			cin >> (list + i)->sex;
		}

		else if (expn == 3) {
			char loc[7];
			cin >> (list + i)->loc;
		}

		else if (expn == 4) {
			char major[13];
			cin >> (list + i)->major;
		}

		else if (expn == 5) {
			float score;
			cin >> (list + i)->score;
			cout << "점수가 이상합니다.";
		}

		else if (expn == 6) {
			int height;
			cin >> (list + i)->height;
		}

		else if (expn == 7) {
			int weight;
			cin >> (list + i)->weight;
		}
	}
}

//오류 검사
/*
void info::error(istream&fp, info *list ,int what) {
	if (fp.fail())
		cout << "File contents error. Edit it" << endl; // 에러 메시지 출력

	//fp.clear(); // 오류스트림을 초기화
	//fp.ignore(256, '\n'); // 입력버퍼를 비움

	if (what == 1) {
		char name[7];
		cin >> (list+i)->name;
	}

	else if (what == 2) {
		char sex;
		cin >> (list + i)->sex;
	}

	else if (what == 3) {
		char loc[7];
		cin >> (list + i)->loc;
	}

	else if (what == 4) {
		char major[13];
		cin >> (list + i)->major;
	}

	else if (what == 5) {
		float score;
		cin >> (list + i)->score;
	}

	else if (what == 6) {
		int height;
		cin >> (list + i)->height;
	}

	else if (what == 7) {
		int weight;
		cin >> (list + i)->weight;
	}
}
*/

//(클래스 멤버 함수로) 출력하기
void info::print(info*list, int lines) {
	cout << fixed;
	cout.precision(2);
	for (i = 0; i < lines; i++) {
		cout << (list + i)->name << ' ' <<  (list + i)->sex << ' ' << (list + i)->loc << ' ' <<
			(list + i)->major << ' ' << (list + i)->score << ' ' << (list + i)->height << ' ' << (list + i)->weight << endl;
	}
}

int main() {
	ifstream it;
	it.open("list.txt");
	
	//파일 열기 성공 여부 확인 메시지
	if (it.is_open()) 
		cout << "The file has been successfully opened" << endl;
	else {
		cout << "Failed to open the file" << endl;
		return 0;
	}
	

	//클래스 삽입
	info in;

	//파일의 줄 수 세기
	int line = in.line(it);
	
	//cout << line;

	//(클래스 멤버 함수로) 클래스 배열 동적 메모리 할당하기
	info * inarrays = in.alloc(line);

	it.clear();
	it.seekg(0);

	//(클래스 멤버 함수로) 입력받기
	in.scan(it, inarrays, line);

	//(클래스 멤버 함수로) 출력하기
	in.print(inarrays, line);

	free(inarrays);
	it.close();

	return 0;
}