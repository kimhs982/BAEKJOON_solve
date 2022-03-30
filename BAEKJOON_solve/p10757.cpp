// 10757¹ø, Å« ¼ö A+B
#include <iostream>
using namespace std;

int main() {
	int digit_A = 0, digit_B = 0, digit_result = 0;
	char* A = new char[10002];
	char* B = new char[10002];
	char* result = new char[10002];

	for (int i = 0; i < 10002; i++)
		result[i] = 48;

	for (int i = 0; i < 10002; i++) {
		A[i] = cin.get();
		if (A[i] == ' ')
			break;
		digit_A = i;
	}

	for (int i = 0; i < 10002; i++) {
		B[i] = cin.get();
		if (B[i] == '\n')
			break;
		digit_B = i;
	}

	while ((digit_A >= 0) && (digit_B >= 0)) {
		if (A[digit_A] + B[digit_B] + result[digit_result] >= 154) {
			result[digit_result] += (A[digit_A] + B[digit_B] - 106);
			result[digit_result + 1]++;
		}
		else {
			result[digit_result] += (A[digit_A] + B[digit_B] - 96);
		}
		digit_A--;
		digit_B--;
		digit_result++;
	}

	while (digit_A >= 0) {
		if ((result[digit_result] + A[digit_A]) == 106) {
			result[digit_result] = 0;
			result[digit_result + 1]++;
		}
		else
			result[digit_result] += (A[digit_A] - 48);
		digit_A--;
		digit_result++;
	}
	while (digit_B >= 0) {
		if ((result[digit_result] + B[digit_B]) == 106) {
			result[digit_result] = 0;
			result[digit_result + 1]++;
		}
		else
			result[digit_result] += (B[digit_B] - 48);
		digit_B--;
		digit_result++;
	}

	if (result[digit_result] == 48)
		digit_result--;

	for (int i = digit_result; i >= 0; i--)
		cout << short(result[i]) - 48;

	delete[] A;
	delete[] B;
	delete[] result;

	return 0;
}