// 1764¹ø, µèº¸Àâ
#include <iostream>
using std::ios_base;
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;

#include <algorithm>
using std::sort;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	string name;
	unordered_set<string> notHeardPeople;
	for (int i = 0; i < N; i++) {
		cin >> name;
		notHeardPeople.emplace(name);
	}

	vector<string> notHeardSeenPeople;
	for (int i = 0; i < M; i++) {
		cin >> name;
		if (notHeardPeople.find(name) != notHeardPeople.end())
			notHeardSeenPeople.emplace_back(name);
	}
	sort(notHeardSeenPeople.begin(), notHeardSeenPeople.end());

	cout << notHeardSeenPeople.size() << '\n';
	for (int i = 0; i < notHeardSeenPeople.size(); i++)
		cout << notHeardSeenPeople[i] << '\n';

	return 0;
}