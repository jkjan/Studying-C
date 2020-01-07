#include <iostream>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

class Pos {
public :
	int y;
	int x;
	Pos(int y, int x) {
		this->x = x;
		this->y = y;
	}
};

Pos forward(int);

int main() {
	int field[52][52];

	int N, M;
	int r, c, d;
	int i;
	int cnt = 0;
	Pos pos(0, 0);

	cin >> N >> M;
	cin >> r >> c >> d;

	for (i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> field[i+1][j+1];
		}
	}

	r += 1;
	c += 1;

	for (int j = 0; j < M; j++) {
		field[0][j] = 1;
		field[51][j] = 1;
	}

	for (i = 0; i < N; i++) {
		field[N][0] = 1;
		field[N][51] = 1;
	}

	while (1) {
		if (field[r][c] == 0) {
			field[r][c] = -1;
			cnt++;
		}

		for (i = 0; i < 4; i++) {
			if (d == 0)
				d = 3;
			else
				d--;

			pos = forward(d);
			if (field[r + pos.y][c + pos.x] == 0)
				break;
		}

		if (i == 4) {
			pos = forward(d);
			if (field[r - pos.y][c - pos.x] == 1) {
				cout << cnt;
				return 0;
			}

			else {
				r -= pos.y;
				c -= pos.x;
			}
		}

		else {
			r += pos.y;
			c += pos.x;
		}
	}

	return 0;
}

Pos forward(int d) {
	switch (d) {
	case UP:
		return Pos(-1, 0);
	case DOWN :
		return Pos(1, 0);
	case LEFT :
		return Pos(0, -1);
	case RIGHT :
		return Pos(0, 1);
	default :
		return Pos(0, 0);
	}
}