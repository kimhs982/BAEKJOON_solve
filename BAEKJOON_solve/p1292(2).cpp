// 1292��, ���� Ǫ�� ����
#include <iostream>
using std::ios_base;
using std::cin;
using std::cout;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B;
	cin >> A >> B;

	// sum_A: A��° ���ڱ����� ��, sum_B: B��° ���ڱ����� ��, num: ���� ����, cnt: ���ڰ� ���� Ƚ��
	int sum_A = 0, sum_B = 0, num = 1, cnt = 0;;
	// A��° ���ڱ����� ��
	for (int i = 0; i < A - 1; i++) {
		if (cnt == num) {
			num++;
			cnt = 0;
		}
		sum_A += num;
		cnt++;
	}

	// B��° ���ڱ����� ��
	num = 1, cnt = 0;
	for (int i = 0; i < B; i++) {
		if (cnt == num) {
			num++;
			cnt = 0;
		}
		sum_B += num;
		cnt++;
	}

	cout << sum_B - sum_A << '\n';

	return 0;
}