// 1269번, 대칭 차집합
#include <iostream>
using std::ios_base;
using std::cin;
using std::cout;

#include <set>
using std::set;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A_num, B_num;
	cin >> A_num >> B_num;

	set<int> A, B;
	for (int i = 0; i < A_num; i++) {
		int in_A;
		cin >> in_A;
		A.emplace(in_A);
	}
	for (int i = 0; i < B_num; i++) {
		int in_B;
		cin >> in_B;
		B.emplace(in_B);
	}

	// A와 B의 공통 원소 찾기
	int cnt = 0;
	if (A_num > B_num)
		for (auto i = A.begin(); i != A.end(); i++) {
			if (*i > *B.rbegin() || cnt > B_num)
				break;
			if (B.count(*i))
				cnt++;
		}
	else
		for (auto i = B.begin(); i != B.end(); i++) {
			if (*i > *A.rbegin() || cnt > A_num)
				break;
			if (A.count(*i))
				cnt++;
		}
	cout << (A_num - cnt) + (B_num - cnt);

	return 0;
}