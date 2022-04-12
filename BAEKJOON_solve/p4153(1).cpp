// 4153번, 직각삼각형
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cmath>

void is_rightTriangle(int, int, int);

int main() {
	int in_a, in_b, in_c;

	while (1) {
		scanf("%d%d%d", &in_a, &in_b, &in_c);
		if ((in_a == 0) && (in_b == 0) && (in_c == 0))
			break;
		is_rightTriangle(in_a, in_b, in_c);
	}

	return 0;
}

void is_rightTriangle(int a, int b, int c) {
	if (c < a)
		std::swap(c, a);
	if (c < b)
		std::swap(c, b);

	if (pow(c, 2) == pow(a, 2) + pow(b, 2))
		printf("right\n");
	else
		printf("wrong\n");
}