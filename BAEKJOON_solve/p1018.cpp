// 1018, 체스판 다시 칠하기
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int min_chessBoardRecolor(char**, int, int);

int main() {
	int N, M, count_recolor;
	scanf("%d%d", &N, &M);

	char** chessBoard = new char* [N];
	for (int i = 0; i < N; i++) {
		*(chessBoard + i) = new char[M + 1];
		scanf("%s", chessBoard[i]);
	}

	count_recolor = min_chessBoardRecolor(chessBoard, N, M);

	printf("%d\n", count_recolor);

	return 0;
}

int min_chessBoardRecolor(char** in_ChessBoard, int in_N, int in_M) {
	int count1, count2, count = 0, min_count = 0;

	for (int i = 0; i < in_M - 7; i++)
		for (int j = 0; j < in_N - 7; j++) {
			count1 = count2 = 0;
			// 첫 번째 칸이 검은색인 경우
			for (int k = j; k < j + 8; k++) {
				if (k % 2 == 0)
					for (int l = i; l < i + 8; l++) {
						if ((l % 2 == 0) && (in_ChessBoard[k][l] != 'B'))
							count1++;
						else if ((l % 2 != 0) && (in_ChessBoard[k][l] != 'W'))
							count1++;
					}
				else
					for (int l = i; l < i + 8; l++) {
						if ((l % 2 == 0) && (in_ChessBoard[k][l] != 'W'))
							count1++;
						else if ((l % 2 != 0) && (in_ChessBoard[k][l] != 'B'))
							count1++;
					}
			}

			// 첫 번째 칸이 흰색인 경우
			for (int k = j; k < j + 8; k++) {
				if (k % 2 == 0)
					for (int l = i; l < i + 8; l++) {
						if ((l % 2 == 0) && (in_ChessBoard[k][l] != 'W'))
							count2++;
						else if ((l % 2 != 0) && (in_ChessBoard[k][l] != 'B'))
							count2++;
					}
				else
					for (int l = i; l < i + 8; l++) {
						if ((l % 2 == 0) && (in_ChessBoard[k][l] != 'B'))
							count2++;
						else if ((l % 2 != 0) && (in_ChessBoard[k][l] != 'W'))
							count2++;
					}
			}

			// 첫 번째 칸이 검은색 또는 흰색인 경우를 비교하여 더 작은 값을 선택
			if (count1 < count2)
				count = count1;
			else
				count = count2;

			// 최소값을 찾음
			if (i == 0)
				min_count = count;
			else if (min_count > count)
				min_count = count;
		}

	return min_count;
}