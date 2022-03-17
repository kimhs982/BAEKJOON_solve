// 2675번, 문자열 반복
#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, R;
	cin >> T;
	string* str = new string[T];

	for (int i = 0; i < T; i++)
	{
		string temp;
		cin >> R >> str[i];

		for (auto location = str[i].begin(); location != str[i].end(); location++)
		{
			for (int j = 0; j < R; j++)
				temp.push_back(*location);
		}
		cout << temp << endl;
	}

	delete[] str;

	return 0;
}