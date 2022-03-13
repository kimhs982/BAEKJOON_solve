// 백준 2525번, 오븐 시계 문제
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	int A, B, C;

	cin >> A >> B;
	cin >> C;

	if (B + C >= 60) {
		int carry = 1;
		B = B + C - 60;
		while (1) {
			if (B >= 60) {
				carry++;
				B -= 60;
			}
			else
				break;
		}
		if (A + carry >= 24)
			A = A + carry - 24;
		else
			A += carry;
	}
	else
		B += C;

	cout << A << " " << B << endl;

	return 0;
}