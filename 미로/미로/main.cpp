#include <fstream>
#include <iostream>
using namespace std;

class element {
public:
	int x;
	int y;
	element() {
		x = 0;
		y = 0;
	}
	element(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class Stack {
public:
	int top;
	int size;
	element* items;

	Stack(int size) {
		this->size = size;
		top = 0;
		items = new element[size];
	}

	~Stack() {
		delete items;
	}

	bool is_full() {
		if (top == size) {
			return true;
		}
		else
			return false;
	}

	bool is_empty() {
		if (top == 0) {
			return true;
		}
		else
			return false;
	}

	void push(element e) {
		if (is_full()) {
			cout << "stack is full";
		}
		else {
			items[top] = e;
			top++;
		}
	}

	element pop() {
		if (is_empty()) {
			element k(-100, -100);

			return k;
		}
		else {
			top--;
			return items[top];
		}
	}

};


int main() {


	fstream fs("test.txt");

	int x, y;

	fs >> x >> y;

	Stack path(x*y);

	int** maze;
	maze = new int*[x];


	for (int i = 0; i < x; i++) {
		maze[i] = new int[y];
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			int n;
			fs >> n;
			maze[i][j] = n;
		}
	}

	element entry, exit;

	fs >> entry.x >> entry.y >> exit.x >> exit.y;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}

	path.push(entry);



	int isstart = 1;
	int found = 0;

	while (!path.is_empty() && !found) {


		element curr = path.pop();




		//시작점이 잘못 되엇을때
		if (isstart == 1) {
			if (maze[curr.y - 1][curr.x - 1] != 0) {
				cout << "wrong entry" << endl;
				break;
			}
		}



		//curr 출구면?
		if (curr.x == exit.x && curr.y == exit.y) {
			cout << "find exit" << endl;
			found = 1;
			path.push(curr);
			break;
		}


		//curr 방문 표시
		maze[curr.y - 1][curr.x - 1] = -1;
		isstart = 0;

		// 왼쪽 아래로 못감		좌하단 모서리가 시작점
		if (curr.y == x && curr.x == 1) {

			//right
			if (maze[curr.y - 1][curr.x] == 0) {
				path.push(curr);
				element next(curr.x + 1, curr.y);
				path.push(next);
				continue;
			}
			//up
			else if (maze[curr.y - 2][curr.x - 1] == 0) {
				path.push(curr);
				element next(curr.x, curr.y - 1);
				path.push(next);
				continue;
			}
			else {
				continue;
			}
		}
		//왼쪽, 위로 못감
		else if (curr.x == 1 && curr.y == 1) {
			//right
			if (maze[curr.y - 1][curr.x] == 0) {
				path.push(curr);
				element next(curr.x + 1, curr.y);
				path.push(next);

				continue;
			}
			//down
			else if (maze[curr.y][curr.x - 1] == 0) {
				path.push(curr);
				element next(curr.x, curr.y + 1);
				path.push(next);
				continue;
			}
			else {
				continue;
			}
		}

		//오른쪽, 아래로 못감
		else if (curr.x == y && curr.y == x) {
			//up
			if (maze[curr.y - 2][curr.x - 1] == 0) {
				path.push(curr);
				element next(curr.x, curr.y - 1);
				path.push(next);
				continue;
			}
			//left
			else if (maze[curr.y - 1][curr.x - 2] == 0) {
				path.push(curr);
				element next(curr.x - 1, curr.y);
				path.push(next);
				continue;
			}
			else {
				continue;
			}
		}
		//오른쪽, 위로 못감
		else if (curr.y == 1 && curr.x == y) {

			//left
			if (maze[curr.y - 1][curr.x - 2] == 0) {
				path.push(curr);
				element next(curr.x - 1, curr.y);
				path.push(next);
				continue;
			}
			//down
			else if (maze[curr.y][curr.x - 1] == 0) {
				path.push(curr);
				element next(curr.x, curr.y + 1);
				path.push(next);
				continue;
			}
			else {
				continue;
			}
		}
		//왼쪽으로 못감
		else if (curr.x == 1 && curr.y > 1) {
			//right
			if (maze[curr.y - 1][curr.x] == 0) {
				path.push(curr);
				element next(curr.x + 1, curr.y);
				path.push(next);
				continue;
			}
			//up
			else if (maze[curr.y - 2][curr.x - 1] == 0) {
				path.push(curr);
				element next(curr.x, curr.y - 1);
				path.push(next);
				continue;
			}
			//down
			else if (maze[curr.y][curr.x - 1] == 0) {
				path.push(curr);
				element next(curr.x, curr.y + 1);
				path.push(next);
				continue;
			}
			else {
				continue;
			}
		}
		//위로 못감
		else if (curr.y == 1 && curr.x > 1) {
			//right
			if (maze[curr.y - 1][curr.x] == 0) {
				path.push(curr);
				element next(curr.x + 1, curr.y);
				path.push(next);

				continue;
			}
			//left
			else if (maze[curr.y - 1][curr.x - 2] == 0) {
				path.push(curr);
				element next(curr.x - 1, curr.y);
				path.push(next);
				continue;
			}
			//down
			else if (maze[curr.y][curr.x - 1] == 0) {
				path.push(curr);
				element next(curr.x, curr.y + 1);
				path.push(next);
				continue;
			}
			else {
				continue;
			}

		}

		//오른쪽으로 못감
		else if (curr.x == y && curr.y < x) {
			//up

			if (maze[curr.y - 2][curr.x - 1] == 0) {
				path.push(curr);
				element next(curr.x, curr.y - 1);
				path.push(next);
				continue;
			}
			//left
			else if (maze[curr.y - 1][curr.x - 2] == 0) {
				path.push(curr);
				element next(curr.x - 1, curr.y);
				path.push(next);
				continue;
			}
			//down
			else if (maze[curr.y][curr.x - 1] == 0) {
				path.push(curr);
				element next(curr.x, curr.y + 1);
				path.push(next);
				continue;
			}
			else {
				continue;
			}
		}
		//아래로 못감
		else if (curr.y == x && curr.x < y) {
			//right
			if (maze[curr.y - 1][curr.x] == 0) {
				path.push(curr);
				element next(curr.x + 1, curr.y);
				path.push(next);
				continue;
			}
			//up
			else if (maze[curr.y - 2][curr.x - 1] == 0) {
				path.push(curr);
				element next(curr.x, curr.y - 1);
				path.push(next);
				continue;
			}
			//left
			else if (maze[curr.y - 1][curr.x - 2] == 0) {
				path.push(curr);
				element next(curr.x - 1, curr.y);
				path.push(next);
				continue;
			}
			else {

				continue;
			}
		}

		else if (curr.x > 1 && curr.y > 1) {
			//right
			if (maze[curr.y - 1][curr.x] == 0) {
				path.push(curr);
				element next(curr.x + 1, curr.y);
				path.push(next);
				continue;
			}
			//up
			else if (maze[curr.y - 2][curr.x - 1] == 0) {
				path.push(curr);
				element next(curr.x, curr.y - 1);
				path.push(next);
				continue;
			}
			//left
			else if (maze[curr.y - 1][curr.x - 2] == 0) {
				path.push(curr);
				element next(curr.x - 1, curr.y);
				path.push(next);
				continue;
			}
			//down
			else if (maze[curr.y][curr.x - 1] == 0) {
				path.push(curr);
				element next(curr.x, curr.y + 1);
				path.push(next);
				continue;
			}
			else {
				continue;
			}

		}

	}



	if (found) {
		int size = path.top;

		element* result = new element[size];
		int i = 0;
		while (!path.is_empty()) {
			element e = path.pop();
			result[i] = e;
			i++;

		}

		for (int k = size - 1; k >= 0; k--) {
			cout << "(" << result[k].x << "," << result[k].y << ")" << endl;
		}
		delete result;
	}
	else {
		cout << "no exit" << endl;
	}
	delete maze;


	return -1;
}