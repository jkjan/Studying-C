#include "MinIsTheBestProfInTheWorld.h"
#include <fstream>

int main() {
	node* ironman = new node;

	char command[10];
	int i, lines, students;

	ifstream in, list;
	in.open("input.txt");
	cout << "input.txt";
	verify("input.txt");

	lines = line(in);  //줄 수를 한 번에 셌습니다.
	in.clear();
	in.seekg(0);

	for (i = 0; i < lines; i++) {
		in >> command;

		if (strcmp(command, "CREATE") == 0) {
			ironman = NULL;
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

			for (int j = 0; j < students; j++) {
				sinfo* info = new sinfo;
				list >> info->name >> info->sex
					>> info->loc >> info->major
					>> info->score >> info->height
					>> info->weight;

				ironman = ironman->addtree(ironman, info);
			}

			cout << "list.txt의 정보들을 저장했습니다.\n" << endl;
		}

		else if (strcmp(command, "PRINT") == 0) {
			cout << command << endl;
			cout << "전체 정보를 출력합니다.\n" << endl;
			ironman->treeprint();
			cout << '\n';
		}

		else if (strcmp(command, "INSERT") == 0) {
			cout << command << endl;

			sinfo* info = new sinfo;
			in >> info->name >> info->sex
				>> info->loc >> info->major
				>> info->score >> info->height
				>> info->weight;

			ironman = ironman->addtree(ironman, info);
			cout << info->name << " 학생을 추가했습니다.\n" << endl;
		}

		else if (strcmp(command, "DELETE") == 0) {
			cout << command;
			in >> command;
			cout << ' ' << command << endl;

			if (ironman->remove(command) == 0) {
				cout << command << " 학생을 삭제합니다.\n" << endl;
			}

			else
				cout << "삭제할 것이 없습니다." << endl << endl;
		}

		else if (strcmp(command, "SEARCH") == 0) {
			cout << command;
			in >> command;
			cout << ' ' << command << endl;
			cout << command << " 학생의 정보입니다 : " << endl;

			getReturn* index;
			if ((index = ironman->search(command)) != NULL) {
				if (index->lr == 1)
					index->searched->lc->info->infoprint();
				else
					index->searched->rc->info->infoprint();
				cout << '\n';
			}

			else
				puts("학생이 존재하지 않습니다\n");
		}
	}

	in.close();
	list.close();

	
	delete (ironman);

	return 0;
}