// 1316번, 그룹 단어 체커
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int N, g_count = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int index = 0;
		bool g_word = true;
		cin >> str;
		char* str_ptr = new char[str.size()];
		for (int j = 0; j < int(str.size()); j++) {
			if (j == 0)
				str_ptr[index++] = str[0];
			else if (str[j - 1] != str[j]) {
				for (int k = 0; k < index; k++)
					if (str_ptr[k] == str[j]) {
						g_word = false;
						break;
					}
				if (g_word == true) {
					str_ptr[index] = str[j];
					index++;
				}
				else
					break;
			}
		}
		if (g_word == true)
			g_count++;
		delete[] str_ptr;
	}

	cout << g_count << endl;

	return 0;
}