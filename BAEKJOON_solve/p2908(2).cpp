// 2908��, ���
// char�� �迭�� ����Ͽ� ���ڸ� ���ڷ� �����ϰ�, �ƽ�Ű�ڵ� ���� �̿��Ͽ� ��꿡 ���
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	char num1[4], num2[4];
	int res1 = 0, res2 = 0;
	cin >> num1 >> num2;

	for (int i = 0; i < 3; i++) {
		res1 += (static_cast<int>(num1[2 - i]) - 48) * static_cast<int>(pow(10, 2 - i));
		res2 += (static_cast<int>(num2[2 - i]) - 48) * static_cast<int>(pow(10, 2 - i));
	}

	if (res1 > res2)
		cout << res1 << endl;
	else
		cout << res2 << endl;

	return 0;
}