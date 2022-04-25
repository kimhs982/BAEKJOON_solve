// 1436번, 영화감독 숌
// 큰 종말의 숫자를 제대로 구하지 못함, "틀렸습니다"
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

#include <vector>
using namespace std;

vector<int> getEndNum(int);

int main() {
	int N;
	vector<int> end;
	scanf("%d", &N);

	end = getEndNum(N);

	for (int i = 0; i<int(end.size()); i++)
		printf("%d", end[i]);
	printf("\n");

	return 0;
}

vector<int> getEndNum(int in_N) {
	vector<int> endNum;

	// 10의 자리 이상부터만 저장
	int digit = 0, i = 1, j = 0;
	bool addFront = true;
	while (i <= in_N) {
			if (digit > 0)
				j = -1;
			for (; (j < 5) && (i < in_N); j++)
				i++;
			if (i == in_N)
				break;

			if (digit % 10 != 6)
				for (j = -1; (j < 99) && (i < in_N); j++)
					i++;
			else
				for (j = -1; (j < 9) && (i < in_N); j++)
					i++;
			if (i == in_N) {
				addFront = false;
				break;
			}

			for (j = 6; (j < 9) && (i < in_N); j++)
				i++;
			if (i == in_N)
				break;
			digit++;
	}

	if (digit > 0)
		endNum.emplace_back(digit);
	if (addFront) {
		if (in_N != 1)
			endNum.emplace_back(j);
		for (int k = 0; k < 3; k++)
			endNum.emplace_back(6);
	}
	else {
		if (digit % 10 == 6) {
			for (int k = 0; k < 2; k++)
				endNum.emplace_back(6);
			if (j < 10) {
				endNum.emplace_back(0);
				endNum.emplace_back(j);
			}
			else
				endNum.emplace_back(j);
		}
		else {
			for (int k = 0; k < 3; k++)
				endNum.emplace_back(6);
			endNum.emplace_back(j);
		}
	}

	return endNum;
}