//#include<iostream>
//
//using namespace std;
//
//char map[64][64];
//
//void solve(int c, int r, int size) {
//	int zero = 0;
//	int one = 0;
//	//0과 1의 갯수 세기
//	for (int i = c; i < c+size; i++) {
//		for (int j = r; j < r+size; j++) {
//			if (map[i][j] == '0') {
//				zero++;
//			}
//			else if (map[i][j] == '1') {
//				one++;
//			}
//			//0과 1이 모두 있으면 탈출
//			if (zero > 0 && one > 0) {
//				break;
//			}
//		}
//	}
//
//	//0과 1이 모두 있으면 분할 시작
//	if (zero > 0 && one > 0) {
//		cout << "("; //분할했으니 "(" 출력
//		solve(c, r,  size / 2); //1사분면
//		solve(c, r + (size / 2), size / 2); //2사분면
//		solve(c + (size / 2), r, size / 2); //4사분면
//		solve(c + (size / 2), r + (size / 2), size / 2); //3사분면
//		cout << ")"; //분할끝났으니 ")" 출력
//	}
//	//0만 있으면 0 출력
//	else if (zero > 0 && one == 0) {
//		cout << "0";
//		return;
//	}
//	//1만 있으면 1출력
//	else if (zero == 0 && one > 0) {
//		cout << "1";
//		return;
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N;
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	solve(0, 0, N);
//
//	return 0;
//}