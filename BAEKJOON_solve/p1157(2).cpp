//1157번, 단어 공부
// 시간초과!
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <ctime>

int main()
{
	char* str = new char[1000000];		// 시간이 오래걸림...
	scanf("%s", str);

	int count[26] = {};
	for (int i = 0; i < strlen(str); i++)
	{
		if ((str[i] >= 65) && (str[i] <= 90))
			count[str[i] - 65]++;
		else if((str[i] >= 97) && (str[i] <= 122))
			count[str[i] - 97]++;
	}

	int max_index = 0;
	for (int i = 1; i < 26; i++)
		if (count[max_index] < count[i])
			max_index = i;

	for (int i = 0; i < 26; i++)
		if ((max_index != i) && (count[max_index] == count[i]))
		{
			max_index = 63;
			break;
		}

	if (max_index == 63)
		printf("%c\n", max_index);
	else
		printf("%c\n", max_index + 65);

	delete[] str;

	return 0;
}