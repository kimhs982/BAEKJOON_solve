// 7568번, 등치
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

#include <vector>
using namespace std;

struct Size {
	int weight;
	int height;
	Size(int w = 0, int h = 0) :weight(w), height(h) {}
};

void printBuildRanking(const Size* const, int);

int main() {
	int N;
	scanf("%d", &N);
	Size* size_list = new Size[N];

	for (int i = 0; i < N; i++)
		scanf("%d%d", &size_list[i].weight, &size_list[i].height);

	printBuildRanking(size_list, N);

	delete[] size_list;
	return 0;
}

// 처음으로 몸무게를 비교하여 자신보다 몸무게가 더 큰 부분의 index를 vector에 저장하고, 그 index에 해당하는 키가 자신의 키보다 더 큰지 확인하여 등수를 결정
void printBuildRanking(const Size* const list, int in_N) {
	vector<int> index_list;
	vector<int> count_list(in_N, 1);

	for (int i = 0; i < in_N; i++) {
		int weight = list[i].weight;
		int height = list[i].height;

		// 자신보다 몸무게가 더 큰 경우, 해당하는 index를 index_list에 저장
		for (int j = 0; j < in_N; j++)
			if (weight < list[j].weight)
				index_list.emplace_back(j);

		// index_list에 저장되어 있는 index 값에서만 키를 비교
		for (int j : index_list)
			if (height < list[j].height)
				count_list[i]++;

		// index_list를 초기화(size = 0, capacity != 0)
		index_list.clear();
	}

	for (int i : count_list)
		printf("%d ", i);
}