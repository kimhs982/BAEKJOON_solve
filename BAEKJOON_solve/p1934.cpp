// 1934번, 최소공배수
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int getGCD(int, int);

int main() {
	int T;
	scanf("%d", &T);

	int first, second, GCD;
	for (int i = 0; i < T; i++) {
		scanf("%d%d", &first, &second);
		GCD = getGCD(first, second);
		/*int j, low = (first < second ? first : second);
		for (j = low; j > 1; j--)
			if ((first % j == 0) && (second % j == 0)) {
				GCD = j;
				break;
			}
		if (j == 1)
			GCD = 1;*/
		printf("%d\n", first * second / GCD);
	}

	return 0;
}

// 유클리드 호제법, 정수 a, b, q r (b ≠ 0)에 대하여 a = bq + r,이면 G(a, b) = G(b, r)가 성립
int getGCD(int first, int second) {
	if (second == 0)
		return first;
	else
		return getGCD(second, first % second);
}