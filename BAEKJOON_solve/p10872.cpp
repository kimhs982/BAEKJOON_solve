// 10872¹ø, ÆÑÅä¸®¾ó
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int factorial_recursive(int);
int factorial_forStatement(int);

int main() {
	int N;
	scanf("%d", &N);

	printf("%d\n", factorial_recursive(N));
	printf("%d\n", factorial_forStatement(N));

	return 0;
}

int factorial_recursive(int in_N) {		// Àç±Í
	if (in_N == 0 || in_N == 1)
		return 1;
	else
		return factorial_recursive(in_N - 1) * in_N;
}

int factorial_forStatement(int in_N) {		// ¹Ýº¹¹®
	if (in_N == 0 || in_N == 1)
		return 1;

	int result = 1;
	for (int i = 2; i <= in_N; i++)
		result *= i;

	return result;
}