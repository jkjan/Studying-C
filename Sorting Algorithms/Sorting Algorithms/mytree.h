#include <iostream>

#ifndef TREEHEAP
#define TREEHEAP
#define NULL 0
#define SIZE 60000

using namespace std;

extern int* intArray;
int idx = 0;

struct treeNode {
	int num;
	struct treeNode* left;
	struct treeNode* right;
};

typedef struct treeNode TreeNode;

class BTree {
private :
	TreeNode* root;
	int cnt;
public :
	void init();
	bool insert(TreeNode* node, int data);
	void insert(int data);
	bool isEmpty();
	void printTree(TreeNode* node);
	void printTree();
};

void BTree::init() {
	this->root = new TreeNode;
	this->root->num = -1;
	this->root->left = NULL;
	this->root->right = NULL;
	this->cnt = 0;
}

bool BTree::insert(TreeNode* node, int data) {
	if (node == NULL) {
		return true;
	}

	if (node->num >= data) {
		if (this->insert(node->left, data)) {
			TreeNode* add = new TreeNode;
			add->num = data;
			add->left = NULL;
			add->right = NULL;
			node->left = add;
			return false;
		}
	}
	else {
		if (this->insert(node->right, data)) {
			TreeNode* add = new TreeNode;
			add->num = data;
			add->left = NULL;
			add->right = NULL;
			node->right = add;
			return false;
		}
	}
}

void BTree::insert(int data) {
	if (this->cnt == 0) {
		this->root->num = data;
	}
	else 
		this->insert(this->root, data);

	this->cnt++;
}

bool BTree::isEmpty() {
	return this->cnt <= 0;
}

void BTree::printTree(TreeNode* node) {
	if (node == NULL) {
		return;
	}
	printTree(node->left);
	intArray[idx++] = node->num;
	printTree(node->right);
}

void BTree::printTree() {
	this->printTree(this->root);
	idx = 0;
}

#endif