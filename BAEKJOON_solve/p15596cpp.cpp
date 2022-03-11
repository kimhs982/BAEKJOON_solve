// 백준 15596번, vector 클래스로 합을 구하는 함수 구현
#include <vector>

long long sum1(std::vector<int>& a) {
	long long ans = 0;
	for (auto i = a.begin(); i != a.end(); i++)		// iterator(반복자)를 통해 vector 원소에 접근
		ans += *i;
	return ans;
}

long long sum2(std::vector<int>& a) {
	long long ans = 0;
	for (int i = 0; i < a.size(); i++)		// vector의 size()를 반환하여 index로 직접 접근
		ans += a[i];
	return ans;
}