// 3090번, 네 번째 점
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	int in_x, in_y, res_x, res_y;
	int x[2], y[2];
	int count_x[2] = { 0 }, count_y[2] = { 0 };
	int index_x = 0, index_y = 0;
	bool full_x = false, full_y = false;


	scanf("%d%d", &in_x, &in_y);
	x[index_x] = in_x, y[index_y] = in_y;
	index_x++, index_y++;
	count_x[0]++, count_y[0]++;
	for (int i = 0; i < 2; i++) {
		scanf("%d%d", &in_x, &in_y);
		if ((in_x != x[0]) && (!full_x)) {
			x[index_x] = in_x;
			count_x[1]++;
			full_x = true;
		}
		else if (in_x != x[0])
			count_x[1]++;
		else
			count_x[0]++;

		if ((in_y != y[0]) && (!full_y)) {
			y[index_y] = in_y;
			count_y[1]++;
			full_y = true;
		}
		else if (in_y != y[0])
			count_y[1]++;
		else
			count_y[0]++;
	}

	if (count_x[0] == 1)
		res_x = x[0];
	else
		res_x = x[1];

	if (count_y[0] == 1)
		res_y = y[0];
	else
		res_y = y[1];

	printf("%d %d\n", res_x, res_y);

	return 0;
}