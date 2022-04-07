// 1929번, 소수 구하기, iostream의 cout, cin, endl의 실행 속도가 느림(특히 endl은 버퍼를 flush하여 속도가 느림)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

void printPN(int, int);

int main() {
	int M, N;
	scanf("%d%d", &M, &N);

	printPN(M, N);

	return 0;
}

void printPN(int start, int end) {
	for (int i = start; i <= end; i++) {
		if (i == 1)		// M이 1이 입력된 경우
			continue;
		else if (int(sqrt(i)) == 1) {		// 2와 3인 경우 -> 2와 3 모두 소수이므로 출력
			printf("%d\n", i);
			continue;
		}
		if (i % 2 != 0) {		// 2의 배수가 아닌 경우(홀수)
			bool check = true;
			for (int j = 3; j <= sqrt(i); j += 2)		// 3부터 제곱근 전까지 홀수로 나누어 떨어지는지 확인
				if (i % j == 0) {
					check = false;
					break;
				}
			if (check)		// 홀수중에 소수인 경우 출력
				printf("%d\n", i);
		}
	}
}