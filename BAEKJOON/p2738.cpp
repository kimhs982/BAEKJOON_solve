// 2738번, 행렬 덧셈
#include <iostream>
using std::cin;
using std::cout;

int main() {
	int N, M;		// N: 행(row), M: 열(column)
	cin >> N >> M;

	// 동적 할당
	int** matrix = new int* [N];
	for (int i = 0; i < N; i++)
		matrix[i] = new int[M]();


	// 두 행렬 입력
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < N; j++)

	// 메모리 공간 해제
	for (int i = 0; i < N; i++)
		delete[] matrix[i];
	delete[] matrix;

	return 0;
}