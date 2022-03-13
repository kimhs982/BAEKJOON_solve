#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	int num1, num2, num3;
	scanf("%d%d%d", &num1, &num2, &num3);

	if ((num1 == num2) && (num2 == num3))
		printf("%d\n", 10000 + num1 * 1000);
	else if (num1 == num2)
		printf("%d\n", 1000 + num1 * 100);
	else if(num1 == num3)
		printf("%d\n", 1000 + num1 * 100);
	else if(num2 == num3)
		printf("%d\n", 1000 + num2 * 100);
	else {
		int max = num1;
		if (max < num2)
			max = num2;
		if (max < num3)
			max = num3;
		printf("%d\n", max);
	}

	return 0;
}