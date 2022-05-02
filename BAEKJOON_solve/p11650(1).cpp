// 11650번, 좌표 정렬하기(pair)
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <utility>
using std::pair;

#include <algorithm>
using std::sort;

void print_coordinatesorting(pair<int, int>*, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	pair<int, int>* cor_pair = new pair<int, int>[N];
	int first, second;
	for (int i = 0; i < N; i++) {
		cin >> first >> second;
		cor_pair[i] = { first,second };
	}

	print_coordinatesorting(cor_pair, N);

	delete[] cor_pair;
	return 0;
}

void print_coordinatesorting(pair<int, int>* cor_arr, int in_N) {
	sort(cor_arr, cor_arr + in_N);

	for (int i = 0; i < in_N; i++)
		cout << cor_arr[i].first << ' ' << cor_arr[i].second << '\n';
}