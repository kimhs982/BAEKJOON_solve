// 10814번, 나이순 정렬 -> 시간초과
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <string>
using std::string;

#include <utility>
using std::pair;

void sortAge(pair<int, string>*, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	pair<int, string>* memberList = new pair<int, string>[N];
	int age;
	string name;
	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		memberList[i] = { age, name };
	}

	sortAge(memberList, N);

	for (int i = 0; i < N; i++)
		cout << memberList[i].first << ' ' << memberList[i].second << '\n';

	delete[] memberList;
	return 0;
}

void sortAge(pair<int, string>* list, int in_N) {
	for (int i = 1; i < in_N; i++) {
		pair<int, string> key = list[i];
		int j = i - 1;
		while ((j >= 0) && (key.first < list[j].first)) {
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = key;
	}
}