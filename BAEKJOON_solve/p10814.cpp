// 10814번, 나이순 정렬
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <string>
using std::string;

#include <algorithm>
using std::stable_sort;

#include <utility>
using std::pair;

struct Member {
	int age;
	string name;
};

bool operator<(const Member& com1, const Member& com2) {
	return com1.age < com2.age;
}

bool cmp(const pair<int, string>& com1, const pair<int, string>& com2) {
	return com1.first < com2.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	/*Member* memberList = new Member[N];
	for (int i = 0; i < N; i++)
		cin >> memberList[i].age >> memberList[i].name;

	stable_sort(memberList, memberList + N);

	for (int i = 0; i < N; i++)
		cout << memberList[i].age << ' ' << memberList[i].name << '\n';*/

	pair<int, string>* memberList = new pair<int, string>[N];
	int age;
	string name;
	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		memberList[i] = { age, name };
	}

	stable_sort(memberList, memberList + N, cmp);

	for (int i = 0; i < N; i++)
		cout << memberList[i].first << ' ' << memberList[i].second << '\n';

	delete[] memberList;
	return 0;
}