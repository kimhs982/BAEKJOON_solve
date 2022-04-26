// 2751��, �� �����ϱ�2
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

// ����ȭ �˰���, ��������
void heapify(int arr[], int h, int m) {
	// ��Ʈ h�� ������ h�� ���� ����Ʈ���� ������ ����Ʈ���� ����
	// ���� �������� ����� �ִ� ���� ���� ��ȣ�� m
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

// ���� ���� �˰���, O(nlogn)
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