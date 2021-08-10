//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int N, M, H, a, b;
//int ladder[30][9];
//int result = 4;
//
//bool cal() {
//	for (int i = 0; i < N; i++) {
//		int n = i;
//		for (int j = 0; j < H; j++) {
//			//처음 세로선이라면
//			if (n == 0) {
//				//가로선이 있으면 세로선을 다음으로 이동
//				if (ladder[j][0] == 1) {
//					n++;
//				}
//			}
//			//마지막 세로선이라면
//			else if (n == N - 1) {
//				//가로선이 있으면 세로선을 이전으로 이동
//				if (ladder[j][n - 1] == 1) {
//					n--;
//				}
//			}
//			//처음과 마지막 세로선이 아니면
//			else {
//				//현재 위치에 가로선이 있으면 세로선을 다음으로 이동
//				if (ladder[j][n] == 1) {
//					n++;
//				}
//				//이전 위치에 가로선이 있으면 세로선을 이전으로 이동
//				else if (ladder[j][n - 1] == 1) {
//					n--;
//				}
//			}
//		}
//		//현재 세로선의 번호와 도착한 위치의 세로선의 번호가 다르면 false 반환 후 종료
//		if (n != i) {
//			return false;
//		}
//	}
//
//	//시작한 위치와 도착한 위치의 세로선이 모두 같으면 true 반환
//	return true;
//}
//
//void solve(int start, int cnt) {
//	//새로 놓은 가로선의 갯수가 3을 초과하면 종료
//	if (cnt > 3) {
//		return;
//	}
//	//사다리 계산를 한 값이 true이면
//	if (cal()) {
//		result = min(result, cnt); //가로선의 갯수 최솟값 저장
//		if (result == 0) { //가로선의 갯수가 0이라면 최솟값이므로 종료
//			return;
//		}
//	}
//
//	//계산한 값이 false이면 새로운 가로선을 추가
//	for (int i = start; i < H; i++) {
//		for (int j = 0; j < N - 1; j++) {
//			//현재 위치에 가로선이 이미 있으면 다음 탐색
//			if (ladder[i][j] == 1) {
//				continue;
//			}
//			//현재 위치 이전에 가로선이 있으면 다음 탐색(가로선 하나가 세로선 두개를 잇고 있기 때문에 이전 것도 봐야함)
//			if (j - 1 >= 0 && ladder[i][j - 1] == 1) {
//				continue;
//			}
//			//현재 위치 다음에 가로선이 있으면 다음 탐색(가로선 하나가 세로선 두개를 잇고 있기 때문에 다음 것도 봐야함)
//			if (j + 1 < N - 1 && ladder[i][j + 1] == 1) {
//				continue;
//			}
//			//위의 상황이 모두 아니라면 현재 위치에 가로선을 추가
//			ladder[i][j] = 1;
//			solve(i, cnt + 1);
//			//원상 복귀
//			ladder[i][j] = 0;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M >> H; 
//
//	for (int i = 0; i < H; i++) {
//		for (int j = 0; j < N - 1; j++) {
//			ladder[i][j] = 0;
//		}
//	}
//
//	for (int i = 0; i < M; i++) {
//		cin >> a >> b;
//		ladder[a - 1][b - 1] = 1; //가로선이 시작하는 위치에 저장
//	}
//
//	solve(0, 0);
//
//	//가로선의 갯수가 4로 종료 되었으면 -1 출력
//	if (result == 4) {
//		result = -1;
//	}
//
//	cout << result << "\n";
//
//	return 0;
//}