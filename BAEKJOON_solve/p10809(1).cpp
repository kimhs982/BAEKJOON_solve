// 10809번, 알파벳 찾기
// STL의 iostream의 cout과 cin을 사용
#include <iostream>
using namespace std;

int main() {
	char S[101];
	int alpha[26];
	//memset(alpha, -1, sizeof(alpha));				// value에서 하위 1바이트 값만 메모리에 들어감 -> 1바이트 배열 : 256 미만의 값 & 1 바이트 초과 배열 : 0과 -1만 가능
	fill_n(alpha, 26, -1);		// value 값에 제한이 따로 없음
	cin >> S;

	int i = 0, index;
	while (S[i] != '\0') {
		index = S[i] - 97;
		if(alpha[index]==-1)
			alpha[index] = i;
		i++;
	}

	for (int j = 0; j < 26; j++)
		cout << alpha[j] << " ";

	return 0;
}