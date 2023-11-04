// 14503번, 로봇 청소기
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int robot_cleaner(vector<vector<int>>&, int, int, int);

vector<pair<int, int>> move_front{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int main() {
	int N, M, r, c, d;
	cin >> N >> M;
	vector<int> temp(M);
	vector<vector<int>> room(N, temp);
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> room[i][j];
	cout << robot_cleaner(room, r, c, d);
}

int robot_cleaner(vector<vector<int>>& room, int r, int c, int d) {
	int cleaned_room = 0;
	while (true) {
		// 1번
		if (room[r][c] == 0) {
			room[r][c] = -1;
			cleaned_room++;
		}

		// 2번
		if (room[r - 1][c] != 0 && room[r + 1][c] != 0 && room[r][c - 1] != 0 && room[r][c + 1] != 0) {
			if (room[r - move_front[d].first][c - move_front[d].second] != 1)
				r -= move_front[d].first, c -= move_front[d].second;
			else
				break;
		}
		// 3번
		else {
			if (--d < 0) d = 3;
			if (room[r + move_front[d].first][c + move_front[d].second] == 0)
				r += move_front[d].first, c += move_front[d].second;
		}
	}
	return cleaned_room;
}