// 10989��, �� �����ϱ�3
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	int N, temp;
	int* arr = new int[10001]();		// 1~10000 ������ �ڿ����� index�� �ޱ� ����

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		arr[temp]++;		// �Է� ���� temp�� index�� �޾� arr[temp]�� 1 ����
	}

	int count = 0;
	for (int i = 1; i < 10001; i++) {		// 1~10000 ������ �ڿ���
		for (int j = 0; j < arr[i]; j++) {		// ī��Ʈ�� Ƚ����ŭ �ݺ�
			printf("%d\n", i);
			count++;
		}
		if (count == N)		// �Է� ���� ����ŭ ����� ��� �ݺ��� ����
			break;
	}

	delete[] arr;
	return 0;
}