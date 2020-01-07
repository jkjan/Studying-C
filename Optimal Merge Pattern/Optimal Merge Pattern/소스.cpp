#include <iostream>
#include <queue>

using namespace std;

class Tree {
public:
	Tree* left;
	Tree* right;
	int cost;
	void init(Tree* left, Tree* right, int cost) {
		this->left = left;
		this->right = right;
		this->cost = cost;
	}
};

struct compare {
	bool operator()(Tree*a, Tree* b) {
		return a->cost > b->cost;
	}
};

typedef priority_queue< Tree*, vector<Tree*>, compare> Heap;

int input(Heap* files);
void buildTree(int n, Heap* files, Tree* root);

int main() {
	Heap files;
	Tree root;
	int n = input(&files);
	buildTree(n, &files, &root);
	cout << root.cost;
}

int input(Heap* files) {
	int n;
	int l;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l;
		Tree* leaf = new Tree;
		leaf->init(NULL, NULL, l);
		files->push(leaf);
	}
	return n;
}

Tree* withdraw(Heap* files) {
	Tree* len = files->top();
	files->pop();
	return len;
}

void buildTree(int n, Heap* files, Tree* root) {
	for (int i = 0; i < n-1; i++) {
		Tree* tnode = new Tree;
		Tree* left = withdraw(files);
		Tree* right = withdraw(files);
		tnode->init(left, right, left->cost + right->cost);
		files->push(tnode);
		*root = *tnode;
	}
}
