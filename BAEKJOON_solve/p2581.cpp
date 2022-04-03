// 2581¹ø, ¼Ò¼ö
#include <iostream>
using namespace std;

int primeNumber_min_find(int, int, int&);

int main() {
	int start, end, sum = 0, min;
	cin >> start;
	cin >> end;

	min = primeNumber_min_find(start, end, sum);
	
	if (sum != -1)
		cout << sum << '\n' << min << endl;
	else
		cout << sum << endl;

	return 0;
}

int primeNumber_min_find(int start, int end, int& sum) {
	int min = 0, count = 0;

	for (int i = start; i <= end; i++) {
		if (i == 1)
			continue;
		int decide_PN = 0;
		for (int j = 2; j < i; j++)
			if (i % j == 0) {
				decide_PN++;
				break;
			}
		if (decide_PN == 0) {
			if (min == 0)
				min = i;
			sum += i;
			count++;
		}
	}
	if (count == 0)
		sum = -1;

	return min;
}