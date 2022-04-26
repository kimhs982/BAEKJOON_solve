// 2751번, 수 정렬하기2
#include <iostream>
#include <algorithm>
using namespace std;

void heapSort(int[], int);

int main() {
	int N;
	cin >> N;

	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	//sort(arr, arr + N);
	heapSort(arr, N);

	for (int i = 0; i < N; i++)
		cout << arr[i] << '\n';

	delete[] arr;
	return 0;
}

// 히프화 알고리즘, 오름차순
void heapify(int arr[], int h, int m) {
	// 루트 h를 제외한 h의 왼쪽 서브트리와 오른쪽 서브트리는 히프
	// 현재 시점으로 노드의 최대 레벨 순서 번호는 m
	int rootVal = arr[h], i;

	for (i = 2 * h + 1; i < m; i = i * 2 + 1)
	{
		if ((i < m - 1) && (arr[i] < arr[i + 1]))
			i++;
		if (rootVal >= arr[i])
			break;
		else
			arr[(i - 1) / 2] = arr[i];
	}
	arr[(i - 1) / 2] = rootVal;
}

// 히프 정렬 알고리즘, O(nlogn)
void heapSort(int arr[], int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, i, size);
	for (int i = size - 2; i >= 0; i--)
	{
		int temp = arr[0];
		arr[0] = arr[i + 1];
		arr[i + 1] = temp;
		heapify(arr, 0, i + 1);
	}
}