// 1004번, 어린 왕자
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

#include <vector>
using std::vector;

#include <utility>
using std::pair;

// 구조체, (x, y) 좌표와 반지름 r을 저장
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

// 최소의 행성계 진입/이탈 횟수, 원의 중심에서 출발점과 도착점이 원의 내부에 있는지 확인
int countPlanet(const vector<planet>& planetSystem, const pair<int, int>& start, const pair<int, int>& end) {
	int count = 0;
	double start_dis, end_dis;
	for (int i = 0; i < planetSystem.size(); i++) {
		// 출발점에서 원의 중심까지의 거리
		start_dis = sqrt(pow(planetSystem[i].x - start.first, 2) + pow(planetSystem[i].y - start.second, 2));
		// 도착점에서 원의 중심까지의 거리
		end_dis = sqrt(pow(planetSystem[i].x - end.first, 2) + pow(planetSystem[i].y - end.second, 2));
		if ((start_dis < planetSystem[i].r) && (end_dis < planetSystem[i].r))		// 출발점과 도착점이 모두 원 내부에 있는 경우
			continue;
		else if ((start_dis > planetSystem[i].r) && (end_dis > planetSystem[i].r))		// 출발점과 도착점이 모두 원 외부에 있는 경우
			continue;
		count++;
	}

	return count;
}