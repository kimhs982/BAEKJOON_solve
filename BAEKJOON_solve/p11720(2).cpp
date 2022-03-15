// 11720번, 숫자의 합
// STL의 cstdio의 printf와 scanf를 사용
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