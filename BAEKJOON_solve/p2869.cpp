// 2869��, �����̴� �ö󰡰� �ʹ�
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int A, B, V;
	cin >> A >> B >> V;

	//int climb = 0, day = 0;
	//while (1) {		// �ð� �ʰ�
	//	day++;
	//	climb += A;
	//	if (climb >= V)
	//		break;
	//	climb -= B;
	//}

	int day;
	day = ceil((double(V) - double(A)) / (double(A) - double(B))) + 1;

	cout << day << endl;

	return 0;
}