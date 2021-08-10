//#include<iostream>
//
//using namespace std;
//
//char map[200][200];
//int R, C, N;
//int dc[4] = {-1,0,1,0};
//int dr[4] = {0,1,0,-1};
//
//void bomb(char c) {
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			//현재 시간에 터질 폭탄이 있으면
//			if (map[i][j] == c) {
//				map[i][j] = '.'; //빈칸으로 만들어 주고 사방 탐색
//				for (int k = 0; k < 4; k++) {
//					int nc = i + dc[k];
//					int nr = j + dr[k];
//					//맵안에 있고 현재 시간에 터질 폭탄이 아니라면(현재 시간에 터질 폭탄을 사방 탐색에 터트리면 그 위치에서 사방 탐색을 할 수 없음)
//					if (nc >= 0 && nc < R && nr >= 0 && nr < C && map[nc][nr] != c) {
//						map[nc][nr] = '.'; //빈칸으로 만들어줌
//					}
//				}
//			}
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> R >> C >> N;
//
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			cin >> map[i][j];
//			//맨처음 폭탄은 3초뒤에 터지므로 3표시
//			if (map[i][j] == 'O') {
//				map[i][j] = '3';
//			}
//		}
//	}
//
//	for (int k = 2; k <= N; k++) {
//		//짝수 시간에는 폭탄을 설치
//		if (k % 2 == 0) {
//			for (int i = 0; i < R; i++) {
//				for (int j = 0; j < C; j++) {
//					//빈칸이면
//					if (map[i][j] == '.') {
//						map[i][j] = char((k+3) + '0'); //현재 시간에서 3초 뒤에 터지는 폭탄을 표시
//					}
//				}
//			}
//		}
//		//홀수 시간에는 폭파
//		else {
//			bomb(char(k + '0')); //현재 시간을 인자로 가지고 감
//		}
//	}
//	//빈칸이 아닌경우에는 모두 폭탄이므로 'O'로 다시 표기 후 출력
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			if (map[i][j] != '.') {
//				map[i][j] = 'O';
//			}
//			cout << map[i][j];
//		}
//		cout << "\n";
//	}
//
//	return 0;
//}