// 10757��, ū �� A+B
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<short> big_plus1(const string&, const string&);
vector<short> big_plus2(string&, string&);

int main() {
	string A, B;
	vector<short> result;
	cin >> A >> B;

	result = big_plus2(A, B);

	for (unsigned int i = 0; i < result.size(); i++)
		cout << result[i];

	return 0;
}

vector<short> big_plus1(const string& in_A, const string& in_B) {
	vector<short> sum_result;
	int index_A = in_A.length() - 1, index_B = in_B.length() - 1;
	int index_com = (index_A > index_B ? index_A : index_B);

	for (int i = index_A; i >= 0; i--)
		sum_result.push_back(in_A[i] - '0');

	if (index_A > index_B)
		for (int i = 0; i <= index_B; i++)
			sum_result[i] += (in_B[index_B - i] - '0');
	else
		for (int i = 0; i <= index_B; i++) {
			if (i <= index_A)
				sum_result[i] += (in_B[index_B - i] - '0');
			else
				sum_result.push_back(in_B[index_B - i] - '0');
		}

	for (int i = 0; i <= index_com; i++)
		if (sum_result[i] >= 10) {
			sum_result[i] %= 10;
			if (i == index_com)
				sum_result.push_back(1);
			else
				sum_result[i + 1]++;
		}
	reverse(sum_result.begin(), sum_result.end());

	return sum_result;
}

vector<short> big_plus2(string& in_A, string& in_B) {
	// in_A�� in_B string�߿� ���̰� �� �� ���� in_A�� �ǵ��� swap��
	if (in_A.length() < in_B.length())
		swap(in_A, in_B);

	vector<short> sum_result;

	// string in_A�� ������ ��ȯ�Ͽ� sum_result�� ����
	for (int i = in_A.length() - 1; i >= 0; i--)
		sum_result.push_back(in_A[i] - '0');

	// string in_B�� ������ ��ȯ�Ͽ� sum_result�� ����
	for (int i = 0; i < in_B.length(); i++)
		sum_result[i] += (in_B[in_B.length() - i - 1] - '0');

	// 10���� ũ�ų� ���� sum_result�� ���Ҹ� ������ ����(%)�� ���ؼ� 10���� ���� ������ �ٲٰ�, carry�� ���� ���ҿ� �ѱ�
	for (int i = 0; i < sum_result.size(); i++)
		if (sum_result[i] >= 10) {
			sum_result[i] %= 10;
			if (i == sum_result.size() - 1)
				sum_result.push_back(1);
			else
				sum_result[i + 1]++;
		}
	// sum_result(vector)�� ������ ����
	reverse(sum_result.begin(), sum_result.end());

	return sum_result;
}