// 1940��, 01Ÿ��
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

#include <memory>
using std::unique_ptr;

int count_01tile(int);

int main() {
	int N;
	scanf("%int", &N);

	printf("%d", count_01tile(N));

	return 0;
}

int count_01tile(int in_N) {
	if (in_N <= 2)
		return in_N;
	unique_ptr<int[]> T(new int[in_N]);
	T[0] = 1, T[1] = 2;

	// ��ȭ�� : T[N] = T[N - 1] + T[N - 2]
	// (A + B) % N == A % N + B % N -> ���ڰ� �ſ� Ŀ�� ���� ����Ͽ� ������ X
	for (int i = 2; i < in_N; i++)
		T[i] = (T[i - 1] + T[i - 2]) % 15746;

	return T[in_N - 1];
}