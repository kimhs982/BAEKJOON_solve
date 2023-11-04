#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned int N, K;
	cin >> N >> K;

	if (K == 1)
		cout << 1 << '\n';
	else {
		vector<unsigned int> divisor_list{ 1, N };

		unsigned int count = 1;
		for (int i = 2; i <= sqrt(N); i++)
			if (N % i == 0) {
				if (i == N / i)
					divisor_list.emplace_back(i);
				else {
					divisor_list.emplace_back(i);
					divisor_list.emplace_back(N / i);
				}
				count++;
				if (K == count)
					break;
			}
		if (divisor_list.size() > 2)
			sort(divisor_list.begin(), divisor_list.end());

		if (K > divisor_list.size())
			cout << 0 << '\n';
		else
			cout << divisor_list[K - 1] << '\n';
	}
}