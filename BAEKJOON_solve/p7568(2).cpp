// 7568��, ��ġ
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

// ó������ �����Ը� ���Ͽ� �ڽź��� �����԰� �� ū �κ��� index�� vector�� �����ϰ�, �� index�� �ش��ϴ� Ű�� �ڽ��� Ű���� �� ū�� Ȯ���Ͽ� ����� ����
void printBuildRanking(const Size* const list, int in_N) {
	vector<int> index_list;
	vector<int> count_list(in_N, 1);

	for (int i = 0; i < in_N; i++) {
		int weight = list[i].weight;
		int height = list[i].height;

		// �ڽź��� �����԰� �� ū ���, �ش��ϴ� index�� index_list�� ����
		for (int j = 0; j < in_N; j++)
			if (weight < list[j].weight)
				index_list.emplace_back(j);

		// index_list�� ����Ǿ� �ִ� index �������� Ű�� ��
		for (int j : index_list)
			if (height < list[j].height)
				count_list[i]++;

		// index_list�� �ʱ�ȭ(size = 0, capacity != 0)
		index_list.clear();
	}

	for (int i : count_list)
		printf("%d ", i);
}