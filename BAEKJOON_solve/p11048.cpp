// 11048��, �̵��ϱ�(DP)
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

	// 2���� �迭 �����Ҵ�
	int** maze = new int* [N];
	for (int i = 0; i < N; i++)
		*(maze + i) = new int[M]();

	// �̷��� �� (N, M)�� �����ִ� ������ ����
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> maze[i][j];

	// �̷��� ���� (1, 1 ~ M)�� ���
	for (int i = 1; i < M; i++)
		maze[0][i] += maze[0][i - 1];

	// �̷��� ���� (1 ~ N, 1)�� ���
	for (int i = 1; i < N; i++)
		maze[i][0] += maze[i - 1][0];

	// �� �̿��� ���, �̷��� ���� (2 ~ N, 2 ~ M)�� ���
	for (int i = 1; i < N; i++)
		for (int j = 1; j < M; j++)
			maze[i][j] = max(max(maze[i - 1][j], maze[i - 1][j - 1]), maze[i][j - 1]) + maze[i][j];

	cout << maze[N - 1][M - 1];		// �̷��� ���� (N, M)�� ��� �ִ�

	// �����Ҵ� �޸� ���� ����
	for (int i = 0; i < N; i++)
		delete[] * (maze + i);
	delete[] maze;

	return 0;
}