// 1620번, 나는야 포켓몬 마스터 이다솜
#include <iostream>
using std::ios_base;
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <functional>
using std::hash;

#include <cctype>
#include <cmath>

class pocketmonGuide
{
public:
	pocketmonGuide(int size) : listSize(size)
	{
		pocketmonNameList.reserve(listSize);
		pocketmonHashList.reserve(listSize);
	}
	void insert(const string& name)
	{
		pocketmonNameList.emplace_back(name);
		pocketmonHashList.emplace_back(str_hash(name));
	}
	int find(const string& name)
	{
		size_t temp = str_hash(name);
		for (int i = 0; i < listSize; i++)
			if (pocketmonHashList[i] == temp)
				return i + 1;
	}
	string find(const int index)
	{
		return pocketmonNameList[index - 1];
	}
private:
	int listSize;
	hash<string> str_hash;
	vector<string> pocketmonNameList;
	vector<size_t> pocketmonHashList;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	pocketmonGuide Lee(N);
	for (int i = 0; i < N; i++)
	{
		string in_list;
		cin >> in_list;
		Lee.insert(in_list);
	}

	for (int i = 0; i < M; i++)
	{
		string guess_str;
		cin >> guess_str;
		if (isdigit(guess_str[0]) == 0)
			cout << Lee.find(guess_str) << '\n';
		else
		{
			int guess_num = 0;
			for (int j = guess_str.size() - 1; j >= 0; j--)
				guess_num += (guess_str[j] - 48) * int(pow(10, guess_str.size() - (j + 1)));
			cout << Lee.find(guess_num) << '\n';
		}
	}

	return 0;
}