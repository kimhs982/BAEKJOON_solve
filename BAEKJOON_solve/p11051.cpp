// 11051��, ���� ���2
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using std::min;

int BinomialCoefficient1(int, int);
int BinomialCoefficient2(int, int);
int BinomialCoefficient_rem10007(int, int);

int main() {
	int N, K;
	scanf("%d%d", &N, &K);

	printf("%d\n", BinomialCoefficient_rem10007(N, K));

	return 0;
}

// ���� ���(DP)
int BinomialCoefficient1(int N, int K) {
	int result;
	// ���� ��� ������ ������ 2���� �迭 �����Ҵ�
	int** BC = new int* [N + 1];
	for (int i = 0; i < N + 1; i++)
		*(BC + i) = new int[K + 1];

	// nC0�� ��� ��� 1�� �ʱ�ȭ
	for (int n = 1; n <= N; n++)
		BC[n][0] = 1;

	// ���� ��� ���ϱ�
	for (int n = 1; n <= N; n++)
		for (int k = 1; k <= K; k++) {
			if (n < k)
				continue;
			if (n == k)
				BC[n][k] = 1;
			else
				BC[n][k] = BC[n - 1][k - 1] + BC[n - 1][k];
		}

	// N_C_K �� ����
	result = BC[N][K];

	// ���� ��� ������ �����ϰ� �ִ� 2���� �迭 �޸� ����
	for (int i = 0; i < N + 1; i++)
		delete[] BC[i];
	delete[] BC;

	return result;
}

// ���� ���(DP), ����ð� ����
int BinomialCoefficient2(int N, int K) {
	int result;
	int** BC = new int* [N + 1];
	for (int i = 0; i < N + 1; i++)
		*(BC + i) = new int[K + 1];

	for (int n = 1; n <= N; n++)
		for (int k = 0; k <= min(n, K); k++)
			if ((k == 0) || (k == n))
				BC[n][k] = 1;
			else
				BC[n][k] = BC[n - 1][k - 1] + BC[n - 1][k];

	result = BC[N][K];

	for (int i = 0; i < N + 1; i++)
		delete[] BC[i];
	delete[] BC;

	return result;
}

int BinomialCoefficient_rem10007(int N, int K) {
	int result;
	int** BC = new int* [N + 1];
	for (int i = 0; i < N + 1; i++)
		*(BC + i) = new int[K + 1];

	for (int n = 1; n <= N; n++)
		for (int k = 0; k <= min(n, K); k++) {
			if ((k == 0) || (k == n))
				BC[n][k] = 1;
			else
				BC[n][k] = (BC[n - 1][k - 1] + BC[n - 1][k]) % 10007;
		}

	result = BC[N][K];

	for (int i = 0; i < N + 1; i++)
		delete[] BC[i];
	delete[] BC;

	return result;
}