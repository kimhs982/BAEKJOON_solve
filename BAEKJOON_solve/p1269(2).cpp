// 1269번, 대칭 차집합
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
	// 이진 탐색(Binary Search)을 위한 정렬
	sort(A.begin(), A.end());

	int cnt = 0;
	for (int i = 0; i < B_num; i++) {
		int in_B;
		cin >> in_B;
		// 이진 탐색(Binary Search)
		if (binary_search(A.begin(), A.end(), in_B))
			cnt++;
	}
	cout << (A_num - cnt) + (B_num - cnt);

	return 0;
}