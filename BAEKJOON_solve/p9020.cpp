// 9020번, 골드바흐의 추측
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

bool isPN(int);

int main() {
	int T, n, PN1, PN2;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &n);

		if (isPN(n / 2)) {		// n/2가 소수인 경우
			PN1 = PN2 = n / 2;		// 두 소수가 n/2인 경우 차이가 가장 작음
			printf("%d %d\n", PN1, PN2);
			continue;
		}

		// n/2가 소수가 아닌 경우
		if ((n / 2) % 2 == 0)		// n/2가 짝수인 경우
			for (int j = n / 2 + 1; j < n; j += 2) {		// n/2 + 1(n/2에 가장 가까운 홀수부터 확인)부터 n보다 작을 때까지 2씩 증가시켜 홀수만 확인
				if (isPN(j) && isPN(n - j)) {
					PN2 = j;
					PN1 = n - PN2;
					printf("%d %d\n", PN1, PN2);
					break;
				}
			}
		// n/2가 홀수인 경우
		else
			for (int j = n / 2 + 2; j < n; j += 2) {		// n/2 + 2(n/2에 가장 가까운 홀수부터 확인)부터 n보다 작을 때까지 2씩 증가시켜 홀수만 확인
				if (isPN(j) && isPN(n - j)) {
					PN2 = j;
					PN1 = n - PN2;
					printf("%d %d\n", PN1, PN2);
					break;
				}
			}
	}

	return 0;
}

bool isPN(int num) {
	for (int i = 2; i <= sqrt(num); i++)
		if (num % i == 0)
			return false;

	return true;
}