// 10757번, 큰 수 A+B
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
	// in_A와 in_B string중에 길이가 더 긴 것이 in_A가 되도록 swap함
	if (in_A.length() < in_B.length())
		swap(in_A, in_B);

	vector<short> sum_result;

	// string in_A를 정수로 변환하여 sum_result에 저장
	for (int i = in_A.length() - 1; i >= 0; i--)
		sum_result.push_back(in_A[i] - '0');

	// string in_B를 정수로 변환하여 sum_result에 더함
	for (int i = 0; i < in_B.length(); i++)
		sum_result[i] += (in_B[in_B.length() - i - 1] - '0');

	// 10보다 크거나 같은 sum_result의 원소를 나머지 연산(%)을 통해서 10보다 작은 값으로 바꾸고, carry를 다음 원소에 넘김
	for (int i = 0; i < sum_result.size(); i++)
		if (sum_result[i] >= 10) {
			sum_result[i] %= 10;
			if (i == sum_result.size() - 1)
				sum_result.push_back(1);
			else
				sum_result[i + 1]++;
		}
	// sum_result(vector)의 순서를 변경
	reverse(sum_result.begin(), sum_result.end());

	return sum_result;
}