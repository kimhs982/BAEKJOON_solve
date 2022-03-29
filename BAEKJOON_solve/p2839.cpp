// 2839번, 설탕 배달
#include <iostream>
using namespace std;

int main() {
	int N, count_5 = 0, count_3 = 0;
	cin >> N;

	count_5 = N / 5;
	for (int i = 0; i < (N / 5); i++) {
		int temp = N - count_5 * 5;
		if (temp % 3 == 0) {
			count_3 = temp / 3;
			break;
		}
		else
			count_5--;
	}
	if ((N % 3 == 0) && (count_5 == 0))
		count_3 = N / 3;
	else if (count_5 == 0)
		count_3 = -1;

	cout << count_3 + count_5 << endl;

	return 0;
}