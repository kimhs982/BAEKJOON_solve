// 1292번, 쉽게 푸는 문제
#include <iostream>
using std::ios_base;
using std::cin;
using std::cout;

#include <memory>
using std::unique_ptr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B;
	cin >> A >> B;

	// 수열 미리 계산
	unique_ptr<int[]> num_arr(new int[B]);
	int num = 1, cnt = 0;
	for (int i = 0; i < B; i++) {
		if (num == cnt)
			num++, cnt = 0;
		num_arr[i] = num;
		cnt++;
	}

	// 수열에서 각 범위에 해당하는 값의 합 계산
	int sum = 0;
	for (int i = A - 1; i < B; i++)
		sum += num_arr[i];

	cout << sum;

	return 0;
}