// 1712번, 손익분기점
#include <iostream>
using namespace std;

int main() {
	int A, B, C, BEP;
	cin >> A >> B >> C;

	if (C - B <= 0)
		BEP = -1;
	else
		BEP = (A / (C - B)) + 1;

	cout << BEP << endl;

	return 0;
}