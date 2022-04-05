// 1929번, 소수 구하기, 시간 초과(배열)
#include <iostream>
#include <cmath>

using namespace std;

void print_primeNum(int, int);

int main() {
	int start, end;
	cin >> start >> end;

	print_primeNum(start, end);

	return 0;
}

int array_search(const int in_list[], int size, int key) {
	for (int i = 0; i < size; i++)
		if (in_list[i] == key)
			return i;
	return -1;
}

void print_primeNum(int in_start, int in_end) {
	int size = in_end - in_start + 1;
	int temp_index = 0;
	int* num_list = new int[size];
	for (int i = in_start; i <= in_end; i++) {
		if (i == 1)
			continue;
		num_list[temp_index] = i;
		temp_index++;
	}
	if (in_start == 1) {
		num_list[temp_index] = 0;
		size--;
	}

	for (int i = 2; i <= sqrt(in_end); i++) {		// 양의 정수 n이 합성수이면, n의 소인수 중에는 p <= n^1/2인 소인수 p가 존재, 에라토스테네스의 체
		bool pDecision = true;
		for (int j = 2; j <= sqrt(i); j++)		// 소수 판단
			if (i % j == 0)
				pDecision = false;
		if (pDecision == false)
			continue;

		int index = 0, mul = 2, j;
		for (j = i * mul; j <= in_end; j = i * (++mul)) {		// 소수의 배수들 중에 가장 먼저 시작하는 숫자의 index를 찾아서 반환
			if (j < in_start)
				continue;
			index = array_search(num_list, size, j);
			if (index != -1)
				break;
			else
				continue;
		}

		for (int l = index; l < size; l += i)		// 소수의 배수를 모두 0으로 바꿈
			num_list[l] = 0;
	}

	for (int i = 0; i < size; i++)
		if (num_list[i] != 0)
			cout << num_list[i] << endl;

	delete[] num_list;
}