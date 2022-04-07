// 1929번, 소수 구하기, iostream의 cout, cin, endl은 실행 속도가 느림(특히 endl은 버퍼를 flush하여 느림)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

int main() {
	int M, N;
	scanf("%d%d", &M, &N);
	int* num_list = new int[N + 1]{ 1,1,0 };

	for (int i = 2; i <= sqrt(N); i++)
		for (int j = i; i * j <= N; j++)
			num_list[i * j] = 1;

	for (int i = M; i <= N; i++)
		if (num_list[i] == 0)
			printf("%d\n", i);

	delete[] num_list;

	return 0;
}