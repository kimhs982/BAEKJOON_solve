// 9020��, �������� ����
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

bool isPN(int);

int main() {
	int T, n, PN1, PN2;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &n);

		if (isPN(n / 2)) {		// n/2�� �Ҽ��� ���
			PN1 = PN2 = n / 2;		// �� �Ҽ��� n/2�� ��� ���̰� ���� ����
			printf("%d %d\n", PN1, PN2);
			continue;
		}

		// n/2�� �Ҽ��� �ƴ� ���
		if ((n / 2) % 2 == 0)		// n/2�� ¦���� ���
			for (int j = n / 2 + 1; j < n; j += 2) {		// n/2 + 1(n/2�� ���� ����� Ȧ������ Ȯ��)���� n���� ���� ������ 2�� �������� Ȧ���� Ȯ��
				if (isPN(j) && isPN(n - j)) {
					PN2 = j;
					PN1 = n - PN2;
					printf("%d %d\n", PN1, PN2);
					break;
				}
			}
		// n/2�� Ȧ���� ���
		else
			for (int j = n / 2 + 2; j < n; j += 2) {		// n/2 + 2(n/2�� ���� ����� Ȧ������ Ȯ��)���� n���� ���� ������ 2�� �������� Ȧ���� Ȯ��
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