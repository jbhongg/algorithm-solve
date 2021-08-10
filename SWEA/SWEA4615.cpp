//#include<iostream>
//
//using namespace std;
//
//bool change = false; //바둑돌을 바꿀지 말지 정하는 변수
//int map[8][8];
//int N;
//int dc[8] = { -1,-1,0,1,1,1,0,-1 };
//int dr[8] = { 0,1,1,1,0,-1,-1,-1 };
//
//void go(int nc, int nr, int d, int type, int c) {
//	nc = nc + dc[d];
//	nr = nr + dr[d];
//
//	//다음 칸이 맵을 벗어나지 않고 같은 색의 바둑돌이라면 한칸 더 진행
//	if (nc >= 0 && nc < N && nr >= 0 && nr < N && map[nc][nr] == type) {
//		go(nc, nr, d, type, c);
//		//지금까지 탐색했던 바둑돌 바꾸기
//		if (change == true) {
//			map[nc][nr] = c;
//		}
//	}
//	//다음 칸이 맵을 벗어나지 않고 처음에 놓은 색의 바둑돌이라면 탐색 종료
//	else if (nc >= 0 && nc < N && nr >= 0 && nr < N && map[nc][nr] == c) {
//		change = true;
//		return;
//	}
//	//다음 칸이 맵을 벗어나거나 빈칸인 경우 종료
//	else
//		return;
//
//}
//
//// 놓은 바둑돌 주변 8방에 다른색 바둑돌이 있는지 체크
//void check(int column, int row, int type) {
//	//순서대로 팔방 탐색
//	for (int i = 0; i < 8; i++) {
//		int nc = column + dc[i];
//		int nr = row + dr[i];
//		//다른색의 바둑돌이 있다면 그 방향으로 계속 탐색하기 위해 함수에 들어감
//		if (type == 1 && map[nc][nr] == 2) {
//			go(nc, nr, i, 2, 1);
//			if (change == true) {
//				map[nc][nr] = 1;
//			}
//			change = false;
//		}
//		else if (type == 2 && map[nc][nr] == 1) {
//			go(nc, nr, i, 1, 2);
//			if (change == true) {
//				map[nc][nr] = 2;
//			}
//			change = false;
//		}
//	}
//}
//
//void init() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			map[i][j] = 0;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int test_case, T;
//	cin >> T;
//
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		int M, row, column, type, black = 0, white = 0;
//		cin >> N >> M;
//
//		init(); //맵 초기화
//		map[N / 2 - 1][N / 2 - 1] = 2;
//		map[N / 2 - 1][N / 2] = 1;
//		map[N / 2][N / 2 - 1] = 1;
//		map[N / 2][N / 2] = 2;
//
//		for (int i = 0; i < M; i++) {
//			cin >> row >> column >> type;
//			map[column - 1][row - 1] = type;
//			check(column - 1, row - 1, type);
//		}
//
//		//바둑돌 세기
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				if (map[i][j] == 1) {
//					black++;
//				}
//				else if (map[i][j] == 2) {
//					white++;
//				}
//			}
//		}
//		cout << "#" << test_case << " " << black << " " << white << "\n";
//	}
//
//	return 0;
//}