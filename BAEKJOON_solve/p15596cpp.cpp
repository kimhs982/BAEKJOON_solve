// ���� 15596��, vector Ŭ������ ���� ���ϴ� �Լ� ����
#include <vector>

long long sum1(std::vector<int>& a) {
	long long ans = 0;
	for (auto i = a.begin(); i != a.end(); i++)		// iterator(�ݺ���)�� ���� vector ���ҿ� ����
		ans += *i;
	return ans;
}

long long sum2(std::vector<int>& a) {
	long long ans = 0;
	for (int i = 0; i < a.size(); i++)		// vector�� size()�� ��ȯ�Ͽ� index�� ���� ����
		ans += a[i];
	return ans;
}