// 11720��, ������ ��
// STL�� cstdio�� printf�� scanf�� ���
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	int N, sum = 0;
	scanf("%d", &N);
	char* str = new char[N + 1];

	scanf("%s", str);
	for (int i = 0; i < N; i++)
		sum += (str[i] - 48);

	printf("%d\n", sum);

	delete[] str;
	return 0;
}