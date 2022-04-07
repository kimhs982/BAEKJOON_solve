// 4948번, 베르트랑 공준
#include <iostream>
#include <vector>
using namespace std;

#define MAX_NUM 123456 * 2

int main() {
	int* num_list = new int[MAX_NUM + 1]{ 1,1,0 };
	vector<int> input_list;
	int n;

	for (int i = 2; i <= MAX_NUM / 2; i++)
		for (int j = 2; i * j <= MAX_NUM; j++)
			num_list[i * j] = 1;

	while (1) {
		cin >> n;
		if (n == 0)
			break;
		input_list.emplace_back(n);
	}

	for (int i : input_list) {
		int count = 0;
		for (int j = i + 1; j <= i * 2; j++)
			if (num_list[j] == 0)
				count++;
		cout << count << endl;
	}
	
	delete[] num_list;

	return 0;
}