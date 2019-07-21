#include "MinIsTheBestProfInTheWorld.h"
#include <fstream>


int main() {
	node* ironman = new node;
	ironman = NULL;

	char command[10];
	int i, lines, students;

	ifstream in, list;
	in.open("input.txt");
	cout << "input.txt";
	verify("input.txt");

	lines = line(in);  //�� ���� �� ���� �ý��ϴ�.
	in.clear();
	in.seekg(0);

	for (i = 0; i < lines; i++) {
		in >> command;
		cout << lines << endl;
		if (strcmp(command, "CREATE") == 0) {
		}

		else if (strcmp(command, "LOAD") == 0) {
			cout << command << endl;
			in >> command;
			list.open(command);
			cout << command;
			verify(command);

			students = line(list);

			list.clear();
			list.seekg(0);

			for (i = 0; i < students; i++) {
				sinfo* info = new sinfo;
				list >> info->name >> info->sex 
					>> info->loc >> info->major 
					>> info->score >> info->height 
					>> info->weight;

				ironman = ironman->addtree(ironman, info);
			}
			ironman->treeprint();
			cout << students << endl;

			char nn[] = "������";

			getReturn * dss= ironman->search(ironman, nn);
			
			//cout << (dss == NULL) ? 1 : 0;

			if (dss->lr == 1)
				cout << dss->searched->lc->info->name << endl;
			else
				cout << dss->searched->rc->info->name<<endl;
			cout << '\n'<< endl;

			ironman->remove(ironman, nn);
			ironman->treeprint();

			cout << "list.txt�� �������� �����߽��ϴ�.\n" << endl;
		}

		else if (strcmp(command, "PRINT") == 0) {
			cout << command << endl;
			cout << "��ü ������ ����մϴ�.\n" << endl;
			ironman->treeprint();
		}

		else if (strcmp(command, "INSERT") == 0) {
			cout << command;
			sinfo* info = new sinfo;
			list >> info->name >> info->sex
				>> info->loc >> info->major
				>> info->score >> info->height
				>> info->weight;

			ironman->addtree(ironman, info);
		}

		else if (strcmp(command, "DELETE") == 0) {
			cout << command;
			in >> command;
			cout << ' ' << command << endl;

			if (ironman->remove(ironman, command) != 0) {
				cout << command << " �л��� �����մϴ�.\n" << endl;
			}

			else
				cout << "������ ���� �����ϴ�." << endl << endl;

		}

		else if (strcmp(command, "SEARCH") == 0) {
			cout << command;
			in >> command;
			cout << ' ' << command << endl;
			cout << command << " �л��� �����Դϴ� : " << endl;

			getReturn* index;
			if ((index = ironman->search(ironman, command)) != NULL) {
				index->searched->info->infoprint();
			}

			else
				puts("�л��� �������� �ʽ��ϴ�\n");
		}
	}

	in.close();
	list.close();
	/*
	ofstream newlymade;
	newlymade.open("new.txt");
	cout << "new.txt";
	if (verify("new.txt"))
		save(newlymade, access);

	cout << "�� �ڷḦ new.txt�� �����߽��ϴ�." << endl;

	delete[] access;
	newlymade.close();

	return 0;
	*/
}
