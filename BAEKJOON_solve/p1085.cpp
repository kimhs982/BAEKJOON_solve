// 1085번, 직사각형에서 탈출
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int shortDistance(int, int, int, int);

int main() {
	int x, y, w, h, min_distance;
	scanf("%d%d%d%d", &x, &y, &w, &h);

	min_distance = shortDistance(x, y, w, h);
	printf("%d\n", min_distance);

	return 0;
}

int shortDistance(int in_x, int in_y, int in_w, int in_h) {
	int min_x, min_y;

	if (in_x < in_w - in_x)
		min_x = in_x;
	else
		min_x = in_w - in_x;

	if (in_y < in_h - in_y)
		min_y = in_y;
	else
		min_y = in_h - in_y;

	if (min_x < min_y)
		return min_x;
	else
		return min_y;
}