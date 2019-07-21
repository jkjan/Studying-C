#include "MinTheGreat.h"

int main() {
	int i;
	int index;
	int students;
	info std; //std Ŭ����
	info*access = &std; //std Ŭ����(��ü)�� �ּ�
	lib*thelist;  //std Ŭ���� �ȿ� �л� ������ ��� ��¥

	char command[10];  //��ɾ�
	
	ifstream in, list;
	in.open("input.txt");
	cout << "input.txt";
	std.verify("input.txt");

	int many = std.line(in);
	
	in.clear();
	in.seekg(0);

	info garbage; // insert �� �ӽ÷� ����� info*
	info*ga = &garbage;

	for (i = 0; i < many; i++) {
		in >> command;

		if (strcmp(command, "CREATE") == 0) {
			thelist = std.create(access, 100);    // �л��� ������ ����� Ŭ���� �迭 ũ�� 100¥��
		}

		else if (strcmp(command, "LOAD") == 0) {
			in >> command;
			list.open(command);
			cout << command;
			std.verify(command);
			students = std.line(list);
			list.clear();
			list.seekg(0);

			std.load(list, access, students);
		}

		else if (strcmp(command, "PRINT") == 0) {
			cout << command << endl;
			cout << "��ü ������ ����մϴ�.\n" << endl;
			std.print(access);
		}

		else if (strcmp(command, "INSERT") == 0) {
			cout << command;
			lib*galist = std.create(ga, 1);
			if (std.insert(access, std.load(in, ga, 1)));
				students++;
		}

		else if (strcmp(command, "DELETE") == 0) {
			cout << command;
			in >> command;
			cout << ' ' << command << endl;

			if (std.remove(access, command)) {
				cout << command << " �л��� �����մϴ�.\n" << endl;
				students--;
			}

			else
				cout << "������ ���� �����ϴ�." << endl << endl;
			
		}

		else if (strcmp(command, "SEARCH") == 0) {
			cout << command;
			in >> command;
			cout << ' ' << command << endl;
			cout << command << " �л��� �����Դϴ� : " << endl;
			if ((index = std.search(command, access, 1, 0, students-1)) > -1) {
				cout
					<< (thelist + index)->sex << ' '
					<< (thelist + index)->loc << ' '
					<< (thelist + index)->major << ' '
					<< (thelist + index)->score << ' '
					<< (thelist + index)->height << ' '
					<< (thelist + index)->weight << endl << endl;
			}
			
			else
				puts("�л��� �������� �ʽ��ϴ�\n");
		}
	}

	in.close();
	list.close();

	ofstream newlymade;
	newlymade.open("new.txt");
	cout << "new.txt";
	if (std.verify("new.txt")) 
		std.save(newlymade, access);

	cout << "�� �ڷḦ new.txt�� �����߽��ϴ�." << endl;

	delete[] thelist;
	newlymade.close();

	return 0;
}