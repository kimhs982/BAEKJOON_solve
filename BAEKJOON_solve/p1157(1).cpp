//1157번, 단어 공부
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main()
{
	string str;
	cin >> str;

	int count[26] = {};
	for (auto i = str.begin(); i != str.end(); i++)
	{
		if ((*i >= 65) && (*i <= 90))
			count[*i - 65]++;
		else if ((*i >= 97) && (*i <= 122))
			count[*i - 97]++;
	}

	int max_index = 0;
	for (int i = 1; i < 26; i++)
		if (count[max_index] < count[i])
			max_index = i;

	for (int i = 0; i < 26; i++)
		if ((max_index != i) && (count[max_index] == count[i]))
		{
			max_index = 63;
			break;
		}

	if (max_index == 63)
		cout << static_cast<char>(max_index) << endl;
	else
		cout << static_cast<char>(max_index + 65) << endl;

	return 0;
}