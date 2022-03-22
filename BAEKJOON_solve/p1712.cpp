// 1712번, 손익분기점
#include <iostream>
using namespace std;

int main() {
	int A, B, C, BEP = 0;
	unsigned int cost, earn;
	cin >> A >> B >> C;

	if (B >= C)
		BEP = -1;
	else
		while (1) {
			cost = A + B * BEP;
			earn = C * BEP;
			if (earn > cost)
				break;
			BEP++;
		}

	cout << BEP << endl;

	return 0;
}