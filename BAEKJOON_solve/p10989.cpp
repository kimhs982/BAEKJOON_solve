// 10989번, 수 정렬하기3
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	int N, temp;
	int* arr = new int[10001]();		// 1~10000 범위의 자연수를 index로 받기 위함

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		arr[temp]++;		// 입력 받은 temp를 index로 받아 arr[temp]를 1 증가
	}

	int count = 0;
	for (int i = 1; i < 10001; i++) {		// 1~10000 범위의 자연수
		for (int j = 0; j < arr[i]; j++) {		// 카운트된 횟수만큼 반복
			printf("%d\n", i);
			count++;
		}
		if (count == N)		// 입력 받은 수만큼 출력한 경우 반복문 종료
			break;
	}

	delete[] arr;
	return 0;
}