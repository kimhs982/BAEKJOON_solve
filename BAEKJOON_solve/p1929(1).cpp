// 1929번, 소수 구하기, 시간 초과
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void print_primeNum(int, int);

int main() {
	int start, end;
	cin >> start >> end;

	print_primeNum(start, end);

	return 0;
}

int vector_search(const vector<int>& in_list, int key) {
	for (unsigned int i = 0; i < in_list.size(); i++)
		if (in_list[i] == key)
			return i;
	return -1;
}

void print_primeNum(int in_start, int in_end) {
	vector<int> num_list;
	if (in_start != 1) {		// 범위에 1이 포함되어 있을 때
		num_list.reserve(in_end - in_start + 1);
		for (int i = in_start; i <= in_end; i++)
			num_list.emplace_back(i);
	}
	else {		// 범위에 1이 포함되지 않을 때
		num_list.reserve(in_end - in_start);
		for (int i = in_start + 1; i <= in_end; i++)
			num_list.emplace_back(i);
	}

	int gap = 2;		// 배수 간의 간격
	for (int i = 2; i <= sqrt(in_end); i++) {		// 양의 정수 n이 합성수이면, n의 소인수 중에는 p <= n^1/2인 소인수 p가 존재, 에라토스테네스의 체
		bool pDecision = true;
		for (int j = 2; j <= sqrt(i); j++)		// 소수 판단
			if (i % j == 0)
				pDecision = false;
		if (pDecision == false)
			continue;

		vector<int> index_list;
		int index = 0, mul = 1, j;
		for (j = i; j <= in_end; j = i * (++mul)) {		// 소수의 배수들 중에 가장 먼저 시작하는 숫자의 index를 찾아서 반환
			if (j < in_start)
				continue;
			index = vector_search(num_list, j);
			if (index != -1)
				break;
			else
				continue;
		}

		if (i == j)		// 찾은 숫자가 소수인 경우
			for (int k = index + gap; k < num_list.size(); k += gap)
				index_list.emplace_back(k);
		// 찾은 숫자가 소수가 아닌 경우(소수의 배수인 경우)
		else
			for (int k = index; k < num_list.size(); k += gap)
				index_list.emplace_back(k);

		for (int l : index_list)		// 소수의 배수를 모두 0으로 바꿈
			num_list[l] = 0;
		for (int l = (i == j ? index + gap : index); l < num_list.size(); l++)		// 값이 0인 원소를 삭제
			if(num_list[l]==0)
				num_list.erase(num_list.begin() + l);
		gap++;		// 배수 간의 간격을 1만큼 증가시킴
		index_list.clear();		// 배수들의 index를 저장한 vector를 초기화
	}

	for (unsigned int i = 0; i < num_list.size(); i++)
			cout << num_list[i] << endl;
}