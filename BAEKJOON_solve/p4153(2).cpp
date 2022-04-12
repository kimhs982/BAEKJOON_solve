// 4153번, 직각삼각형
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
using namespace std;

#include <cstdio>
#include <cmath>

void is_rightTriangle(vector<int>);

int main() {
	vector<int> in_side(3);
	int input;

	while (1) {
		for (int i = 0; i < 3; i++) {
			scanf("%d", &input);
			in_side[i] = input;
		}

		if ((in_side[0] == 0) && (in_side[1] == 0) && (in_side[2] == 0))
			break;

		is_rightTriangle(in_side);
	}

	return 0;
}

void is_rightTriangle(vector<int> side) {
	int hypotenuse = side[0], hypotenuse_index = 0;

	for (int i = 1; i < 3; i++)
		if (hypotenuse < side[i]) {
			hypotenuse = side[i];
			hypotenuse_index = i;
		}
	side.erase(side.begin() + hypotenuse_index);

	int temp = 0;
	for (int i = 0; i < 2; i++)
		temp += pow(side[i], 2);

	if (pow(hypotenuse, 2) == temp)
		printf("right\n");
	else
		printf("wrong\n");
}