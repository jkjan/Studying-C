#include <iostream>
#include <cstdlib>

using namespace std;

class memo {
private:
	int three[100];
	int threec;

	int two[100];
	int twoc;

	int one[100];
	int onec;

	int tot;
public:
	void init();
	int add(int n);
	int max();
	void print();
};

void memo::init() {
	for (int i = 0; i < 100; i++) {
		this->three[i] = 0;
		this->two[i] = 0;
		this->one[i] = 0;
	}

	this->threec = this->twoc = this->onec = this->tot = 0;
}

int cnt = 0;

int memo::add(int n) {
	int tr = 0;
	int tw = 0;
	int on = 0;
	//cnt = 0;

	if (n == 1)
		return 0;

	else {
		if (n % 3 == 0) {
			if ((threec == 0) || (this->three[this->threec] > n / 3)) {
				this->three[(this->threec)++] = n / 3;
				tr++;
			}
		}

		if (n % 2 == 0) {
			if ((twoc == 0) || (this->two[this->twoc] > n / 2)) {
				this->two[(this->twoc)++] = n / 2;
				tw++;
			}
		}

		if (n - 1 >= 1) {
			if ((onec == 0) || (this->one[this->onec] > n - 1)) {
				this->one[(this->onec)++] = n - 1;
				on++;
			}
		}

		cnt++;

		//this->tot++;
		if (cnt <= 1) {
			if (tr == 1) {
				add(n / 3);
				cnt = 0;
			}

			if (tw == 1) {
				add(n / 2);
				cnt = 0;
			}

			if (on == 1) {
				add(n - 1);
				cnt = 0;
			}
		}
	}
}

int memo::max() {
	int tr = this->threec;
	int tw = this->twoc;
	int on = this->onec;

	return tr > tw ? (tr > on ? tr : on) : (tw > on ? tw : on);
}

void memo::print() {
	int i = 0;

	cout << this->threec << ' ' << this->twoc << ' ' << this->onec << endl;


	while (this->three[i] != 0) {
		cout << this->three[i] << ' ';
		i++;
	}
	cout << '\n';
	i = 0;

	while (this->two[i] != 0) {
		cout << this->two[i] << ' ';
		i++;
	}
	cout << '\n';
	i = 0;

	while (this->one[i] != 0) {
		cout << this->one[i] << ' ';
		i++;
	}

	//cout << '\n' << this->tot << endl;
}


int main() {
	memo* fuck = new memo;

	fuck->init();
	fuck->add(10);
	fuck->print();
	//cout << fuck->max();

	return 0;
}