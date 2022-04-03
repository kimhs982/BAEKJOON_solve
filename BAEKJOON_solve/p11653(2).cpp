// 11653��, ���μ�����
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> factorization_into_primes(int);

int main() {
	int N;
	cin >> N;
	clock_t start, end;
	double result;


	vector<int> prime_list = factorization_into_primes(N);

	for (int elem : prime_list)
		cout << elem << endl;

	return 0;
}

vector<int> factorization_into_primes(int in_N) {
	vector<int> p_list;

	// ��� �ռ����� �� ���� �����ٺ��� �۰ų� ���� ����� ���´�.
	for (int i = 2; i <= sqrt(in_N); i++) {
		while (in_N % i == 0) {
			p_list.push_back(i);
			in_N /= i;
		}
		if (in_N == 1)
			break;
	}

	if (in_N > 1)
		p_list.push_back(in_N);

	return p_list;
}