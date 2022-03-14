// ���� 1065��, �Ѽ�
#include <iostream>
using namespace std;

int one_num1(int);
int one_num2(int);

int main() {
	int N;
	cin >> N;
	cout << one_num2(N) << endl;

	return 0;
}

// ���� ���� ���ڸ� ��� Ȯ��
int one_num1(int in_N) {
	if (in_N < 100)
		return in_N;

	int start_num = 100, digit[3], count = 99;
	while (start_num <= in_N) {
		if (start_num == 1000)
			break;
		int temp = start_num;
		for (int i = 0; i < 3; i++) {
			digit[i] = temp % 10;
			temp /= 10;
		}
		if ((digit[0] - digit[1]) == (digit[1] - digit[2]))
			count++;
		start_num++;
	}
	return count;
}


// ��Ģ�� �߰�, 3�ڸ��� ������ ��� �� �ڸ������� �Ѽ��� 5���� ���� & ���� 12��ŭ ����
int one_num2(int in_N) {
	if (in_N < 100)
		return in_N;

	int start_num = 100, digit[3], count = 99;
	while (start_num <= in_N) {
		if (start_num == 1000)
			break;
		int temp = start_num;
		for (int i = 0; i < 3; i++) {
			digit[i] = temp % 10;
			temp /= 10;
		}
		if ((digit[0] - digit[1]) == (digit[1] - digit[2])) {
			int max_count = 1;
			while (((start_num += 12) <= in_N) && (max_count < 5))
				max_count++;
			count += max_count;
			start_num = 100 * (digit[2] + 1);
		}
		else
			start_num++;
	}
	return count;
}