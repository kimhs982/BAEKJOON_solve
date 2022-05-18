// 1004��, � ����
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

#include <vector>
using std::vector;

#include <utility>
using std::pair;

// ����ü, (x, y) ��ǥ�� ������ r�� ����
struct planet {
	int x, y;
	int r;
	planet(int in_x = 0, int in_y = 0, int in_r = 0) : x(in_x), y(in_y), r(in_r) {}
};

int countPlanet(const vector<planet>&, const pair<int, int>&, const pair<int, int>&);

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		pair<int, int> start, end;
		int x, y;
		scanf("%d%d", &x, &y);
		start = { x,y };
		scanf("%d%d", &x, &y);
		end = { x,y };

		int n;
		scanf("%d", &n);
		vector<planet> planetSystem(n);

		int r;
		for (int j = 0; j < n; j++) {
			scanf("%d%d%d", &x, &y, &r);
			planetSystem[j].x = x;
			planetSystem[j].y = y;
			planetSystem[j].r = r;
		}

		printf("%d\n", countPlanet(planetSystem, start, end));
		
		planetSystem.clear();
	}

	return 0;
}

// �ּ��� �༺�� ����/��Ż Ƚ��, ���� �߽ɿ��� ������� �������� ���� ���ο� �ִ��� Ȯ��
int countPlanet(const vector<planet>& planetSystem, const pair<int, int>& start, const pair<int, int>& end) {
	int count = 0;
	double start_dis, end_dis;
	for (int i = 0; i < planetSystem.size(); i++) {
		// ��������� ���� �߽ɱ����� �Ÿ�
		start_dis = sqrt(pow(planetSystem[i].x - start.first, 2) + pow(planetSystem[i].y - start.second, 2));
		// ���������� ���� �߽ɱ����� �Ÿ�
		end_dis = sqrt(pow(planetSystem[i].x - end.first, 2) + pow(planetSystem[i].y - end.second, 2));
		if ((start_dis < planetSystem[i].r) && (end_dis < planetSystem[i].r))		// ������� �������� ��� �� ���ο� �ִ� ���
			continue;
		else if ((start_dis > planetSystem[i].r) && (end_dis > planetSystem[i].r))		// ������� �������� ��� �� �ܺο� �ִ� ���
			continue;
		count++;
	}

	return count;
}