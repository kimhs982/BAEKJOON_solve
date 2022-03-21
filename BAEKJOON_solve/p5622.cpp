// 5622번, 다이얼
#include <iostream>
using namespace std;

int main() {
	char call_num[16];
	int total_time = 0;

	cin >> call_num;
	for (int i = 0; call_num[i] != NULL; i++)
		if (call_num[i] >= 87)
			total_time += 10;
		else if (call_num[i] >= 84)
			total_time += 9;
		else if (call_num[i] >= 80)
			total_time += 8;
		else if (call_num[i] >= 77)
			total_time += 7;
		else if (call_num[i] >= 74)
			total_time += 6;
		else if (call_num[i] >= 71)
			total_time += 5;
		else if (call_num[i] >= 68)
			total_time += 4;
		else if (call_num[i] >= 65)
			total_time += 3;
	cout << total_time << endl;

	return 0;
}