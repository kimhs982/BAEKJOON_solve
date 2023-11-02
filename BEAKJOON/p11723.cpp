// 11723Йј, С§Че
#include <iostream>
#include <string>
using namespace std;

void S(const string&);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		string cmd;
		int x;
		cin >> cmd;
		S(cmd);
	}
}

void S(const string& cmd) {
	static int cus_S = 0;

	int x;
	if (cmd == "add") {
		cin >> x;
		cus_S |= (1 << (x - 1));
	}
	else if (cmd == "remove") {
		cin >> x;
		cus_S &= ~(1 << (x - 1));
	}
	else if (cmd == "check") {
		cin >> x;
		if (cus_S & (1 << (x - 1)))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	else if (cmd == "toggle") {
		cin >> x;
		cus_S ^= (1 << (x - 1));
	}
	else if (cmd == "all")
		cus_S = (1 << 20) - 1;
	else if (cmd == "empty")
		cus_S = 0;
}