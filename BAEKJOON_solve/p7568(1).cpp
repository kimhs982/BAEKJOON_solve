// 7568번, 덩치
// 틀린 이유를 모르겠음 -> 몸무게가 동일한 경우 키에 상관없이 덩치를 판단할 수 없다는 것을 추가
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

// 몸무게, 키를 저장할 Size 구조체
struct Size
{
	int weight;
	int height;
	int index;
	int count;
	Size(int w = 0, int h = 0, int i = 0) : weight(w), height(h), index(i) {
		count = 1;
	}
};

void print_buildRankingList(Size*, int);

int main() {
	int N;
	scanf("%d", &N);
	Size* size_list = new Size[N];

	for (int i = 0; i < N; i++) {
		scanf("%d%d", &size_list[i].weight, &size_list[i].height);
		size_list[i].index = i;
	}

	print_buildRankingList(size_list, N);

	delete[] size_list;
	return 0;
}

// 몸무게를 기준으로 오름차순 정렬을 함
void insertionSort_weight(Size* list, int in_N) {
	for (int i = 1; i < in_N; i++) {
		Size key = list[i];
		int j = i - 1;
		while ((j >= 0) && (list[j].weight > key.weight)) {
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = key;
	}
}

// index를 기준으로 오름차순 정렬을 함
void insertionSort_index(Size* list, int in_N) {
	for (int i = 1; i < in_N; i++) {
		Size key = list[i];
		int j = i - 1;
		while ((j >= 0) && (list[j].index > key.index)) {
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = key;
	}
}

// 몸무게를 기준으로 오름차순 정렬을 하고 키를 비교하여 덩치 등수를 정함
void print_buildRankingList(Size* list, int in_N) {
	// 몸무게를 기준으로 오름차순 정렬
	insertionSort_weight(list, in_N);

	for (int i = 0; i < in_N - 1; i++) {
		int height = list[i].height;
		int weight = list[i].weight;
		for (int j = i + 1; j < in_N; j++)
			if ((weight != list[j].weight) && (height < list[j].height))		// 몸무게가 동일한 경우 덩치를 판단할 수 없음!
				list[i].count++;
	}

	// index를 기준으로 오름차순 정렬
	insertionSort_index(list, in_N);

	for (int i = 0; i < in_N; i++)
		printf("%d ", list[i].count);
}