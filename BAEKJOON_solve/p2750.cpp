// 2750번, 수 정렬하기
#include <iostream>
using namespace std;

void selectionSort(int[], int);
void insertionSort(int[], int);
void bubbleSort(int[], int);

int main() {
	int N;
	cin >> N;

	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	// 정렬 함수
	insertionSort(arr, N);

	for (int i = 0; i < N; i++)
		cout << arr[i] << '\n';

	delete[] arr;
	return 0;
}

void swap(int& num1, int& num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

// 선택 정렬 알고리즘, O(n^2), unstable
void selectionSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
			if (arr[minIndex] > arr[j])
				minIndex = j;
		swap(arr[i], arr[minIndex]);
	}
}

// 버블(교환) 정렬 알고리즘, O(n^2), stable
void bubbleSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
}

// 삽입 정렬 알고리즘, O(n^2), stable
void insertionSort(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		while ((j >= 0) && (arr[j] > key)) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}