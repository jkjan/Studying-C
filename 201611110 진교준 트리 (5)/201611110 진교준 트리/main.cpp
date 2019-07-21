#include "maximumeffort.h"
#include <fstream>

int main() {
	ifstream tony;
	tony.open("stark.txt");
	cout << "stark.txt";
	verify("stark.txt");

	tnode* acc = new tnode;
	acc->init();

	int lines, i;
	int root, left, right;
	lines = line(tony);  //�� ���� �� ���� �ý��ϴ�.
	tony.clear();
	tony.seekg(0);

	tnode* next;

	for (i = 0; i < lines; i++) {
		tony >> root >> left >> right;
		cout << root <<' ' << left<< ' ' << right << endl;
		if (!i) {	//addtree ��ü�� ����ó���� �����ϴ�. ���� ��Ʈ ��带 �����ؾ� �մϴ�.
			acc = acc->addtree(acc, root, left, right);
			cout << "gimme the root!" << endl;
		}

		else if ((next = acc->valid(acc, root, left, right)) != NULL) { //valid ���� Ȯ���ϴ� ���ÿ�
			acc->addtree(next, root, left, right);						//��带 �߰��� �ּҵ� ���� �� �ֽ��ϴ�
			cout << "added" << endl;
		}

		else
			cout << "invalid" << endl;

		cout << '\n';
	}
	tony.close();

	acc->treeprint(acc);
	cout << '\n';
	cout << "height : " << acc->height(acc) << endl;
	cout << " width : " << acc->width(acc) << endl;

	acc->thanos(acc);
	
	return 0;
}
