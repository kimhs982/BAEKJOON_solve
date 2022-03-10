#include <iostream>
using namespace std;

int main() {
	int C, N;
	double mean;

	cin >> C;
	for (int i = 0; i < C; i++)
	{
		int sum = 0, count = 0;
		cin >> N;
		int* score_ptr = new int[N];
		for (int j = 0; j < N; j++)
		{
			cin >> score_ptr[j];
			sum += score_ptr[j];
		}
		mean = static_cast<double>(sum) / N;
		for (int j = 0; j < N; j++)
		{
			if (score_ptr[j] > mean)
				count++;
		}
		cout << fixed;
		cout.precision(3);
		cout << static_cast<double>(count) / N * 100 << "%\n";
		delete[] score_ptr;
	}

	return 0;
}