// 1358��, ��Ű
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

#include <vector>
using std::vector;

#include <utility>
using std::pair;

int playerNum_in_link(int, int, int, int, const vector<pair<int, int>>&);

int main() {
	int W, H, X, Y, P;
	scanf("%d%d%d%d%d", &W, &H, &X, &Y, &P);

	vector<pair<int, int>> playerList(P);
	int x, y;
	for (int i = 0; i < P; i++) {
		scanf("%d%d", &x, &y);
		playerList[i] = { x,y };
	}

	printf("%d", playerNum_in_link(W, H, X, Y, playerList));

	return 0;
}

int playerNum_in_link(int in_W, int in_H, int in_X, int in_Y, const vector<pair<int, int>>& P_list) {
	int count = 0, x, y;
	for (int i = 0; i<int(P_list.size()); i++) {
		x = P_list[i].first;
		y = P_list[i].second;

		// ������ ��ġ�� ��ũ�� ���簢�� �κп� �ִ� ���
		if ((x >= in_X) && (x <= in_X + in_W))
			if ((y >= in_Y) && (y <= in_Y + in_H)) {
				count++;
				continue;
			}

		// ������ ��ġ�� ��ũ�� ���� �ݿ� �κп� �ִ� ���
		if (x < in_X)
			if (sqrt(pow(in_X - x, 2) + pow(y - (in_Y + in_H / 2), 2)) <= in_H / 2) {
				count++;
				continue;
			}

		// ������ ��ġ�� ��ũ�� ������ �ݿ� �κп� �ִ� ���
		if (x > (in_X + in_W))
			if (sqrt(pow(x - (in_X + in_W), 2) + pow(y - (in_Y + in_H / 2), 2)) <= (in_H / 2)) {
				count++;
				continue;
			}
	}

	return count;
}