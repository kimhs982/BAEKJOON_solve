// 11050번, 이항 계수1
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int BinomialCoefficient(int, int);

int main() {
	int N, K;
	scanf("%d%d", &N, &K);

	printf("%d\n", BinomialCoefficient(N, (K < N - K ? K : N - K)));		// nCk = nCn-k 성질을 이용

	return 0;
}

// nCk = nCn-k = n! / k!(n-k)! = n(n-1)...(n-(k-1)) / k!
int BinomialCoefficient(int in_N, int in_K) {
	int numerator = in_N, denominator = in_K;
	for (int i = 1; i < in_K; i++) {
		numerator *= (in_N - i);
		denominator *= (in_K - i);
	}

	if (denominator != 0)
		return numerator / denominator;
	else
		return 1;
}