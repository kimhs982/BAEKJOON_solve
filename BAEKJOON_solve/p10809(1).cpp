// 10809��, ���ĺ� ã��
// STL�� iostream�� cout�� cin�� ���
#include <iostream>
using namespace std;

int main() {
	char S[101];
	int alpha[26];
	//memset(alpha, -1, sizeof(alpha));				// value���� ���� 1����Ʈ ���� �޸𸮿� �� -> 1����Ʈ �迭 : 256 �̸��� �� & 1 ����Ʈ �ʰ� �迭 : 0�� -1�� ����
	fill_n(alpha, 26, -1);		// value ���� ������ ���� ����
	cin >> S;

	int i = 0, index;
	while (S[i] != '\0') {
		index = S[i] - 97;
		if(alpha[index]==-1)
			alpha[index] = i;
		i++;
	}

	for (int j = 0; j < 26; j++)
		cout << alpha[j] << " ";

	return 0;
}