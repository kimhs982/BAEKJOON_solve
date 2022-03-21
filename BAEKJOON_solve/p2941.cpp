// 2941번, 크로아티아 알파벳
#include <iostream>
#include <string>
using namespace std;

int croatia_alphabet(const string&);

int main() {
	string input;
	cin >> input;
	cout << croatia_alphabet(input) << endl;

	return 0;
}

int croatia_alphabet(const string& str) {
	int count = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'c') {
			if ((str.substr(i, 2) == "c=") || (str.substr(i, 2) == "c-")) {
				count++;
				i++;
			}
			else
				count++;
		}
		else if (str[i] == 'd') {
			if (str.substr(i, 3) == "dz=") {
				count++;
				i += 2;
			}
			else if (str.substr(i, 2) == "d-") {
				count++;
				i++;
			}
			else
				count++;
		}
		else if (str[i] == 'l') {
			if (str.substr(i, 2) == "lj") {
				count++;
				i++;
			}
			else
				count++;
		}
		else if (str[i] == 'n') {
			if (str.substr(i, 2) == "nj") {
				count++;
				i++;
			}
			else
				count++;
		}
		else if (str[i] == 's') {
			if (str.substr(i, 2) == "s=") {
				count++;
				i++;
			}
			else
				count++;
		}
		else if (str[i] == 'z') {
			if (str.substr(i, 2) == "z=") {
				count++;
				i++;
			}
			else
				count++;
		}
		else
			count++;
	}

	return count;
}