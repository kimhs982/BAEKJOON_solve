// 11051번, 이항 계수2
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using std::min;

int BinomialCoefficient1(int, int);
int BinomialCoefficient2(int, int);
int BinomialCoefficient_rem10007(int, int);

int main() {
	int N, K;
	scanf("%d%d", &N, &K);

	printf("%d\n", BinomialCoefficient_rem10007(N, K));

	return 0;
}

// 이항 계수(DP)
int BinomialCoefficient1(int N, int K) {
	int result;
	// 이항 계수 값들을 저장할 2차원 배열 동적할당
	int** BC = new int* [N + 1];
	for (int i = 0; i < N + 1; i++)
		*(BC + i) = new int[K + 1];

	// nC0인 경우 모두 1로 초기화
	for (int n = 1; n <= N; n++)
		BC[n][0] = 1;

	// 이항 계수 구하기
	for (int n = 1; n <= N; n++)
		for (int k = 1; k <= K; k++) {
			if (n < k)
				continue;
			if (n == k)
				BC[n][k] = 1;
			else
				BC[n][k] = BC[n - 1][k - 1] + BC[n - 1][k];
		}

	// N_C_K 값 저장
	result = BC[N][K];

	// 이항 계수 값들을 저장하고 있는 2차원 배열 메모리 해제
	for (int i = 0; i < N + 1; i++)
		delete[] BC[i];
	delete[] BC;

	return result;
}

// 이항 계수(DP), 실행시간 개선
int BinomialCoefficient2(int N, int K) {
	int result;
	int** BC = new int* [N + 1];
	for (int i = 0; i < N + 1; i++)
		*(BC + i) = new int[K + 1];

	for (int n = 1; n <= N; n++)
		for (int k = 0; k <= min(n, K); k++)
			if ((k == 0) || (k == n))
				BC[n][k] = 1;
			else
				BC[n][k] = BC[n - 1][k - 1] + BC[n - 1][k];

	result = BC[N][K];

	for (int i = 0; i < N + 1; i++)
		delete[] BC[i];
	delete[] BC;

	return result;
}

int BinomialCoefficient_rem10007(int N, int K) {
	int result;
	int** BC = new int* [N + 1];
	for (int i = 0; i < N + 1; i++)
		*(BC + i) = new int[K + 1];

	for (int n = 1; n <= N; n++)
		for (int k = 0; k <= min(n, K); k++) {
			if ((k == 0) || (k == n))
				BC[n][k] = 1;
			else
				BC[n][k] = (BC[n - 1][k - 1] + BC[n - 1][k]) % 10007;
		}

	result = BC[N][K];

	for (int i = 0; i < N + 1; i++)
		delete[] BC[i];
	delete[] BC;

	return result;
}