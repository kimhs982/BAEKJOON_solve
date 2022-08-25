// 15652번, N과 M (4)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int num_arr[8];

void NandM(int, int, int);

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	NandM(N, M, 0);

	return 0;
}

// 백트래킹, 재귀함수
void NandM(int in_N, int in_M, int height) {
	if (height == in_M) {
		for (int i = 0; i < in_M; i++)
			printf("%d ", num_arr[i]);
		printf("\n");
	}
	else {
		for (int i = (height - 1 < 0 ? 1 : num_arr[height - 1]); i <= in_N; i++) {
			num_arr[height] = i;
			NandM(in_N, in_M, height + 1);
		}
	}
}