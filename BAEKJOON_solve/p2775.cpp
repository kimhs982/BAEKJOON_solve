// 2275번, 부녀회장이 될테야
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<int>> family_num;
	vector<int> floor_num = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	family_num.push_back(floor_num);

	int T, k, n;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k;
		cin >> n;
		if (k > family_num.size() - 1) {
			for (int j = family_num.size(); j <= k; j++) {
				int temp_sum = 0;
				floor_num.clear();
				for (int l = 0; l < 14; l++) {
					temp_sum += family_num[j - 1][l];
					floor_num.push_back(temp_sum);
				}
				family_num.push_back(floor_num);
			}
		}
		cout << family_num[k][n - 1] << endl;
	}

	return 0;
}