#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "myheap.h"
#include "myqueue.h"
#include "mytree.h"

using namespace std;

void printArray(int* array, int size);

void insertionSort(int* array, int size);
void selectionSort(int* array, int size);
void bubbleSort(int* array, int size);
void mergeSort(int* array, int s, int e);
void quickSort(int* array, int s, int e);
void heapSort(int* array, int size);
void countSort(int* array, int size);
void radixSort(int* array, int size);
void treeSort(int* array, int size);
void bogoSort(int* array, int size);

int* intArray;

int main(int argc, char** argv) {
	int sortingSelect;
	clock_t start, end;
	//ifstream fp("array.txt");
	//fp >> size;
	intArray = new int[SIZE];

	srand(time(NULL));

	for (int i = 0; i < SIZE; i++) {
		intArray[i] = rand() % 100000;
	}

	//for (int i = 0; i < size; i++) {
	//	fp >> *(intArray + i);
	//}

	cout << "Which sorting algorithm do you want me to use, sir?" << endl;
	cout << endl;
	cout << "1 : Insertion Sort" << endl;
	cout << "2 : Selection Sort" << endl;
	cout << "3 : Bubble Sort" << endl;
	cout << "4 : Merge Sort" << endl;
	cout << "5 : Quick Sort" << endl;
	cout << "6 : Heap Sort" << endl;
	cout << "7 : Count Sort" << endl;
	cout << "8 : Radix Sort" << endl;
	cout << "9 : Tree Sort" << endl;
	cout << "10 : Bogo Sort (BONUS!)" << endl;
	cout << endl;

	cin >> sortingSelect;
	cout << endl;

	cout << "original array : " << endl;
	//printArray(intArray, SIZE);

	cout << endl;
	switch (sortingSelect) {
	case 1:
		start = clock();
		insertionSort(intArray, SIZE);
		end = clock();
		break;
	case 2:
		start = clock();
		selectionSort(intArray, SIZE);
		end = clock();
		break;
	case 3:
		start = clock();
		bubbleSort(intArray, SIZE);
		end = clock();
		break;
	case 4:
		start = clock();
		mergeSort(intArray, 0, SIZE - 1);
		end = clock();
		break;
	case 5:
		start = clock();
		quickSort(intArray, 0, SIZE - 1);
		end = clock();
		break;
	case 6:
		start = clock();
		heapSort(intArray, SIZE);
		end = clock();
		break;
	case 7:
		start = clock();
		countSort(intArray, SIZE);
		end = clock();
		break;
	case 8:
		start = clock();
		radixSort(intArray, SIZE);
		end = clock();
		break;
	case 9:
		start = clock();
		treeSort(intArray, SIZE);
		end = clock();
		break;
	case 10:
		cout << "Stay calm and wait. It is no infinite loop." << endl;
		start = clock();
		bogoSort(intArray, SIZE);
		end = clock();
		break;
	default:
		break;
	}
	cout << "sorted array : " << endl;
	//printArray(intArray, SIZE);
	cout << endl;
	printf("%.8f seconds", (double)(end - start) / CLOCKS_PER_SEC);
	delete[] intArray;
	return 0;
}

void printArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertionSort(int* array, int size) {
	int insert;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if (array[i] < array[j]) {
				insert = array[i];
				for (int k = i - 1; k >= j; k--) {
					array[k + 1] = array[k];
				}
				array[j] = insert;
			}
		}
	}
}

void selectionSort(int* array, int size) {
	int minIndex;
	for (int i = 0; i < size - 1; i++) {
		minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (array[j] < array[minIndex]) {
				minIndex = j;
			}
		}
		swap(&array[i], &array[minIndex]);
	}
}

void bubbleSort(int* array, int size) {
	bool flag = false;

	for (int i = size - 1; i >= 1; i--) {
		if (flag)
			break;
		flag = true;
		for (int j = 0; j < i; j++) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
				flag = false;
			}
		}
	}
}

void merge(int* array, int ss, int se, int es, int ee) {
	int* mergedArray = new int[ee - es + se - ss + 2];
	int si, ei, mi;
	si = ss;
	ei = es;
	mi = 0;

	while (si <= se && ei <= ee) {
		mergedArray[mi++] = array[si] < array[ei] ? array[si++] : array[ei++];
	}
	while (si <= se) {
		mergedArray[mi++] = array[si++];
	}
	while (ei <= ee) {
		mergedArray[mi++] = array[ei++];
	}
	for (int i = ss; i <= ee; i++) {
		array[i] = mergedArray[i - ss];
	}
	delete(mergedArray);
}

void mergeSort(int* array, int s, int e) {
	if (s == e) {
		return;
	}
	int m = (s + e) / 2;
	mergeSort(array, s, m);
	mergeSort(array, m + 1, e);
	merge(array, s, m, m + 1, e);
}

void quickSort(int* array, int s, int e) {
	if (s >= e)
		return;

	int left = s;
	int right = e;
	int pivot = array[(s + e) / 2];

	while (s <= e) {
		while (array[s] < pivot) {
			s++;
		}
		while (array[e] > pivot) {
			e--;
		}
		if (s <= e) {
			swap(&array[s], &array[e]);
			s++;
			e--;
		}
	}

	quickSort(array, left, e);
	quickSort(array, s, right);
}

void heapSort(int* array, int size) {
	int heapSize = 2;
	while (size > heapSize - 1) {
		heapSize *= 2;
	}
	Heap myheap(heapSize);

	for (int i = 0; i < size; i++) {
		myheap.push(array[i]);
	}
	for (int i = 0; i < size; i++) {
		array[i] = myheap.top();
		myheap.pop();
	}
}

void countSort(int* array, int size) {
	int max = 0;
	int i;

	for (i = 0; i < size; i++) {
		max = array[i] > max ? array[i] : max;
	}
	max++;
	int* count = new int[max];
	fill_n(count, max, 0);

	for (i = 0; i < size; i++) {
		count[array[i]]++;
	}

	i = 0;

	while (i < size) {
		for (int j = 0; j < max; j++) {
			for (int k = 0; k < count[j]; k++) {
				array[i++] = j;
			}
		}
	}

	delete[] count;
}

int numlen(int input) {
	int length = 0;
	while (input > 0) {
		input /= 10;
		length++;
	}
	return length;
}

int pow(int num, int ex) {
	if (ex == 0)
		return 1;
	else if (ex == 1)
		return num;
	else
		return pow(num, ex / 2) * pow(num, ex / 2) * (ex % 2 == 1 ? num : 1);
}

void radixSort(int* array, int size) {
	int max = 0;

	for (int i = 0; i < size; i++) {
		max = array[i] > max ? array[i] : max;
	}
	int digit = numlen(max);
	int k = 0;
	int j;
	Queue* myqueue = new Queue[10];
	for (int i = 0; i < 10; i++) {
		myqueue[i] = Queue();
	}
	for (int i = 0; i < digit; i++) {
		for (j = 0; j < size; j++) {
			myqueue[(array[j] % pow(10, i + 1)) / pow(10, i)].push(array[j]);
		}
		j = 0;
		k = 0;
		while (k < 10 && j < size) {
			if (myqueue[k].isEmpty()) {
				k++;
				continue;
			}
			array[j++] = myqueue[k].front();
			myqueue[k].pop();
		}
	}
}

void treeSort(int* array, int size) {
	BTree mytree;
	mytree.init();

	for (int i = 0; i < size; i++) {
		mytree.insert(array[i]);
	}

	mytree.printTree();
}

bool isSorted(int* array, int size) {
	int sorted = true;
	for (int i = 0; i < size - 1; i++) {
		sorted = (array[i] < array[i+1]);
		if (!sorted)
			break;
	}
	return sorted;
}

void bogoSort(int* array, int size) {
	srand(time(NULL));
	int aIndex;
	int bIndex;

	while (!isSorted(array, size)) {
		aIndex = rand() % size;
		bIndex = rand() % size;
		swap(array + aIndex, array + bIndex);
	}
}