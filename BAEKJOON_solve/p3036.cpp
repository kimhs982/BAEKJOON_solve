// 3036번, 링
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int getGCD(int, int);

int main() {
	int N;
	scanf("%d", &N);
	int* radiusList = new int[N];
	for (int i = 0; i < N; i++)
		scanf("%d", radiusList + i);
	
	int GCD;
	for (int i = 1; i < N; i++) {
		GCD = getGCD(radiusList[0], radiusList[i]);
		printf("%d/%d\n", radiusList[0] / GCD, radiusList[i] / GCD);
	}

	return 0;
}

// 유클리드 호제법
int getGCD(int num1, int num2) {
	if (num2 == 0)
		return num1;
	else
		return getGCD(num2, num1 % num2);
}