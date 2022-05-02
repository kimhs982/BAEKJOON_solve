// 11650, 좌표 정렬하기(struct)
#include <iostream>
#include <algorithm>
using namespace std;

struct coordinate {
	int x;
	int y;
	coordinate(int in_x = 0, int in_y = 0) : x(in_x), y(in_y) {}
	bool operator<(const coordinate& temp) {		// 연산자(<) 오버로딩, 오름차순 정렬
		if (this->x != temp.x)
			return this->x < temp.x;
		else
			return this->y < temp.y;
	}
};

void print_coordinateSorting(coordinate*, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	coordinate* corList = new coordinate[N];

	int first, second;
	for (int i = 0; i < N; i++) {
		cin >> first >> second;
		corList[i] = { first, second };
	}

	print_coordinateSorting(corList, N);

	delete[] corList;
	return 0;
}

void print_coordinateSorting(coordinate* coordinateList, int in_N) {
	sort(coordinateList, coordinateList + in_N);

	for (int i = 0; i < in_N; i++)
		cout << coordinateList[i].x << ' ' << coordinateList[i].y << '\n';
}