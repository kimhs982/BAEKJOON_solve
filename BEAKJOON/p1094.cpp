// 1094번, 막대기
#include <iostream>

using namespace std;

int divideAndMergeStick(int);

int main() {
	int X;
	cin >> X;
	cout << divideAndMergeStick(X) << '\n';
}

int divideAndMergeStick(const int X) {
	if (X == 64) return 1;

	int half_stick = 64;
	int stick_count = 1, stick_sum = 0;
	while (stick_sum != X) {
		half_stick /= 2;
		if (half_stick > X) continue;
		else if (half_stick < X) {
			if (stick_sum + half_stick < X) {
				stick_count++;
				stick_sum += half_stick;
			}
			else if (stick_sum + half_stick > X)
				continue;
			else
				stick_sum += half_stick;
		}
		else
			stick_sum = half_stick;
	}

	return stick_count;
}