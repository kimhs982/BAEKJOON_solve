// 11729��, �ϳ��� ž �̵� ����
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

// ���� ����(divide and conquer)
/*
������ 2���� ���
	1. 1 -> 2
	2. 1 -> 3
	3. 2 -> 3
������ 3�� �̻��� ��� -> 1�� ���� �̿��� ������ ������ ��� ���� �ϳ��� �������� ���� -> 2���� ������ �ű�� ������ ����
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