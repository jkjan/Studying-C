#include "killemall.h" 

int main() {
	jo real;
	jo*access = &real;
	
	ifstream com;
	com.open("input.txt");
	cout << "input.txt";
	real.verify("input.txt");

	int n, k;
	int num;
	int i;
	int lines;
	int whowas;

	com >> lines;

	for (i = 0; i < lines; i++) {
		access = real.init();

		com >> n >> k;
		num = n;

		cout << n << "���� �ɾ� " << k << "�� ���Դϴ�." << endl;

		for (int j = 1; j <= n; j++) 
			real.enque(access, j);
		
		while (num >= k) {
			for (int j = 0; j < k; j++) {
				whowas = real.deque(access);
				num--;
				if (j < k - 1) {
					real.enque(access, whowas);
					num++;
					//cout << whowas << "�� ��Ҵ�" << endl;
				}
			}
		}

		cout << num <<"���� ���Ұ�, ";
		if (num==1)
			cout << "�״� ";
		else
			cout << "�׵��� ";

		for (int j = 0; j < num; j++) {
			cout << real.deque(access);
			if (j < num-1)
				cout << ", ";
		}

		cout << "��° ����Դϴ�." <<endl;
		cout << endl;
	}
}