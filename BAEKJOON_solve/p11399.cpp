// 11399锅, ATM
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename key>
void insertionSort(vector<key>& p, int n) {
	key temp;

	for (int i = 1; i < n; i++) {
		temp = p[i];
		int j = i - 1;
		while ((j >= 0) && (p[j] > temp)) {
			p[j + 1] = p[j];
			j--;
		}
		p[j + 1] = temp;
	}
}

template <typename key>
void exchange(key& x, key& y) {
	key temp;
	temp = x;
	x = y;
	y = temp;
}

template <typename key>
void selectionSort(vector<key>& p, int n) {
	key temp, smallest;

	for (int i = 0; i < n - 1; i++) {
		smallest = i;
		for (int j = i + 1; j < n; j++)
			if (p[j] < p[smallest])
				smallest = j;
		exchange(p[i], p[smallest]);
	}
}

int main() {
	int N, in_P, total_time = 0;
	cin >> N;
	vector<int> P(N);
	for (int i = 0; i < N; i++) {
		cin >> in_P;
		P[i] = in_P;
	}

	//insertionSort<int>(P, N);		// 流立 备泅茄 insertion sort
	//selectionSort<int>(P, N);		// 流立 备泅茄 selection sort
	sort(P.begin(), P.end());

	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			total_time += P[j];

	cout << total_time << endl;

	return 0;
}