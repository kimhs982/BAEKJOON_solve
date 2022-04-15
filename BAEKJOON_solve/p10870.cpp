// 10870번, 피보나치 수 5
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <ctime>

int fibonacci_recursive(int);
int fibonacci_forStatement(int);

int main() {
	int n;
	scanf("%d", &n);
	
	clock_t start, end;
	double result;

	printf("%d\n", fibonacci_recursive(n));
	printf("%d\n", fibonacci_forStatement(n));

	return 0;
}

int fibonacci_recursive(int in_n) {
	if (in_n == 0 || in_n == 1)
		return in_n;
	else
		return fibonacci_recursive(in_n - 1) + fibonacci_recursive(in_n - 2);
}

int fibonacci_forStatement(int in_n) {
	int result[2] = { 0,1 };
	
	if (in_n == 0 || in_n == 1)
		return result[in_n];

	for (int i = 2; i <= in_n; i++) {
		if (i == in_n)
			return result[0] + result[1];

		if (i % 2 == 0)
			result[0] += result[1];
		else
			result[1] += result[0];
	}
}