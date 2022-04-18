// 2798번, 블랙잭
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
	// num_list vector의 모든 원소를 모두 확인, combination(조합)
	for (unsigned i = 0; i < num_list.size() - 2; i++)
		for (unsigned j = i + 1; j < num_list.size() - 1; j++)
			for (unsigned k = j + 1; k < num_list.size(); k++) {
				sum = num_list[i] + num_list[j] + num_list[k];		// sum에 index i, j, k 3개의 원소의 합을 저장
				if (sum <= in_M)		// sum이 in_M보다 작거나 같은 경우
					sum_list.emplace_back(sum);		// sum_list vector에 저장
			}

	int max_sum = num_list[0];
	for (unsigned i = 1; i < sum_list.size(); i++)
		if (sum_list[i] > max_sum)		// sum_list vector에서 최대값을 max_sum에 저장
			max_sum = sum_list[i];

	return max_sum;
}

int combination_count(int n, int r) {		// 조합(combination) 개수 구함, nCr
	if ((r == 0) || (n - r == 0))
		return 1;
	else if ((r == 1) || (n - r == 1))
		return n;
	else
		return combination_count(n - 1, r - 1) + combination_count(n - 1, r);
}

int blackjack2(const vector<int>& num_list, int in_M) {
	int sum_listSize = combination_count(int(num_list.size()), 3);
	int* sum_list = new int[sum_listSize]();		// 조합의 경우의 수를 구하여 sum_list 배열을 동적할당

	int index = 0;
	for (unsigned i = 0; i < num_list.size() - 2; i++)
		for (unsigned j = i + 1; j < num_list.size() - 1; j++)
			for (unsigned k = j + 1; k < num_list.size(); k++)
				sum_list[index++] = num_list[i] + num_list[j] + num_list[k];		// // sum_list[]에 index i, j, k 3개의 원소의 합을 모두 저장

	int max_sum = 0, i;
	// 첫 번째 for 반복문, sum_list 배열에서 in_M 보다 작은 값을 찾아 max_sum에 저장, 반복문 종료(break)
	for (i = 0; i < sum_listSize; i++)
		if ((sum_list[i] <= in_M)) {
			max_sum = sum_list[i];
			break;
		}
	// i+1번 째부터 sum_listSize-1까지의 최대값 구하기
	for (int j = i + 1; j < sum_listSize; j++)
		if ((sum_list[j] <= in_M) && (sum_list[j] > max_sum))
			max_sum = sum_list[j];

	delete[] sum_list;		// 동적할당한 메모리 공간 해제
	return max_sum;
}