// 4948번, 베르트랑 공준
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

int countPrimeNum(int);

int main() {
	int n, count;

	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		count = countPrimeNum(n);
		printf("%d\n", count);
	}

	return 0;
}

int countPrimeNum(int num) {
	if (num == 1)
		return 1;
	vector<int> PN_list;

	for (int i = 2; i <= sqrt(2 * num); i++) {
		bool checkPN = true;
		for (int j = 2; j <= sqrt(i); j++)
			if (i % j == 0) {
				checkPN = false;
				break;
			}
		if (checkPN)
			PN_list.emplace_back(i);
	}


	int count = 0;
	for (int i = num + 1; i <= 2 * num; i++) {
		bool check = true;
		for (int j : PN_list)
			if (i % j == 0) {
				check = false;
				break;
			}
		if (check)
			count++;
	}

	return count;
}