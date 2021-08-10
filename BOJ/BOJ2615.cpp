//#include<iostream>
//
//using namespace std;
//
//int map[19][19];
//
//int dc[4] = {0,1,1,1};
//int dr[4] = {1,1,0,-1};
//
//bool solve(int c, int r, int color, int dir) {
//	int count = 1; //돌의 갯수를 세기 위한 변수
//	int nc = c + dc[dir];
//	int nr = r + dr[dir];
//	//탐색할 방향의 반대방향에 같은 색의 돌이 있으면 이미 해본 것이므르 false 반환
//	if (map[c - dc[dir]][r - dr[dir]] == color) {
//		return false;
//	}
//	while (true) {
//		//돌의 갯수가 5개 이상이면 종료
//		if (count > 5) {
//			break;
//		}
//		//탐색할 위치가 맵안에 없거나 같은 색의 돌이 아니면 종료
//		if (nc < 0 || nc >= 19 || nr < 0 || nr >= 19 || map[nc][nr] != color) {
//			break;
//		}
//		//맵안에 있고 같은 색의 돌이면 갯수 증가 후 다음 위치 계산
//		count++;
//		nc = nc + dc[dir];
//		nr = nr + dr[dir];
//	}
//
//	//돌의 갯수가 5개면 true 반환
//	if (count == 5) {
//		return true;
//	}
//	//아니면 false 반환
//	else {
//		return false;
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	bool flag = false;
//	int win = 0;
//	pair <int, int> p;
//
//	for (int i = 0; i < 19; i++) {
//		for (int j = 0; j < 19; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	for (int i = 0; i < 19; i++) {
//		for (int j = 0; j < 19; j++) {
//			//돌을 만나면
//			if (map[i][j] != 0) {
//				//4방 탐색
//				for (int k = 0; k < 4; k++) {
//					//반환값이 true이면
//					if (solve(i, j, map[i][j], k)) {
//						flag = true;     //승패가 결정 났다고 표시
//						win = map[i][j]; //이긴 돌을 저장
//						//탐색 방향이 왼쪽 대각선 아래이면 오목이 완성된 마지막 돌이 가장 왼쪽돌이므로 행과 열 계산 후 저장
//						if (k == 3) {
//							p.first = i + 4;
//							p.second = j - 4;
//						}
//						//나머지 방향들은 오목 시작 위치가 가장 왼쪽 돌이므로 행과 열 바로 저장
//						else {
//							p.first = i;
//							p.second = j;
//						}
//						break;
//					}
//				}
//				if (flag) {
//					break;
//				}
//			}
//		}
//		if (flag) {
//			break;
//		}
//	}
//	//승패가 결정났을 시
//	if (flag) {
//		cout << win << "\n" << p.first + 1 << " " << p.second + 1 << "\n";
//	}
//	//무승부일 때
//	else {
//		cout << win << "\n";
//	}
//	
//	return 0;
//}