// 1152번, 단어의 개수
// 문제의 요점을 정확하게 파악하지 못함... 딴 길로 새서 시간이 너무 오래 걸렸음...
#include <iostream>
//#include <cctype>
#include <string>
using namespace std;

int main() {
	string str;
	int count = 0;
	//int	c_word = 0, c_temp = 0;
	getline(cin, str);

	/*for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			c_word = i + 1;
			if (i != 0 && i != str.length() - 1)
				count++;
			count += c_temp;
		}
		else {
			if ((tolower(str[i]) == tolower(str[c_word])) && (i != c_word)) {
				bool check = true;
				int j;
				if (i - c_word > 1) {
					for (j = 0; j < i - c_word; j++) {
						if (str[i + j] != str[c_word + j]) {
							check = false;
							break;
						}
					}
					if (check == true) {
						count++;
						c_word = i;
						i += (j - 1);
					}
				}
				else if (i - c_word == 1) {
					c_temp++;
					c_word = i;
				}
			}
			else
				c_temp = 0;
		}
	}*/

	for (int i = 0; i < str.length(); i++)
		if (str[i] == ' ')
			count++;

	if ((str[0] == ' ') && str[str.length() - 1] == ' ')
		count--;
	else if ((str[0] != ' ') && (str[str.length() - 1] != ' '))
		count++;

	cout << count << endl;

	return 0;
}