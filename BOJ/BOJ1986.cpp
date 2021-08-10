//#include<iostream>
//
//using namespace std;
//int map[1000][1000];
//int dc[8] = {-1,-1,0,1,1,1,0,-1};
//int dr[8] = {0,1,1,1,0,-1,-1,-1};
////나이트의 움직임을 탐색할 배열
//int kc[8] = {-2,-2,-1,1,2,2,1,-1}; 
//int kr[8] = {-1,1,2,2,1,-1,-2,-2};
//int n, m, answer;
//
//void move(int c, int r, int dir) {
//	//이동할 방향으로 다음 행과 열 저장
//	int nc = c + dc[dir]; 
//	int nr = r + dr[dir];
//	while (true) {
//		//이동한 행과 열이 맵을 벗어나거나 이동할 위치가 빈칸이 아니라면 종료
//		if (nc < 0 || nc >= n || nr < 0 || nr >= m || map[nc][nr] > 0) {
//			break;
//		}
//		//맵안에 있으면 이동한 위치를 -1로 표시
//		else {
//			map[nc][nr] = -1;
//		}
//		//다음 행과 열 저장
//		nc = nc + dc[dir];
//		nr = nr + dr[dir];
//	}
//	//이동할 방향을 현재 방향 반대로 저장
//	dir = dir + 4;
//	//퀸이 있는 위치에서 이동할 방향으로 다음 행과 열 저장
//	nc = c + dc[dir];
//	nr = r + dr[dir];
//	while (true) {
//		//이동한 행과 열이 맵을 벗어나거나 이동할 위치가 빈칸이 아니라면 종료
//		if (nc < 0 || nc >= n || nr < 0 || nr >= m || map[nc][nr] > 0) {
//			break;
//		}
//		//맵안에 있으면 이동한 위치를 -1로 표시
//		else {
//			map[nc][nr] = -1;
//		}
//		//다음 행과 열 저장
//		nc = nc + dc[dir];
//		nr = nr + dr[dir];
//	}
//}
//
//void knight(int c, int r) {
//	//8방 탐색(나이트가 움직일 수 있는 곳)
//	for (int i = 0; i < 8; i++) {
//		//이동할 행과 열 저장
//		int nc = c + kc[i];
//		int nr = r + kr[i];
//		//이동한 행과 열이 맵안에 있고 빈칸이라면 -1 표시
//		if (nc >= 0 && nc < n && nr >= 0 && nr < m && map[nc][nr] == 0) {
//			map[nc][nr] = -1;
//		}
//	}
//
//}
//
//void queen(int c, int r) {
//	//사방 탐색(8방인데 4개 반대가 4개이므로)
//	for (int i = 0; i < 4; i++) {
//		//현재 행과 열 정보와 방향 정보를 가지고 함수 이동
//		move(c, r, i);
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int qn, x, y, kn, pn;
//
//
//	cin >> n >> m;
//	cin >> qn;
//	//퀸을 1로 맵에 표시
//	for (int i = 0; i < qn; i++) {
//		cin >> x >> y;
//		map[x - 1][y - 1] = 1;
//	}
//	cin >> kn;
//	//나이트를 2로 맵에 표시
//	for (int i = 0; i < kn; i++) {
//		cin >> x >> y;
//		map[x - 1][y - 1] = 2;
//	}
//	cin >> pn;
//	//폰을 3으로 맵에 표시
//	for (int i = 0; i < pn; i++) {
//		cin >> x >> y;
//		map[x - 1][y - 1] = 3;
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			//퀸을 만나면 함수 이동
//			if (map[i][j] == 1) {
//				queen(i, j);
//			}
//			//나이트를 만나면 함수 이동
//			if (map[i][j] == 2) {
//				knight(i, j);
//			}
//		}
//	}
//
//	//빈칸의 갯수 세기
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (map[i][j] == 0) {
//				answer++;
//			}
//		}
//	}
//
//	cout << answer << "\n";
//
//	return 0;
//}