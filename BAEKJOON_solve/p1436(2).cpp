// 1436��, ��ȭ���� ��
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int getEndNum(int);

int main() {
	int N, end;

	scanf("%d", &N);
	end = getEndNum(N);
	printf("%d\n", end);

	return 0;
}

int getEndNum(int in_N) {
	int start = 665, count = 0, temp;
	
	// 666���� ���ڸ� 1�� ������Ű�鼭 ������ ������ Ȯ��
	while (count != in_N) {
		start++;
		temp = start;
		/*if (temp % 1000 == 666)
			count++;
		else
			while ((temp /= 10) > 0)
				if (temp % 1000 == 666) {
					count++;
					break;
				}*/
		while (temp > 0) {
			if (temp % 1000 == 666) {
				count++;
				break;
			}
			temp /= 10;
		}
	}

	return start;
}