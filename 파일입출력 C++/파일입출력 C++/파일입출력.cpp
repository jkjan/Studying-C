#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int i = 0;

//�л� ������ ������ Ŭ���� ����
class info {
private:
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
	int scan(istream& fp, info*list, int lines);
	void print(info*list, int lines);
};

//������ �� �� ����
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

//(Ŭ���� ��� �Լ���) Ŭ���� �迭 ���� �޸� �Ҵ��ϱ�
info* info::alloc(int lines) {
	info * infoarray = new info[lines];

	return infoarray;
}

//(Ŭ���� ��� �Լ���) �Է¹ޱ�
int info::scan(istream& fp, info*list, int lines) {
	try {
		while (i < lines) {
			fp >> (list + i)->name >> (list + i)->sex >> (list + i)->loc >>
				(list + i)->major >> (list + i)->score >> (list + i)->height
				>> (list + i)->weight;
			if (fp.fail())
				throw 1;
			i++;
			}
		}

	/*�ڷ��� ���� ���� ó��
	�̸��� ���ڰ� ���� ������ �߰��ϰ� �;����� �̸� �Ϸ��� ���� �ϳ��ϳ��� �˻��ؼ�
	(list + i)->name[i] - atoi((list+i)->name[i]) �� 48�� �Ǵ����� �Ǵ��ؾ� �ϰ�, �̶����� 
	�˰����� O(n^2)�� �Ǳ� ������ �����Ͽ����ϴ�.
	������ �ִ� ���� ��Ȯ�� ã�� ���ϴ� ������
	���� �л��� ���Կ� 60dd ��� ���� ���� �� ���� ���� �̸��� dd��� �ν��� �Ǿ�Դϴ�.
	*/
	catch (int expn) {
		if (expn) {
			cout << (list + i-1)->name << " �л�, Ȥ�� ���� �л��� ��ġ ������ ������ �ֽ��ϴ�. "
				<< "��Ȯ�� �Ͻʽÿ�." << endl;
			return 1;
		}
	}
	
	return 0;
	}

//(Ŭ���� ��� �Լ���) ����ϱ�
void info::print(info*list, int lines) {
	cout << fixed;
	cout.precision(2);
	for (i = 0; i < lines; i++) {
		cout << (list + i)->name << ' ' << (list + i)->sex << ' ' << (list + i)->loc << ' ' <<
			(list + i)->major << ' ' << (list + i)->score << ' ' << (list + i)->height << ' ' << (list + i)->weight << endl;
	}
}

int main() {
	ifstream it;
	it.open("list.txt");
	int error, line;

	//���� ���� ���� ���� Ȯ�� �޽���
	if (it.is_open())
		cout << "The file has been successfully opened" << endl;
	else {
		cout << "Failed to open the file" << endl;
		return 0;
	}

	//Ŭ���� ����
	info in;

	//������ �� �� ����
	line = in.line(it);

	//(Ŭ���� ��� �Լ���) Ŭ���� �迭 ���� �޸� �Ҵ��ϱ�
	info * inarrays = in.alloc(line);

	it.clear();
	it.seekg(0);

	//(Ŭ���� ��� �Լ���) �Է¹ޱ�
	error = in.scan(it, inarrays, line);

	//(Ŭ���� ��� �Լ���) ����ϱ�
	if (!error)
		in.print(inarrays, line);

	delete[] inarrays;
	it.close();

	return 0;
}