// 3034��, �ޱ׸� â��
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

void print_checkFitMatch(const vector<int>&, int, int);

int main() {
	int N, W, H;
	scanf("%d%d%d", &N, &W, &H);

	vector<int> matches(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &matches[i]);

	print_checkFitMatch(matches, W, H);

	return 0;
}

void print_checkFitMatch(const vector<int>& matchList, int width, int length) {
	double diagonal = sqrt(pow(width, 2) + pow(length, 2));

	for (int i = 0; i<int(matchList.size()); i++)
		// ����, ����, �밢�� ���� �߿� �밢�� ���̰� ���� ���, �밢�� ���̺��� ������ �ڽ��� �� �� ����
		if (matchList[i] <= diagonal)
			printf("DA\n");
		else
			printf("NE\n");
}