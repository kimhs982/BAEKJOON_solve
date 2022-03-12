// ���� 4673��, ���� �ѹ�(�����ڰ� ���� ����)�� ���ϴ� ���α׷� <- ���� ���� n(������) + n�� �� �ڸ���
// STL�� iostream�� �ִ� cout, endl�� �̿��Ͽ� ���

#include <iostream>
using namespace std;

int d(int);

int main() {
	int* num_container = new int[10000]();
	int temp;

	for (int i = 1; i <= 10000; i++) {
		temp = d(i);
		while (1) {
			if (temp <= 10000) {
				num_container[temp - 1]++;
				temp = d(temp);
			}
			else
				break;
		}
	}

	for (int i = 0; i < 10000; i++)
		if (num_container[i] == 0)
			cout << i + 1 << endl;

	delete[] num_container;

	return 0;
}

int d(int n) {
	int temp = n;
	while (1) {
		n += temp % 10;
		if ((temp / 10) >= 1) {
			temp /= 10;
		}
		else
			break;
	}
	return n;
}