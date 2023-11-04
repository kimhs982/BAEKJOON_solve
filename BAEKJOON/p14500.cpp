// 14500번, 테트로미노
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 내가 푼 방법
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int N, M;
//	cin >> N >> M;
//	vector<int> scorePaper(N * M);
//	for (int i{ 0 }; i < N; i++)
//		for (int j{ 0 }; j < M; j++)
//			cin >> scorePaper[i * M + j];
//
//	int max = INT_MIN;
//	for (int i{ 0 }; i < N; i++)
//		for (int j{ 0 }; j < M - 3; j++) {
//			int temp = scorePaper[i * M + j] + scorePaper[i * M + j + 1] + scorePaper[i * M + j + 2] + scorePaper[i * M + j + 3];
//			if (temp > max)
//				max = temp;
//
//		}
//
//	for (int i{ 0 }; i < N - 3; i++)
//		for (int j{ 0 }; j < M; j++) {
//			int temp = scorePaper[i * M + j] + scorePaper[(i + 1) * M + j] + scorePaper[(i + 2) * M + j] + scorePaper[(i + 3) * M + j];
//			if (temp > max)
//				max = temp;
//		}
//
//	for (int i{ 0 }; i < N - 1; i++)
//		for (int j{ 0 }; j < M - 1; j++) {
//			int temp = scorePaper[i * M + j] + scorePaper[(i + 1) * M + j] + scorePaper[i * M + j + 1] + scorePaper[(i + 1) * M + j + 1];
//			if (temp > max)
//				max = temp;
//		}
//
//	for (int i{ 0 }; i < N - 2; i++)
//		for (int j{ 0 }; j < M - 1; j++) {
//			int temp1 = scorePaper[i * M + j] + scorePaper[(i + 1) * M + j] + scorePaper[(i + 2) * M + j] + scorePaper[(i + 2) * M + j + 1];
//			int temp2 = scorePaper[i * M + j] + scorePaper[(i + 1) * M + j] + scorePaper[(i + 2) * M + j] + scorePaper[i * M + j + 1];
//			if (temp1 > max)
//				max = temp1;
//			if (temp2 > max)
//				max = temp2;
//		}
//
//	for (int i{ 1 }; i < N; i++)
//		for (int j{ 0 }; j < M - 2; j++) {
//			int temp1 = scorePaper[i * M + j] + scorePaper[i * M + j + 1] + scorePaper[i * M + j + 2] + scorePaper[(i - 1) * M + j];
//			int temp2 = scorePaper[i * M + j] + scorePaper[i * M + j + 1] + scorePaper[i * M + j + 2] + scorePaper[(i - 1) * M + j + 2];
//			if (temp1 > max)
//				max = temp1;
//			if (temp2 > max)
//				max = temp2;
//		}
//
//	for (int i{ 0 }; i < N - 2; i++)
//		for (int j{ 1 }; j < M; j++) {
//			int temp1 = scorePaper[i * M + j] + scorePaper[(i + 1) * M + j] + scorePaper[(i + 2) * M + j] + scorePaper[(i + 2) * M + j - 1];
//			int temp2 = scorePaper[i * M + j] + scorePaper[(i + 1) * M + j] + scorePaper[(i + 2) * M + j] + scorePaper[i * M + j - 1];
//			if (temp1 > max)
//				max = temp1;
//			if (temp2 > max)
//				max = temp2;
//		}
//
//	for (int i{ 0 }; i < N - 1; i++)
//		for (int j{ 0 }; j < M - 2; j++) {
//			int temp1 = scorePaper[i * M + j] + scorePaper[i * M + j + 1] + scorePaper[i * M + j + 2] + scorePaper[(i + 1) * M + j];
//			int temp2 = scorePaper[i * M + j] + scorePaper[i * M + j + 1] + scorePaper[i * M + j + 2] + scorePaper[(i + 1) * M + j + 2];
//			if (temp1 > max)
//				max = temp1;
//			if (temp2 > max)
//				max = temp2;
//		}
//
//	for (int i{ 1 }; i < N - 1; i++)
//		for (int j{ 0 }; j < M - 1; j++) {
//			int temp1 = scorePaper[i * M + j] + scorePaper[i * M + j + 1] + scorePaper[(i - 1) * M + j] + scorePaper[(i + 1) * M + j + 1];
//			int temp2 = scorePaper[i * M + j] + scorePaper[i * M + j + 1] + scorePaper[(i - 1) * M + j + 1] + scorePaper[(i + 1) * M + j];
//			if (temp1 > max)
//				max = temp1;
//			if (temp2 > max)
//				max = temp2;
//		}
//
//	for (int i{ 0 }; i < N - 1; i++)
//		for (int j{ 1 }; j < M - 1; j++) {
//			int temp1 = scorePaper[i * M + j] + scorePaper[(i + 1) * M + j] + scorePaper[i * M + j + 1] + scorePaper[(i + 1) * M + j - 1];
//			int temp2 = scorePaper[i * M + j] + scorePaper[(i + 1) * M + j] + scorePaper[i * M + j - 1] + scorePaper[(i + 1) * M + j + 1];
//			if (temp1 > max)
//				max = temp1;
//			if (temp2 > max)
//				max = temp2;
//		}
//
//	for (int i{ 0 }; i < N - 1; i++)
//		for (int j{ 1 }; j < M - 1; j++) {
//			int temp1 = scorePaper[i * M + j - 1] + scorePaper[i * M + j] + scorePaper[i * M + j + 1] + scorePaper[(i + 1) * M + j];
//			int temp2 = scorePaper[(i + 1) * M + j - 1] + scorePaper[(i + 1) * M + j] + scorePaper[(i + 1) * M + j + 1] + scorePaper[i * M + j];
//			if (temp1 > max)
//				max = temp1;
//			if (temp2 > max)
//				max = temp2;
//		}
//
//	for (int i{ 1 }; i < N - 1; i++)
//		for (int j{ 0 }; j < M - 1; j++) {
//			int temp1 = scorePaper[(i - 1) * M + j] + scorePaper[i * M + j] + scorePaper[(i + 1) * M + j] + scorePaper[i * M + j + 1];
//			int temp2 = scorePaper[(i - 1) * M + j + 1] + scorePaper[i * M + j + 1] + scorePaper[(i + 1) * M + j + 1] + scorePaper[i * M + j];
//			if (temp1 > max)
//				max = temp1;
//			if (temp2 > max)
//				max = temp2;
//		}
//
//	cout << max;
//
//	return 0;
//}

// 다른 방법(DFS)
int scorePaper[501][501];
bool visited[501][501];
int N, M, result;

// 왼쪽, 오른쪽, 위쪽, 아래쪽
int direction[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

// ㅗ, ㅏ, ㅜ, ㅓ
int dir_x[4][4] = { {0, 0, 0, -1}, {0, 1, 2, 1}, {0, 0, 0, 1}, {0, -1, 0, 1} };
int dir_y[4][4] = { {0, 1, 2, 1}, {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 1, 1, 1} };

// DFS로 'ㅜ' 모양 제외 4가지 모양 검사
void dfs(int x, int y, int total, int length) {
	// 길이가 4 이상일 때 종료
	if (length >= 4) {
		result = max(result, total);
		return;
	}

	for (int i{ 0 }; i < 4; i++) {
		int p_x = x + direction[i][0];
		int p_y = y + direction[i][1];

		// 종이를 넘어가는 경우 검사
		if (p_x < 1 || p_x > N || p_y < 1 || p_y > M)
			continue;

		// 방문하지 않은 칸일 때
		if (!visited[p_x][p_y]) {
			// 방문 표시
			visited[p_x][p_y] = true;

			dfs(p_x, p_y, total + scorePaper[p_x][p_y], length + 1);

			// 방문 표시 해제
			visited[p_x][p_y] = false;
		}
	}
}

// 'ㅜ' 모양 검사
void checkAnotherShape(int x, int y) {
	for (int i{ 0 }; i < 4; i++) {
		bool isValid = true;
		int total = 0;

		for (int j{ 0 }; j < 4; j++) {
			int p_x = x + dir_x[i][j];
			int p_y = y + dir_y[i][j];

			if (p_x < 1 || p_x > N || p_y < 1 || p_y > M) {
				isValid = false;
				break;
			}
			else
				total += scorePaper[p_x][p_y];
		}

		if (isValid)
			result = max(result, total);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i{ 1 }; i <= N; i++)
		for (int j{ 1 }; j <= M; j++)
			cin >> scorePaper[i][j];

	for (int i{ 1 }; i <= N; i++)
		for (int j{ 1 }; j <= M; j++) {
			// DFS로 4가지 모양 검사
			visited[i][j] = true;		// 방문 표시
			dfs(i, j, scorePaper[i][j], 1);
			visited[i][j] = false;		// 방문 표시 해제

			// 'ㅜ' 모양 검사
			checkAnotherShape(i, j);
		}

	cout << result;
}