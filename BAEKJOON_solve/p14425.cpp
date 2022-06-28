// 14425번, 문자열 집합
#include <iostream>
using std::ios_base;
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <set>
using std::set;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	// 문자열 집합 S에 문자열 삽입
	set<string> S;
	for (int i = 0; i < N; i++) {
		string str_insert;
		cin >> str_insert;
		S.emplace(str_insert);
	}

	// 문자열 집합 S에서 문자열 포함 여부 확인
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		string str_search;
		cin >> str_search;
		set<string>::iterator pos = S.find(str_search);
		if (pos != S.end())
			cnt++;
	}
	cout << cnt << '\n';

	return 0;
}