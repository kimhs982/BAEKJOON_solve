// 11048번, 이동하기(DP)
#include <iostream>
using std::ios_base;
using std::cin;
using std::cout;

#include <algorithm>
using std::max;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	// 2차원 배열 동적할당
	int** maze = new int* [N];
	for (int i = 0; i < N; i++)
		*(maze + i) = new int[M]();

	// 미로의 방 (N, M)에 놓여있는 사탕의 개수
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> maze[i][j];

	// 미로의 방이 (1, 1 ~ M)인 경우
	for (int i = 1; i < M; i++)
		maze[0][i] += maze[0][i - 1];

	// 미로의 방이 (1 ~ N, 1)인 경우
	for (int i = 1; i < N; i++)
		maze[i][0] += maze[i - 1][0];

	// 그 이외의 경우, 미로의 방이 (2 ~ N, 2 ~ M)인 경우
	for (int i = 1; i < N; i++)
		for (int j = 1; j < M; j++)
			maze[i][j] = max(max(maze[i - 1][j], maze[i - 1][j - 1]), maze[i][j - 1]) + maze[i][j];

	cout << maze[N - 1][M - 1];		// 미로의 방이 (N, M)인 경우 최댓값

	// 동적할당 메모리 공간 해제
	for (int i = 0; i < N; i++)
		delete[] * (maze + i);
	delete[] maze;

	return 0;
}