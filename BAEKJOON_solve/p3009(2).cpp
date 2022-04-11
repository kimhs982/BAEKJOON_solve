// 3009번, 네 번째 점
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <cstdio>
using namespace std;

void get_fourPoint(int&, int&);
int search_count(vector<int>&, int);

int main() {
	int x, y;

	get_fourPoint(x, y);
	printf("%d %d\n", x, y);

	return 0;
}

void get_fourPoint(int& x, int& y) {
	int in_x, in_y;
	vector<int> point_arrX(3);
	vector<int> point_arrY(3);

	for (int i = 0; i < 3; i++) {
		scanf("%d%d", &in_x, &in_y);
		point_arrX[i] = in_x;
		point_arrY[i] = in_y;
	}

	for (int i = 0; i < 3; i++)
		if (search_count(point_arrX, point_arrX[i]) == 1) {
			x = point_arrX[i];
			break;
		}

	for (int i = 0; i < 3; i++)
		if (search_count(point_arrY, point_arrY[i]) == 1) {
			y = point_arrY[i];
			break;
		}
}

int search_count(vector<int>& arr, int key) {
	int count = 0;

	for (unsigned int i = 0; i < arr.size(); i++)
		if (arr[i] == key)
			count++;

	return count;
}