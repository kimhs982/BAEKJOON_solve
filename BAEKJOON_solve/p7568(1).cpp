// 7568��, ��ġ
// Ʋ�� ������ �𸣰��� -> �����԰� ������ ��� Ű�� ������� ��ġ�� �Ǵ��� �� ���ٴ� ���� �߰�
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

// ������, Ű�� ������ Size ����ü
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

// �����Ը� �������� �������� ������ ��
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

// index�� �������� �������� ������ ��
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

// �����Ը� �������� �������� ������ �ϰ� Ű�� ���Ͽ� ��ġ ����� ����
void print_buildRankingList(Size* list, int in_N) {
	// �����Ը� �������� �������� ����
	insertionSort_weight(list, in_N);

	for (int i = 0; i < in_N - 1; i++) {
		int height = list[i].height;
		int weight = list[i].weight;
		for (int j = i + 1; j < in_N; j++)
			if ((weight != list[j].weight) && (height < list[j].height))		// �����԰� ������ ��� ��ġ�� �Ǵ��� �� ����!
				list[i].count++;
	}

	// index�� �������� �������� ����
	insertionSort_index(list, in_N);

	for (int i = 0; i < in_N; i++)
		printf("%d ", list[i].count);
}