// 1929��, �Ҽ� ���ϱ�, �ð� �ʰ�
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
	if (in_start != 1) {		// ������ 1�� ���ԵǾ� ���� ��
		num_list.reserve(in_end - in_start + 1);
		for (int i = in_start; i <= in_end; i++)
			num_list.emplace_back(i);
	}
	else {		// ������ 1�� ���Ե��� ���� ��
		num_list.reserve(in_end - in_start);
		for (int i = in_start + 1; i <= in_end; i++)
			num_list.emplace_back(i);
	}

	int gap = 2;		// ��� ���� ����
	for (int i = 2; i <= sqrt(in_end); i++) {		// ���� ���� n�� �ռ����̸�, n�� ���μ� �߿��� p <= n^1/2�� ���μ� p�� ����, �����佺�׳׽��� ü
		bool pDecision = true;
		for (int j = 2; j <= sqrt(i); j++)		// �Ҽ� �Ǵ�
			if (i % j == 0)
				pDecision = false;
		if (pDecision == false)
			continue;

		vector<int> index_list;
		int index = 0, mul = 1, j;
		for (j = i; j <= in_end; j = i * (++mul)) {		// �Ҽ��� ����� �߿� ���� ���� �����ϴ� ������ index�� ã�Ƽ� ��ȯ
			if (j < in_start)
				continue;
			index = vector_search(num_list, j);
			if (index != -1)
				break;
			else
				continue;
		}

		if (i == j)		// ã�� ���ڰ� �Ҽ��� ���
			for (int k = index + gap; k < num_list.size(); k += gap)
				index_list.emplace_back(k);
		// ã�� ���ڰ� �Ҽ��� �ƴ� ���(�Ҽ��� ����� ���)
		else
			for (int k = index; k < num_list.size(); k += gap)
				index_list.emplace_back(k);

		for (int l : index_list)		// �Ҽ��� ����� ��� 0���� �ٲ�
			num_list[l] = 0;
		for (int l = (i == j ? index + gap : index); l < num_list.size(); l++)		// ���� 0�� ���Ҹ� ����
			if(num_list[l]==0)
				num_list.erase(num_list.begin() + l);
		gap++;		// ��� ���� ������ 1��ŭ ������Ŵ
		index_list.clear();		// ������� index�� ������ vector�� �ʱ�ȭ
	}

	for (unsigned int i = 0; i < num_list.size(); i++)
			cout << num_list[i] << endl;
}