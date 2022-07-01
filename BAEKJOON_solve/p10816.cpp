// 10816번, 숫자 카드 2
#include <iostream>
using std::ios_base;
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;
using std::upper_bound;
using std::lower_bound;

int find_numCard(const vector<int>&, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, in_num;
	cin >> N;

	vector<int> card;
	card.reserve(N);
	for (int i = 0; i < N; i++) {
		cin >> in_num;
		card.emplace_back(in_num);
	}
	// <algorithm>의 sort() 함수
	sort(card.begin(), card.end());

	cin >> M;
	vector<int> count_card;
	count_card.reserve(M);
	for (int i = 0; i < M; i++) {
		cin >> in_num;
		count_card.emplace_back(find_numCard(card, in_num));
	}

	for (int i = 0; i < M; i++)
		cout << count_card[i] << ' ';

	return 0;
}

// <algorithm>의 lower_bound(), upper_bount() 함수
int find_numCard(const vector<int>& cardList, int val) {
	return upper_bound(cardList.begin(), cardList.end(), val) - lower_bound(cardList.begin(), cardList.end(), val);
}