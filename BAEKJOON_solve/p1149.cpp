// 1149¹ø, RGB°Å¸®(DP)
#include <iostream>
using std::ios_base;
using std::cin;
using std::cout;

#include <algorithm>
using std::min;

int minCost_RGB(int**, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int** C = new int* [N];
	for (int i = 0; i < N; i++)
		C[i] = new int[3];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> C[i][j];

	cout << minCost_RGB(C, N);

	for (int i = 0; i < N; i++)
		delete[] C[i];
	delete[] C;

	return 0;
}

int minCost_RGB(int** CL, int in_N) {
	for (int i = 1; i < in_N; i++) {
		CL[i][0] = CL[i][0] + min(CL[i - 1][1], CL[i - 1][2]);
		CL[i][1] = CL[i][1] + min(CL[i - 1][0], CL[i - 1][2]);
		CL[i][2] = CL[i][2] + min(CL[i - 1][0], CL[i - 1][1]);
	}

	return min(min(CL[in_N - 1][0], CL[in_N - 1][1]), CL[in_N - 1][2]);
}