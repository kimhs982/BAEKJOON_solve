// 9184번, 신나는 함수 실행
#include <iostream>
using std::ios_base;
using std::cin;
using std::cout;

void print_w1(int, int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		print_w1(a, b, c);
	}

	return 0;
}

void print_w1(int in_a, int in_b, int in_c) {
	if (in_a <= 0 || in_b <= 0 || in_c <= 0) {
		cout << "w(" << in_a << ", " << in_b << ", " << in_c << ") = 1\n";
		return;
	}

	int temp_a = in_a, temp_b = in_b, temp_c = in_c;
	if (in_a > 20 || in_b > 20 || in_c > 20)
		temp_a = temp_b = temp_c = 20;

	// 3차원 배열 동적 할당
	int*** w = new int** [temp_a + 1];
	for (int i = 0; i <= temp_a; i++) {
		w[i] = new int* [temp_b + 1];
		for (int j = 0; j <= temp_b; j++)
			w[i][j] = new int[temp_c + 1];
	}

	for (int i = 0; i <= temp_a; i++)
		for (int j = 0; j <= temp_b; j++)
			for (int k = 0; k <= temp_c; k++) {
				if (i == 0 || j == 0 || k == 0)
					w[i][j][k] = 1;
				else if (i < j && j < k)
					w[i][j][k] = w[i][j][k - 1] + w[i][j - 1][k - 1] - w[i][j - 1][k];
				else
					w[i][j][k] = w[i - 1][j][k] + w[i - 1][j - 1][k] + w[i - 1][j][k - 1] - w[i - 1][j - 1][k - 1];
			}


	cout << "w(" << in_a << ", " << in_b << ", " << in_c << ") = " << w[temp_a][temp_b][temp_c] << '\n';

	// 3차원 배열 메모리 해제
	for (int i = 0; i < temp_a; i++) {
		for (int j = 0; j < temp_b; j++)
			delete[] w[i][j];
		delete[] w[i];
	}
	delete[] w;
}