// 1193��, �м�ã��
#include <iostream>
using namespace std;

int main() {
	int X, numerator = 1, denominator = 1;
	int diag_num = 1, diag_count = 0;
	bool r_decision = true, diag_decision = false, f_diag_decision = true;
	cin >> X;

	for (int i = 1; i < X; i++) {
		if (diag_decision == false) {
			if (r_decision == true) {		// ������ �̵�
				denominator++;
				r_decision = false;
			}
			else {		// �Ʒ� �̵�
				numerator++;
				r_decision = true;
			}
			diag_decision = true;		// ������ �Ǵ� �Ʒ� �̵� ���Ŀ��� �밢�� �̵�
		}
		else {		// �밢�� �̵�
			if (f_diag_decision == true) {		// ���� �밢�� �̵�
				numerator++;
				denominator--;
			}
			else {		// ���� �밢�� �̵�
				numerator--;
				denominator++;
			}
			diag_count++;
			if (diag_count == diag_num) {		// Ư�� ������ �밢�� �̵��� ��� �Ϸ�
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