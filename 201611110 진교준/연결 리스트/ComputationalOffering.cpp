#include "MinTheGreat.h"

int main() {
	int i;
	int students;
	link std; //std Ŭ����
	link*access = &std; //std Ŭ����(��ü)�� �ּ�

	char command[10];  //��ɾ�

	ifstream in, list;
	in.open("input.txt");
	cout << "input.txt";
	std.verify("input.txt");

	int many = std.line(in);

	in.clear();
	in.seekg(0);

	link garbage;
	link*ga = &garbage;

	for (i = 0; i < many; i++) {
		in >> command;

		if (strcmp(command, "CREATE") == 0) {
			access = std.create();
		}

		else if (strcmp(command, "LOAD") == 0) {
			cout << command << endl;
			in >> command;
			list.open(command);
			cout << command;
			std.verify(command);
			students = std.line(list);
			list.clear();
			list.seekg(0);
			
			std.load(list, access, students);
			cout << "list.txt�� �������� �����߽��ϴ�.\n" << endl;
		}

		else if (strcmp(command, "PRINT") == 0) {
			cout << command << endl;
			cout << "��ü ������ ����մϴ�.\n" << endl;
			std.print(access);
		}

		else if (strcmp(command, "INSERT") == 0) {
			cout << command;
			ga = std.create();
			if (std.insert(access, std.load(in, ga, 1)))
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

			node*index;
			if ((index = std.search(command, access)) != NULL) {
				cout
					<< index->library->sex << ' '
					<< index->library->loc << ' '
					<< index->library->major << ' '
					<< index->library->score << ' '
					<< index->library->height << ' '
					<< index->library->weight << endl << endl;
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

	delete[] access;
	newlymade.close();
	
		return 0;
	}