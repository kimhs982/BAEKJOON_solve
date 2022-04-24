// 2231��, ������
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int getDecomSum(int);

int main() {
	int N, M;

	scanf("%d", &N);
	M = getDecomSum(N);

	printf("%d\n", M);

	return 0;
}

int getDecomSum(int in_N) {
	int copy = in_N, num_digit = 0, startNum;
	// �� �ڸ����� ���
	if (in_N < 10)
		startNum = 1;
	// 10 ~ 27 ������ ���� ���
	else if (in_N < 28)
		startNum = 10;
	// 28 �̻��� ���
	else {
		// �ڸ��� ���ϱ�
		while (copy > 0) {
			num_digit++;
			copy /= 10;
		}
		startNum = in_N - (num_digit * 9);
	}

	// �����ڰ� ������ �� �ִ� ���� ���� ������ ã��
	for (int i = startNum; i < in_N; i++) {
		int copy_sum = copy = i;
		while (copy > 0) {
			copy_sum += (copy % 10);
			copy /= 10;
		}
		if (copy_sum == in_N)
			return i;
	}

	return 0;
}