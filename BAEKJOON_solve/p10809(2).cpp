// 10809��, ���ĺ� ã��
// STL�� cstdio�� printf�� scanf�� ���
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

int main() {
	char S[101];
	int alpha[26];
	memset(alpha, -1, sizeof(alpha));
	scanf("%s", S);

	int i = 0, index;
	while (S[i] != '\0') {
		index = S[i] - 97;
		if (alpha[index] == -1)
			alpha[index] = i;
		i++;
	}

	for (int j = 0; j < 26; j++)
		printf("%d ", alpha[j]);

	return 0;
}