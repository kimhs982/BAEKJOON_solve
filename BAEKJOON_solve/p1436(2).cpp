// 1436번, 영화감독 숌
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int getEndNum(int);

int main() {
	int N, end;

	scanf("%d", &N);
	end = getEndNum(N);
	printf("%d\n", end);

	return 0;
}

int getEndNum(int in_N) {
	int start = 665, count = 0, temp;
	
	// 666부터 숫자를 1씩 증가시키면서 종말의 수인지 확인
	while (count != in_N) {
		start++;
		temp = start;
		/*if (temp % 1000 == 666)
			count++;
		else
			while ((temp /= 10) > 0)
				if (temp % 1000 == 666) {
					count++;
					break;
				}*/
		while (temp > 0) {
			if (temp % 1000 == 666) {
				count++;
				break;
			}
			temp /= 10;
		}
	}

	return start;
}