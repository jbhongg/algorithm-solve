//#include<iostream>
//
//using namespace std;
//
//int b[6][5];
//int g[6][5];
//int answer;
//
//void b_move(int idx, int cnt) {
//	//터진 행만큼 블록들 아래로 이동
//	for (int i = idx - 1; i >= 0; i--) {
//		for (int j = 0; j < 5; j++) {
//			b[i + cnt][j] = b[i][j];
//			b[i][j] = 0;
//		}
//	}
//}
//
//void b_move_check() {
//	int cnt = 0;
//	//0번행과 1번 행에 블록이 있는지 확인
//	for (int i = 0; i <= 1; i++) {
//		for (int j = 0; j < 5; j++) {
//			if (b[i][j] != 0) {
//				cnt++;
//				break;
//			}
//		}
//	}
//	//0번행과 1번 행에 블록이 있으면 있는 행만큼 블록들 아래로 이동
//	if (cnt != 0) {
//		b_move(6 - cnt, cnt);
//	}
//}
//
//void b_bomb_check() {
//	int cnt = 0;
//	int last = -1;
//	for (int i = 5; i >= 2; i--) {
//		int line = 0;
//		for (int j = 0; j < 5; j++) {
//			if (b[i][j] != 0) {
//				line++;
//			}
//		}
//		//터트릴 블록이 있으면 터트리기
//		if (line == 4) {
//			cnt++;
//			last = i;
//			for (int j = 0; j < 5; j++) {
//				b[i][j] = 0;
//			}
//			answer++;
//		}
//	}
//	//터진 블록이 있으면
//	if (last != -1) {
//		b_move(last, cnt);
//	}
//	b_move_check();
//}
//
//void g_move(int idx, int cnt) {
//	//터진 행만큼 블록들 아래로 이동
//	for (int i = idx - 1; i >= 0; i--) {
//		for (int j = 0; j < 5; j++) {
//			g[i + cnt][j] = g[i][j];
//			g[i][j] = 0;
//		}
//	}
//}
//
//void g_move_check() {
//	int cnt = 0;
//	//0번행과 1번 행에 블록이 있는지 확인
//	for (int i = 0; i <= 1; i++) {
//		for (int j = 0; j < 5; j++) {
//			if (g[i][j] != 0) {
//				cnt++;
//				break;
//			}
//		}
//	}
//	//0번행과 1번 행에 블록이 있으면 있는 행만큼 블록들 아래로 이동
//	if (cnt != 0) {
//		g_move(6 - cnt, cnt);
//	}
//}
//
//void g_bomb_check() {
//	int cnt = 0;
//	int last = -1;
//	for (int i = 5; i >= 2; i--) {
//		int line = 0;
//		for (int j = 0; j < 5; j++) {
//			if (g[i][j] != 0) {
//				line++;
//			}
//		}
//		//터트릴 블록이 있으면 터트리기
//		if (line == 4) {
//			cnt++;
//			last = i;
//			for (int j = 0; j < 5; j++) {
//				g[i][j] = 0;
//			}
//			answer++;
//		}
//	}
//	//터진 블록이 있으면
//	if (last != -1) {
//		g_move(last, cnt);
//	}
//	g_move_check();
//}
//
//void green(int t, int c, int r) {
//	//1×1인 블록일떄
//	if (t == 1) {
//		//블록 떨어트리기
//		for (int i = 0; i < 6; i++) {
//			if (g[i][r] != 0) {
//				g[i - 1][r] = 1;
//				break;
//			}
//			if (i == 5) {
//				g[5][r] = 1;
//			}
//		}
//		g_bomb_check(); 
//	}
//	// 1×2인 블록일 떄
//	else if (t == 2) {
//		//블록 떨어트리기
//		for (int i = 0; i < 6; i++) {
//			if (g[i][r] != 0 || g[i][r+1] != 0) {
//				g[i - 1][r] = 2;
//				g[i - 1][r + 1] = 2;
//				break;
//			}
//			if (i == 5) {
//				g[5][r] = 2;
//				g[5][r+1] = 2;
//			}
//		}
//		g_bomb_check();
//	}
//	//2×1인 블록일 떄
//	else if (t == 3) {
//		//블록 떨어트리기
//		for (int i = 0; i < 5; i++) {
//			if (g[i][r] != 0 || g[i+1][r] != 0) {
//				g[i - 1][r] = 3;
//				g[i][r] = 3;
//				break;
//			}
//			if (i == 4) {
//				g[4][r] = 3;
//				g[5][r] = 3;
//			}
//		}
//		g_bomb_check();
//	}
//}
//
//void blue(int t, int c, int r) {
//	//1×1인 블록일떄
//	if (t == 1) {
//		//블록 떨어트리기
//		for (int i = 0; i < 6; i++) {
//			if (b[i][r] != 0) {
//				b[i - 1][r] = 1;
//				break;
//			}
//			if (i == 5) {
//				b[5][r] = 1;
//			}
//		}
//		b_bomb_check();
//	}
//	// 1×2인 블록일 떄
//	else if (t == 2) {
//		//블록 떨어트리기
//		for (int i = 0; i < 5; i++) {
//			if (b[i][r] != 0 || b[i + 1][r] != 0) {
//				b[i - 1][r] = 2;
//				b[i][r] = 2;
//				break;
//			}
//			if (i == 4) {
//				b[4][r] = 2;
//				b[5][r] = 2;
//			}
//		}
//		b_bomb_check();
//	}
//	//2×1인 블록일 떄
//	else if (t == 3) {
//		//블록 떨어트리기
//		for (int i = 0; i < 6; i++) {
//			if (b[i][r] != 0 || b[i][r + 1] != 0) {
//				b[i - 1][r] = 3;
//				b[i - 1][r + 1] = 3;
//				break;
//			}
//			if (i == 5) {
//				b[5][r] = 3;
//				b[5][r + 1] = 3;
//			}
//		}
//		b_bomb_check();
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	int N, cnt = 0;
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		int t, x, y;
//		cin >> t >> x >> y;
//		green(t,x,y); //초록색 보드
//		blue(t, y, x); //파란색 보드(x와 y를 반대로)
//	}
//
//	//남은 블록 세주기
//	for (int i = 2; i < 6; i++) {
//		for (int j = 0; j < 4; j++) {
//			if (b[i][j] != 0) {
//				cnt++;
//			}
//			if (g[i][j] != 0) {
//				cnt++;
//			}
//		}
//	}
//	
//	cout << answer << "\n" << cnt << "\n";
//	return 0;
//}