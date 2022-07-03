// 11478번, 서로 다른 부분 문자열의 개수
#include <iostream>
using std::ios_base;
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <unordered_set>
using std::unordered_set;

int countSubstring(const string&);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	cin >> S;

	int difSubstring = countSubstring(S);

	cout << difSubstring;

	return 0;
}

int countSubstring(const string& str) {
	unordered_set<string> strList;

	for(int i=0;i<str.size();i++)
		for (int j = 1; i + j <= str.size(); j++)
			strList.emplace(str.substr(i, j));

	return strList.size();
}