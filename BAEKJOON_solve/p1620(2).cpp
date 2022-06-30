// 1620번, 나는야 포켓몬 마스터 이다솜, 시간초과
#include <iostream>
using std::ios_base;
using std::cin;
using std::cout;

#include <unordered_map>
using std::unordered_map;

#include <string>
using std::string;

#include <cctype>
#include <cmath>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<string, int> pocketmonGuide;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string in_str;
		cin >> in_str;
		pocketmonGuide.emplace(in_str, i + 1);
	}

	for (int i = 0; i < M; i++) {
		string guess_str;
		cin >> guess_str;
		if (isdigit(guess_str[0]) == 0)
			cout << pocketmonGuide[guess_str] << '\n';
			//cout << pocketmonGuide.at(guess_str) << '\n';
			//cout << pocketmonGuide.find(guess_str) << '\n';
		else {
			int guess_num = 0;
			for (int j = guess_str.size() - 1; j >= 0; j--)
				guess_num += (guess_str[j] - 48) * int(pow(10, guess_str.size() - (j + 1)));
			for (auto j = pocketmonGuide.begin(); j != pocketmonGuide.end(); j++)
				if (j->second == guess_num)
					cout << j->first << '\n';
		}
	}

	return 0;
}