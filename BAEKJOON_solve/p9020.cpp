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

		if (isPN(n / 2)) {
			PN1 = PN2 = n / 2;
			printf("%d %d\n", PN1, PN2);
			continue;
		}

		if ((n / 2) % 2 == 0)
			for (int j = n / 2 + 1; j < n; j += 2) {
				if (isPN(j) && isPN(n - j)) {
					PN2 = j;
					PN1 = n - PN2;
					printf("%d %d\n", PN1, PN2);
					break;
				}
			}
		else
			for (int j = n / 2 + 2; j < n; j += 2) {
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