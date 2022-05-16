// 2477��, ���ܹ�
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

#include <utility>
using std::pair;

#include <array>
using std::array;

int getOrientalMelon(const array<pair<int, int>, 6>&, int, int);

int main() {
	int K, direction, size, shape;
	scanf("%d", &K);
	int east = 0, west = 0, south = 0, north = 0;

	array<pair<int, int>, 6> field;
	for (int i = 0; i < 6; i++) {
		scanf("%d%d", &direction, &size);
		field[i] = { direction, size };
		// ��(1),��(2), ��(3), ��(4)
		switch (direction) {
		case 1:
			east++;
			break;
		case 2:
			west++;
			break;
		case 3:
			south++;
			break;
		case 4:
			north++;
			break;
		}
	}

	if (south == 2)
		if (east == 2)
			shape = 1;		// �����
		else
			shape = 4;		// �����
	else
		if (east == 2)
			shape = 2;		// �����
		else
			shape = 3;		// �����

	printf("%d", getOrientalMelon(field, K, shape));

	return 0;
}

int getLocation(const array<pair<int, int>, 6>& field, int shape) {
	int shape_num, location;
	switch (shape) {
	case 1:
		shape_num = 4;		// �����
		break;
	case 2:
		shape_num = 2;		// �����
		break;
	case 3:
		shape_num = 3;		// �����
		break;
	case 4:
		shape_num = 1;		// �����
		break;
	}

	for (int i = 0; i < 6; i++)
		if (field[i].first == shape_num)
			location = i;
	return location;
}

// ���ܹ��� ũ��(���� ū ���簢��)
int getBigFieldSize(const array<pair<int, int>, 6>& field, int shape) {
	int location = getLocation(field, shape);

	if (location + 1 < 6)
		return field[location].second * field[location + 1].second;
	else
		return field[location].second * field[location - 5].second;
}

//���ܹ��� ũ��(���� ���簢��)
int getSmallFieldSize(const array<pair<int, int>, 6>& field, int shape) {
	int location, width, length;
	location = getLocation(field, shape);

	if (location + 3 < 6)
		length = field[location + 3].second;
	else
		length = field[location - 3].second;

	if (location + 4 < 6)
		width = field[location + 4].second;
	else
		width = field[location - 2].second;

	return length * width;
}

// ���ܹ��� ���̿� �ش��ϴ� ���� ���� ���ϱ�
int getOrientalMelon(const array<pair<int, int>, 6>& field, int num_per_unit, int shape) {
	return(getBigFieldSize(field, shape) - getSmallFieldSize(field, shape)) * num_per_unit;
}