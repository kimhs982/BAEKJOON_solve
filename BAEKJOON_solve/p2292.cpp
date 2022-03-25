// 2292번, 벌집
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
			if (index < path.size())		// 여러번 반복할 때 중복으로 push_back이 되는 경우를 방지
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