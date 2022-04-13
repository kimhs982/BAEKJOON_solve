// 3053번, 택시 기하학
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>

double Euclid_circle(int);
double Taxicab_circle(int);

int main() {
	int R;
	double E_circle, T_circle;

	scanf("%d", &R);

	E_circle = Euclid_circle(R);
	T_circle = Taxicab_circle(R);

	printf("%.6lf\n%.6lf\n", E_circle, T_circle);

	return 0;
}

double Euclid_circle(int in_R) {		// 유클리드 기하학에서의 원의 넓이
	double c_area = pow(in_R, 2) * M_PI;

	return c_area;
}

double Taxicab_circle(int in_R) {		// 택시 기하학에서의 원의 넓이
	double c_area = pow(in_R, 2) * 2;

	return c_area;
}