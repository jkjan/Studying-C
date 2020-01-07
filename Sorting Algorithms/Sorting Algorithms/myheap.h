#ifndef MYHEAP
#define HEAP

extern void swap(int* a, int* b);

class Heap {
private:
	int* heap;
	int cnt;
	int size;
public:
	Heap(int size);
	void push(int data);
	void pop();
	int top();
	int getSize();
	int getCount();
	bool isEmpty();
	bool isFull();
	~Heap();
};

Heap::Heap(int size) {
	this->heap = new int[size];
	this->size = size;
	this->cnt = 1;
}

void Heap::push(int data) {
	int insertAt = this->cnt;
	this->heap[insertAt] = data;
	while (insertAt > 1) {
		if (this->heap[insertAt / 2] > this->heap[insertAt]) {
			swap(&this->heap[insertAt / 2], &this->heap[insertAt]);
			insertAt /= 2;
		}
		else
			break;
	}
	this->cnt++;
}

void Heap::pop() {
	int insertAt = 1;
	this->heap[insertAt] = this->heap[this->cnt - 1];

	int to;

	while (insertAt * 2 < this->cnt) {
		to = insertAt * 2;

		if ((insertAt * 2 + 1 < this->cnt) && (this->heap[insertAt * 2] > this->heap[insertAt * 2 + 1])) {
			to = insertAt * 2 + 1;
		}

		if (this->heap[insertAt] > this->heap[to]) {
			swap(&this->heap[insertAt], &this->heap[to]);
			insertAt = to;
		}
		else
			break;
	}
	this->cnt--;
}

int Heap::top() {
	return this->heap[1];
}

int Heap::getSize() {
	return this->size;
}

int Heap::getCount() {
	return this->cnt;
}

bool Heap::isEmpty() {
	return this->cnt <= 1;
}

bool Heap::isFull() {
	return this->cnt > this->size;
}

Heap::~Heap() {
	delete[] this->heap;
}

#endif