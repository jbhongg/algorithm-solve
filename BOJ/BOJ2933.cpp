//#include<iostream>
//
//using namespace std;
//
//char map[100][100], temp[100][100];
//int R, C, N;
//int dc[4] = { -1,0,1,0 };
//int dr[4] = { 0,1,0,-1 };
//bool visit[100][100];
//
//void init() {
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			visit[i][j] = false;
//		}
//	}
//}
//
//void back() {
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			map[i][j] = temp[i][j];
//		}
//	}
//}
//
//void cop() {
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			temp[i][j] = map[i][j];
//		}
//	}
//}
//
//void move(int n) {
//	//라벨링 번호만큼 탐색
//	for (int k = 1; k < n; k++) {
//		bool flag = false;
//		while (!flag) {
//			//아래서부터 탐색
//			for (int i = R - 1; i >= 0; i--) {
//				for (int j = 0; j < C; j++) {
//					//현재 위치가 현재 라벨 번호라면
//					if (map[i][j] == (char)k) {
//						//현재 위치보다 하나 아래 행이 맵 바깥이면 종료 후 다음 라벨 탐색
//						if (i + 1 < 0 || i + 1 >= R) {
//							flag = true; 
//							break;
//						}
//						//현재 위치보다 하나 아래 행이 맵 안에 있으면
//						else {
//							//아래 행이 빈칸이라면
//							if (map[i + 1][j] == '.') {
//								//현재 값을 아래 행으로 이동
//								map[i + 1][j] = map[i][j];
//								map[i][j] = '.'; //현재 위치를 빈칸으로 바꿔줌
//							}
//							//아래 행이 빈칸이 아니면 종료 후 다음 라벨 탐색
//							else {
//								flag = true;
//								break;
//							}
//						}
//					}
//
//				}
//				//이동이 불가능하여 현재 라벨 탐색 종료이면
//				if (flag) {
//					back(); //맵 원상복귀
//					break;
//				}
//			}
//			//현재 라벨의 모든 미네랄이 이동이 가능하면
//			if (!flag) {
//				cop(); //temp 배열에 현재 맵 복사
//			}
//		}
//
//	}
//}
//
//void dfs(int c, int r, int num) {
//	//4방탐색
//	for (int i = 0; i < 4; i++) {
//		int nc = c + dc[i];
//		int nr = r + dr[i];
//		//탐색한 위치가 맵 안에 있고 방문하지 않았던 곳이고 미네랄이라면
//		if (nc >= 0 && nc < R && nr >= 0 && nr < C && map[nc][nr] != '.' && visit[nc][nr] == false) {
//			visit[c][r] = true;     //방문했다고 표시
//			map[c][r] = (char)num;  //해당 위치를 현재 라벨링 번호 라벨링
//			temp[c][r] = (char)num;
//			dfs(nc, nr, num);
//		}
//	}
//	visit[c][r] = true;    //현재 위치를 방문했다고 표시
//	map[c][r] = (char)num; //해당 위치를 현재 라벨링 번호 라벨링
//	temp[c][r] = (char)num;
//
//}
//
//void label() {
//	int num = 1; //라벨링 시작 번호
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			//미네랄을 발견했고 라벨링 되지 않은 것이라면
//			if (map[i][j] != '.' && visit[i][j] == false) {
//				dfs(i, j, num++);
//			}
//		}
//	}
//	move(num);
//}
//
//void bomb(int dir, int h) {
//	//왼쪽일 경우
//	if (dir == 1) {
//		for (int i = 0; i < C; i++) {
//			//미네랄을 발견하면
//			if (map[R - h][i] != '.') {
//				map[R - h][i] = '.'; //미네랄을 빈칸으로 만들어줌
//				temp[R - h][i] = '.';
//				break;
//			}
//		}
//		label();
//	}
//	//오른쪽일 경우
//	else if (dir == 2) {
//		for (int i = C-1; i >= 0; i--) {
//			//미네랄을 발견하면
//			if (map[R - h][i] != '.') {
//				map[R - h][i] = '.'; //미네랄을 빈칸으로 만들어줌
//				temp[R - h][i] = '.';
//				break;
//			}
//		}
//		label();
//	}
// }
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> R >> C;
//
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			cin >> map[i][j];
//			temp[i][j] = map[i][j];
//		}
//	}
//
//	cin >> N;
//
//	for (int i = 1; i <= N; i++) {
//		int h;
//		cin >> h;
//		init(); //visit 배열 초기화
//		if (i % 2 == 1) {
//			bomb(1, h); //왼쪽에서 막대를 던지는 경우
//		}
//		else {
//			bomb(2, h); //오른쪽에서 막대를 던지는 경우
//		}
//
//	}
//
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			//빈칸이 아니라면 미네랄이므로
//			if (map[i][j] != '.') {
//				map[i][j] = 'x'; //미네랄 표시를 x로 다시 바꿔줌
//			}
//			cout << map[i][j];
//		}
//		cout << "\n";
//	}
//	
//	return 0;
//}