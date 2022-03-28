//1025번, ACM호텔
#include <iostream>
using namespace std;

int main() {
	int T, H, W, N;

	cin >> T;
	//for (int i = 0; i < T; i++) {		// 동적 할당을 사용
	//	int H_count = 0, W_count = 0;

	//	cin >> H >> W >> N;

	//	int** hotel_room = new int* [H];

	//	for (int j = 0; j < H; j++)
	//		hotel_room[j] = new int[W];

	//	for (int j = 0; j < H; j++)
	//		for (int k = 0; k < W; k++)
	//			hotel_room[j][k] = (j + 1) * 100 + (k + 1);

	//	for (int j = 1; j < N; j++)
	//		if (H_count + 1 < H)
	//			H_count++;
	//		else {
	//			H_count = 0;
	//			if (W_count + 1 < W)
	//				W_count++;
	//		}

	//	cout << hotel_room[H_count][W_count] << endl;


	//	for (int j = 0; j < H; j++)
	//		delete[] hotel_room[j];
	//	delete[] hotel_room;
	//}

	//for (int i = 0; i < T; i++) {		// 방 번호만 차례대로 계산
	//	int H_count = 1, W_count = 1;

	//	cin >> H >> W >> N;

	//	for (int j = 1; j < N; j++)
	//		if (H_count + 1 <= H)
	//			H_count++;
	//		else {
	//			H_count = 1;
	//			W_count++;
	//		}

	//	cout << H_count * 100 + W_count << endl;
	//}

	for (int i = 0; i < T; i++) {		// for 반복문을 최소화하여 방 번호 계산
		int room_num;
		cin >> H >> W >> N;

		if (N % H == 0)
			room_num = H * 100 + N / H;
		else if (N < H)
			room_num = N % H * 100 + 1;
		else
			room_num = N % H * 100 + N / H + 1;
		
		cout << room_num << endl;
	}

	return 0;
}