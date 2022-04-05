// 1929��, �Ҽ� ���ϱ�, �ð� �ʰ�(�迭)
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

	for (int i = 2; i <= sqrt(in_end); i++) {		// ���� ���� n�� �ռ����̸�, n�� ���μ� �߿��� p <= n^1/2�� ���μ� p�� ����, �����佺�׳׽��� ü
		bool pDecision = true;
		for (int j = 2; j <= sqrt(i); j++)		// �Ҽ� �Ǵ�
			if (i % j == 0)
				pDecision = false;
		if (pDecision == false)
			continue;

		int index = 0, mul = 2, j;
		for (j = i * mul; j <= in_end; j = i * (++mul)) {		// �Ҽ��� ����� �߿� ���� ���� �����ϴ� ������ index�� ã�Ƽ� ��ȯ
			if (j < in_start)
				continue;
			index = array_search(num_list, size, j);
			if (index != -1)
				break;
			else
				continue;
		}

		for (int l = index; l < size; l += i)		// �Ҽ��� ����� ��� 0���� �ٲ�
			num_list[l] = 0;
	}

	for (int i = 0; i < size; i++)
		if (num_list[i] != 0)
			cout << num_list[i] << endl;

	delete[] num_list;
}