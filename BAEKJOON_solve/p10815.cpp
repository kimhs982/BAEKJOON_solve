// 10815번, 숫자 카드
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

#include <algorithm>
using std::sort;
using std::binary_search;

#include <algorithm>
using std::sort;

template <typename elem>
elem binarySearch_location(const elem*, int, int, elem);

int main() {
	int N, M;

	scanf("%d", &N);
	int* cardList = new int[N];
	for (int i = 0; i < N; i++)
		scanf("%d", cardList + i);

	scanf("%d", &M);
	int* searchList = new int[M];
	for (int i = 0; i < M; i++)
		scanf("%d", searchList + i);

	sort(cardList, cardList + N);
	for (int i = 0; i < M; i++)
		printf("%d ", binary_search(cardList, cardList + N, searchList[i]));
		//printf("%d ", binarySearch_location<int>(cardList, 0, N - 1, searchList[i]));


	delete[] cardList;
	delete[] searchList;
	return 0;
}

// key의 index를 검색하는 binary search, 오름차순 정렬 필수
template <typename elem>
elem binarySearch_location(const elem* S, int low, int high, elem key) {
	int mid;

	if (low > high)
		return -1;
	else {
		mid = (low + high) / 2;
		if (key == S[mid])
			return mid;
		else if (key < S[mid])
			return binarySearch_location(S, low, mid - 1, key);
		else
			return binarySearch_location(S, mid + 1, high, key);
	}
}