// 11729번, 하노이 탑 이동 순서
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>

void HanoiTower(int, int, int, int);

int main() {
	int N;
	scanf("%d", &N);
	printf("%d\n", int(pow(2, N) - 1));
	HanoiTower(1, 2, 3, N);

	return 0;
}

// 분할 정복(divide and conquer)
/*
원판이 2개인 경우
	1. 1 -> 2
	2. 1 -> 3
	3. 2 -> 3
원판이 3개 이상인 경우 -> 1층 원판 이외의 나머지 원판을 모두 묶어 하나의 원판으로 간주 -> 2개의 원판을 옮기는 것으로 생각
*/
void HanoiTower(int from, int temp, int to, int in_N) {
	if (in_N == 1)
		printf("%d %d\n", from, to);
	else {
		HanoiTower(from, to, temp, in_N - 1);
		printf("%d %d\n", from, to);
		HanoiTower(temp, from, to, in_N - 1);
	}
}