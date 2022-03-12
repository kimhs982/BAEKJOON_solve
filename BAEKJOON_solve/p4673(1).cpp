// 백준 4673번, 셀프 넘버(생성자가 없는 숫자)를 구하는 프로그램 <- 양의 정수 n(생성자) + n의 각 자리수
// STL의 iostream에 있는 cout, endl을 이용하여 출력

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