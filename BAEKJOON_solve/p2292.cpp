// 2292��, ����
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> path(1, 1);
	int N, index = 0, room_num = 1;

	cin >> N;

	while (1) {
		if (N > path[index]) {
			index++;
			if (index < path.size())		// ������ �ݺ��� �� �ߺ����� push_back�� �Ǵ� ��츦 ����
				continue;
			room_num += index * 6;
			path.push_back(room_num);
		}
		else
			break;
	}

	cout << index + 1 << endl;

	return 0;
}