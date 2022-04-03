// 11653번, 소인수분해
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

void factorization_into_primes(int);

int main() {
	int N;
	scanf("%d", &N);

	factorization_into_primes(N);

	return 0;
}

void factorization_into_primes(int in_N) {
	int prime = 2;
	while (1) {
		if (in_N == 1)
			break;
		if (in_N % prime == 0) {
			printf("%d\n", prime);
			in_N /= prime;
		}
		else
			prime++;
	}
}