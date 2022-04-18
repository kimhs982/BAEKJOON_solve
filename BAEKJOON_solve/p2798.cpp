// 2798��, ����
#define _CRT_SECURE_NO_WARNINGS

#include <vector>
using namespace std;

#include <cstdio>

int blackjack1(const vector<int>&, int);
int blackjack2(const vector<int>&, int);

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<int> list(N);
	int input;
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		list[i] = input;
	}

	printf("%d\n", blackjack2(list, M));

	return 0;
}

int blackjack1(const vector<int>& num_list, int in_M) {
	vector<int> sum_list;

	int sum;
	// num_list vector�� ��� ���Ҹ� ��� Ȯ��, combination(����)
	for (unsigned i = 0; i < num_list.size() - 2; i++)
		for (unsigned j = i + 1; j < num_list.size() - 1; j++)
			for (unsigned k = j + 1; k < num_list.size(); k++) {
				sum = num_list[i] + num_list[j] + num_list[k];		// sum�� index i, j, k 3���� ������ ���� ����
				if (sum <= in_M)		// sum�� in_M���� �۰ų� ���� ���
					sum_list.emplace_back(sum);		// sum_list vector�� ����
			}

	int max_sum = num_list[0];
	for (unsigned i = 1; i < sum_list.size(); i++)
		if (sum_list[i] > max_sum)		// sum_list vector���� �ִ밪�� max_sum�� ����
			max_sum = sum_list[i];

	return max_sum;
}

int combination_count(int n, int r) {		// ����(combination) ���� ����, nCr
	if ((r == 0) || (n - r == 0))
		return 1;
	else if ((r == 1) || (n - r == 1))
		return n;
	else
		return combination_count(n - 1, r - 1) + combination_count(n - 1, r);
}

int blackjack2(const vector<int>& num_list, int in_M) {
	int sum_listSize = combination_count(int(num_list.size()), 3);
	int* sum_list = new int[sum_listSize]();		// ������ ����� ���� ���Ͽ� sum_list �迭�� �����Ҵ�

	int index = 0;
	for (unsigned i = 0; i < num_list.size() - 2; i++)
		for (unsigned j = i + 1; j < num_list.size() - 1; j++)
			for (unsigned k = j + 1; k < num_list.size(); k++)
				sum_list[index++] = num_list[i] + num_list[j] + num_list[k];		// // sum_list[]�� index i, j, k 3���� ������ ���� ��� ����

	int max_sum = 0, i;
	// ù ��° for �ݺ���, sum_list �迭���� in_M ���� ���� ���� ã�� max_sum�� ����, �ݺ��� ����(break)
	for (i = 0; i < sum_listSize; i++)
		if ((sum_list[i] <= in_M)) {
			max_sum = sum_list[i];
			break;
		}
	// i+1�� °���� sum_listSize-1������ �ִ밪 ���ϱ�
	for (int j = i + 1; j < sum_listSize; j++)
		if ((sum_list[j] <= in_M) && (sum_list[j] > max_sum))
			max_sum = sum_list[j];

	delete[] sum_list;		// �����Ҵ��� �޸� ���� ����
	return max_sum;
}