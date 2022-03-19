// 2908번, 상수
// int형으로 계산 처리
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int num1[2]{ 0 }, num2[2]{ 0 };
	cin >> num1[0] >> num2[0];

	for (int i = 0; i < 3; i++) {
		num1[1] += (num1[0] % 10) * pow(10, 2 - i);
		num1[0] /= 10;
		num2[1] += (num2[0] % 10) * pow(10, 2 - i);
		num2[0] /= 10;
	}

	if (num1[1] > num2[1])
		cout << num1[1] << endl;
	else
		cout << num2[1] << endl;

	return 0;
}