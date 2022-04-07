// 1929��, �Ҽ� ���ϱ�, iostream�� cout, cin, endl�� ���� �ӵ��� ����(Ư�� endl�� ���۸� flush�Ͽ� �ӵ��� ����)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

void printPN(int, int);

int main() {
	int M, N;
	scanf("%d%d", &M, &N);

	printPN(M, N);

	return 0;
}

void printPN(int start, int end) {
	for (int i = start; i <= end; i++) {
		if (i == 1)		// M�� 1�� �Էµ� ���
			continue;
		else if (int(sqrt(i)) == 1) {		// 2�� 3�� ��� -> 2�� 3 ��� �Ҽ��̹Ƿ� ���
			printf("%d\n", i);
			continue;
		}
		if (i % 2 != 0) {		// 2�� ����� �ƴ� ���(Ȧ��)
			bool check = true;
			for (int j = 3; j <= sqrt(i); j += 2)		// 3���� ������ ������ Ȧ���� ������ ���������� Ȯ��
				if (i % j == 0) {
					check = false;
					break;
				}
			if (check)		// Ȧ���߿� �Ҽ��� ��� ���
				printf("%d\n", i);
		}
	}
}