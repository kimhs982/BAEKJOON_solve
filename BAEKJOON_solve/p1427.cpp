// 1427��, ��Ʈ�λ��̵�
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <algorithm>
using std::sort;
using std::greater;
using std::swap;

#include <vector>
using std::vector;

void print_descDigit(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	print_descDigit(N);

	return 0;
}

// ����(��ȯ)����
void bubbleSort(vector<int>& arr) {
	for (int i = 0; i < arr.size() - 1; i++)
		for (int j = i + 1; j < arr.size(); j++)
			if (arr[i] < arr[j])
				swap(arr[i], arr[j]);
}

// ��������
void selectionSort(vector<int>& arr) {
	int biggest;
	for (int i = 0; i < arr.size() - 1; i++) {
		biggest = i;
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[biggest] < arr[j])
				biggest = j;
		}
		swap(arr[i], arr[biggest]);
	}
}

// ��������
void insertionSort(vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) {
		int key = arr[i];
		int j = i - 1;
		while ((j >= 0) && (key > arr[j])) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void print_descDigit(int in_N) {
	vector<int> digitList;

	// �� �ڸ����� �����Ͽ� vector �����̳ʿ� ����
	while (in_N > 0) {
		digitList.emplace_back(in_N % 10);
		in_N /= 10;
	}

	// algorithm ��������� sort() �Լ��� ���
	sort(digitList.begin(), digitList.end(), greater<int>());

	for (int i = 0; i < digitList.size(); i++)
		cout << digitList[i];
	cout << '\n';
}