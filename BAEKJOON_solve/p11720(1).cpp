// 11720��, ������ ��
// STL�� iostream�� cout�� cin�� ���
#include <iostream>
using namespace std;

int main() {
	int N, sum = 0;
	cin >> N;
	char* str = new char[N + 1];

	cin >> str;
	for (int i = 0; i < N; i++)
		sum += (str[i] - 48);

	cout << sum << endl;

	delete[] str;
	return 0;
}