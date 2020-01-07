#ifndef MYQUEUE
#define QUEUE
#define NULL 0

struct node {
	int num;
	struct node* next;
};

typedef struct node Node;

class Queue {
public:
	Node* head;
	Node* back;
	int cnt;
public:
	Queue();
	void push(int data);
	int front();
	void pop();
	bool isEmpty();
	bool isFull();
};

Queue::Queue(){
	this->cnt = 0;
	this->head = new Node;
	this->head->num = 0;
	this->head->next = NULL;
	this->back = this->head;
}

void Queue::push(int data) {
	Node* add = new Node;
	add->num = data;
	add->next = NULL;
	this->back->next = add;
	this->back = add;
	this->cnt++;
}

int Queue::front() {
	return this->head->next->num;
}

void Queue::pop() {
	Node* deleting = this->head->next;
	this->head->next = this->head->next->next;
	this->cnt--;
	delete[] deleting;
	if (this->isEmpty())
		this->back = this->head;
}

bool Queue::isEmpty() {
	return this->cnt <= 0;
}

bool Queue::isFull() {
	return false;
}

#endif