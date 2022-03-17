// 2675번, 문자열 반복
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

int main() {
	int T, R;
	scanf("%d", &T);

	char* S = new char[21];
	for (int i = 0; i < T; i++)
	{
		int index = 0;
		scanf("%d%s", &R, S);
		int len = strlen(S);
		char* temp = new char[len * R + 1];
		for (int j = 0; j < len; j++)
			for (int k = 0; k < R; k++)
			{
				temp[index] = S[j];
				index++;
			}
		temp[index] = '\0';
		printf("%s\n", temp);
		delete[] temp;
	}

	delete[] S;

	return 0;
}