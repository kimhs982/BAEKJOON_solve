// 2738��, ��� ����
#include <iostream>
using std::cin;
using std::cout;

int main() {
	int N, M;		// N: ��(row), M: ��(column)
	cin >> N >> M;

	// ���� �Ҵ�
	int** matrix = new int* [N];
	for (int i = 0; i < N; i++)
		matrix[i] = new int[M]();


	// �� ��� �Է�
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < N; j++)

	// �޸� ���� ����
	for (int i = 0; i < N; i++)
		delete[] matrix[i];
	delete[] matrix;

	return 0;
}