// 1002��, �ͷ�
#define _CRT_SECURE_NO_WARNINGS

#include <vector>
using namespace std;

#include <cstdio>
#include <cmath>


int possibleCoordinateNum(vector<int>&);

int main() {
	int T;
	vector<int> coordinate_list(6);
	scanf("%d", &T);

	int num_count;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 6; j++)
			scanf("%d", &coordinate_list[j]);
		num_count = possibleCoordinateNum(coordinate_list);
		printf("%d\n", num_count);
	}

	return 0;
}

double distance(int x1, int y1, int x2, int y2) {
	double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	return d;
}

int possibleCoordinateNum(vector<int>& coordinates) {
	int x1, y1, r1, x2, y2, r2;
	double d;

	x1 = coordinates[0], y1 = coordinates[1], r1 = coordinates[2];
	x2 = coordinates[3], y2 = coordinates[4], r2 = coordinates[5];
	d = distance(x1, y1, x2, y2);

	// �� ���� �߽��� ��ġ
	if ((x1 == x2) && (y1 == y2))
		if (r1 == r2)		// �������� ���� ���
			return -1;
		else
			return 0;

	// �� ���� ������ �� �� ū �������� biggerRadius, ���� �������� smallerRadius�� ����
	int biggerRadius, smallerRadius;
	if (r1 > r2) {
		biggerRadius = r1;
		smallerRadius = r2;
	}
	else {
		biggerRadius = r2;
		smallerRadius = r1;
	}

	// ������ ���� �߽��� �� �ܺο� �ִ� ���
	if (d > biggerRadius) {
		int sum_radius = r1 + r2;
		if (sum_radius > d)
			return 2;
		else if (sum_radius == d)
			return 1;
		else
			return 0;
	}
	// ������ ���� �߽��� �� ���ο� �ִ� ���
	else {
		int sub_radius = biggerRadius - smallerRadius;
		if (sub_radius < d)
			return 2;
		else if (sub_radius == d)
			return 1;
		else
			return 0;
	}
}