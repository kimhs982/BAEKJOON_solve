// 1978번, 소수 찾기
#include <iostream>
using namespace std;

int primeNumber_count(const int[], int);

int main() {
	int N, in_num;
	cin >> N;

	int* num_list = new int[N];
	for (int i = 0; i < N; i++)
		cin >> num_list[i];
		
	cout << primeNumber_count(num_list, N) << endl;

	delete[] num_list;

	return 0;
}

int primeNumber_count(const int n_list[], int size) {
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (n_list[i] == 1)
			continue;
		int decision_count = 0;
		for (int j = 2; j < n_list[i]; j++)
			if (n_list[i] % j == 0)
				decision_count++;

		if (decision_count == 0)
			count++;
	}

	return count;
}