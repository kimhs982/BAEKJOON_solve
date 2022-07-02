// 1269��, ��Ī ������
#include <iostream>
using std::ios_base;
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;
using std::binary_search;

int main() {
	int A_num, B_num;
	cin >> A_num >> B_num;

	vector<int> A;
	A.reserve(A_num);
	for (int i = 0; i < A_num; i++) {
		int in_A;
		cin >> in_A;
		A.emplace_back(in_A);
	}
	// ���� Ž��(Binary Search)�� ���� ����
	sort(A.begin(), A.end());

	int cnt = 0;
	for (int i = 0; i < B_num; i++) {
		int in_B;
		cin >> in_B;
		// ���� Ž��(Binary Search)
		if (binary_search(A.begin(), A.end(), in_B))
			cnt++;
	}
	cout << (A_num - cnt) + (B_num - cnt);

	return 0;
}