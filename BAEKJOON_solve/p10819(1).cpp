// 10819��, ���̸� �ִ��
#include <iostream>
using std::ios_base;
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
using std::find;

#include <cstdlib>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> A(N);

	int min = 100, max = -100, diff_sum = 0;;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] < min) min = A[i];		// �ּڰ� ã��
		if (A[i] > max) max = A[i];		// �ִ� ã��
	}

	diff_sum += (max - min);		// �ִ񰪰� �ּڰ��� ���̸� ���� ó���� ����
	A.erase(find(A.begin(), A.end(), min));		// �ּڰ��� �迭 A���� ����
	A.erase(find(A.begin(), A.end(), max));		// �ִ��� �迭 A���� ����

	int index = 0;
	while (A.size() != 0) {		// �迭 A�� ����� ������ �ݺ�
		int index = 0, diff_max = -1;
		bool is_min = false;
		for (int i = 0; i < A.size(); i++) {		// �迭 A�� ���鼭 �ִ񰪰� �ּڰ� �߿� ���̰� ���� ū ��츦 ã��
			int temp = (abs(min - A[i]) > abs(max - A[i]) ? abs(min - A[i]) : abs(max - A[i]));
			if (diff_max < temp) {
				diff_max = temp;
				index = i;
			}
		}
		if (diff_max == abs(min - A[index]))		// �ּڰ����� ���̰� ���� ū ���
			is_min = true;
		diff_sum += diff_max;
		if (is_min) min = A[index];		// �ִ񰪰� �ּڰ� ����
		else max = A[index];
		A.erase(A.begin() + index);		// �迭 A���� �ش��ϴ� ���ڸ� ����
	}

	cout << diff_sum;

	return 0;
}