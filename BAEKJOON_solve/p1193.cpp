// 1193번, 분수찾기
#include <iostream>
using namespace std;

int main() {
	int X, numerator = 1, denominator = 1;
	int diag_num = 1, diag_count = 0;
	bool r_decision = true, diag_decision = false, f_diag_decision = true;
	cin >> X;

	for (int i = 1; i < X; i++) {
		if (diag_decision == false) {
			if (r_decision == true) {		// 오른쪽 이동
				denominator++;
				r_decision = false;
			}
			else {		// 아래 이동
				numerator++;
				r_decision = true;
			}
			diag_decision = true;		// 오른쪽 또는 아래 이동 이후에는 대각선 이동
		}
		else {		// 대각선 이동
			if (f_diag_decision == true) {		// 하향 대각선 이동
				numerator++;
				denominator--;
			}
			else {		// 상향 대각선 이동
				numerator--;
				denominator++;
			}
			diag_count++;
			if (diag_count == diag_num) {		// 특정 구간의 대각선 이동을 모두 완료
				diag_count = 0;
				diag_num++;
				diag_decision = false;
				f_diag_decision = !(f_diag_decision);
			}
		}
	}
	
	cout << numerator << "/" << denominator << endl;

	return 0;
}