// 백준 1065번, 한수
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

// 범위 내의 숫자를 모두 확인
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


// 규칙성 발견, 3자리수 숫자일 경우 각 자리수마다 한수가 5개씩 존재 & 각각 12만큼 차이
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