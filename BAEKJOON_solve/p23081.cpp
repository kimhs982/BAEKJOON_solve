// 23081번, 오델로-실패
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <vector>
using std::vector;

#include <utility>
using std::pair;
using std::make_pair;

#include <algorithm>
using std::min;
using std::max;

void playOthello_print(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	playOthello_print(N);

	return 0;
}

void playOthello_print(int in_N) {
	char** othello = new char* [in_N];
	for (int i = 0; i < in_N; i++)
		othello[i] = new char[in_N + 1];

	vector<pair<int, int>> blank_cor;
	blank_cor.reserve(in_N);
	for (int i = 0; i < in_N; i++)
		for (int j = 0; j < in_N; j++) {
			cin >> othello[i][j];
			if (othello[i][j] == '.')
				blank_cor.emplace_back(make_pair(j, i));
		}

	int max_white = 0;
	pair<int, int> max_coordinate;
	for (pair<int, int> i : blank_cor) {
		int cnt_white = 0, temp1 = 0, temp2 = 0, j;
		char state;
		// 수평방향
		for (j = i.first - 1; j >= 0; j--) {
			state = othello[i.second][j];
			if (state == '.') {
				temp1 = 0;
				break;
			}
			if (state == 'W')
				temp1++;
			if (state == 'B')
				break;
		}
		if (j == -1)
			temp1 = 0;

		for (j = i.first + 1; j < in_N; j++) {
			state = othello[i.second][j];
			if (state == '.') {
				temp2 = 0;
				break;
			}
			if (state == 'W')
				temp2++;
			if (state == 'B')
				break;
		}
		if (j == in_N)
			temp2 = 0;

		cnt_white += (temp1 + temp2);
		temp1 = temp2 = 0;

		// 수직방향
		for (j = i.second - 1; j >= 0; j--) {
			state = othello[j][i.first];
			if (state == '.') {
				temp1 = 0;
				break;
			}
			if (state == 'W')
				temp1++;
			if (state == 'B')
				break;
		}
		if (j == -1)
			temp1 = 0;

		for (j = i.second + 1; j < in_N; j++) {
			state = othello[j][i.first];
			if (state == '.') {
				temp2 = 0;
				break;
			}
			if (state == 'W')
				temp2++;
			if (state == 'B')
				break;
		}
		if (j == in_N)
			temp2 = 0;
		
		cnt_white += (temp1 + temp2);
		temp1 = temp2 = 0;

		// 대각선방향
		int min_cor = min(i.first, i.second);
		for (j = 1; j <= min_cor; j++) {
			state = othello[i.second - j][i.first - j];
			if (state == '.') {
				temp1 = 0;
				break;
			}
			if (state == 'W')
				temp1++;
			if (state == 'B')
				break;
		}
		if (j == min_cor + 1)
			temp1 = 0;

		int max_cor = max(i.first, i.second);
		for (j = 1; j < in_N - max_cor; j++) {
			state = othello[i.second + j][i.first + j];
			if (state == '.') {
				temp2 = 0;
				break;
			}
			if (state == 'W')
				temp2++;
			if (state == 'B')
				break;
		}
		if (j == in_N)
			temp2 = 0;

		cnt_white += (temp1 + temp2);

		if (max_white < cnt_white) {
			max_white = cnt_white;
			max_coordinate = i;
		}
	}

	if (max_white != 0) {
		cout << max_coordinate.first << ' ' << max_coordinate.second << '\n';
		cout << max_white << '\n';
	}
	else
		cout << "PASS\n";

	for (int i = 0; i < in_N; i++)
		delete[] othello[i];
	delete[] othello;
}