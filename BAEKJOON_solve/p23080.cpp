// 23080번, 스키테일 암호
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <string>
using std::string;

string scytaleDecode(const string&, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int K;
	string cryptogram;
	cin >> K;
	cin >> cryptogram;

	cout << scytaleDecode(cryptogram, K) << '\n';

	return 0;
}

string scytaleDecode(const string& cryp, int k) {
	string plainText;
	for (int i = 0; i < cryp.length(); i += k)
		plainText.push_back(cryp[i]);

	return plainText;
}