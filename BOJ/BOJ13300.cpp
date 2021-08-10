//#include<iostream>
//
//using namespace std;
//
//int boy[6], girl[6];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	int N, K, S, Y, count = 0;
//	cin >> N >> K;
//
//	for (int i = 0; i < N; i++) {
//		cin >> S >> Y;
//		//남학생인 경우
//		if (S == 1) {
//			//해당 학년의 방이 꽉 찼으면
//			if (boy[Y - 1] == K) {
//				boy[Y - 1] = 0; //방을 0으로 초기화
//				count++; //방의 수 증가
//			}
//			boy[Y - 1]++; //해당 학년의 방에 공간이 남아 있다면 해당 방의 수를 하나 증가
//		}
//		//여학생인 경우
//		else {
//			//해당 학년의 방이 꽉 찼으면
//			if (girl[Y - 1] == K) {
//				girl[Y - 1] = 0; //방을 0으로 초기화
//				count++; //방의 수 증가
//			}
//			girl[Y - 1]++; //해당 학년의 방에 공간이 남아 있다면 해당 방의 수를 하나 증가
//		}
//
//	}
//	//학년별 방의 수를 세기 위해 탐색
//	for (int i = 0; i < 6; i++) {
//		//해당 학년의 방의 인원 수가 0이 아니라면 방의 갯수를 증가
//		if (boy[i] != 0) {
//			count++;
//		}
//		if (girl[i] != 0) {
//			count++;
//		}
//	}
//
//	cout << count << "\n";
//
//	return 0;
//}