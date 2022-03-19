#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int count = 0, c_word = 0;
	bool first = true;
	getline(cin, str);

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			c_word = i + 1;
			if (i != 0 && i != str.length() - 1)
				count++;
		}
		else {
			if ((str[i] == str[c_word]) && (i != c_word)) {
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
						if (first == true) {
							count++;
							first = false;
						}
						count++;
						c_word = i;
						i += j;
					}
				}
			}
		}
	}
	cout << count + 1 << endl;

	return 0;
}