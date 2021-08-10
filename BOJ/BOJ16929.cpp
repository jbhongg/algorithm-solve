//#include<iostream>
//
//using namespace std;
//
//int N, M;
//char map[50][50];
//bool visit[50][50];
//int dc[4] = { -1,0,1,0 };
//int dr[4] = { 0,1,0,-1 };
//bool flag;
//
////현재위치, 탐색 횟수, 이전 위치
//void solve(int c, int r, int cnt, int bc, int br) {
//	//사이클이 있으면 종료
//	if (flag) {
//		return;
//	}
//
//	visit[c][r] = true; //현재 위치 방문 표시
//
//	//4방 탐색
//	for(int i = 0; i < 4; i++) {
//		int nc = c + dc[i];
//		int nr = r + dr[i];
//		//탐색할 위치가 맵안에 있으면
//		if (nc >=0 && nr >= 0 && nc < N && nr < M) {
//			//탐색위치의 색이 현재 위치의 색과 다르면 다음 진행
//			if (map[c][r] != map[nc][nr]) {
//				continue;
//			}
//			//탐색위치의 색이 현재 위치의 색과 같고 방문하지 않았으면
//			if (!visit[nc][nr]) {
//				solve(nc, nr, cnt + 1, c, r); //재귀
//
//			}
//			//탐색위치의 색이 현재 위치의 색과 같은데 방문했던 곳이고 탐색횟수가 4이상이면
//			else if (visit[nc][nr] && cnt >= 4) {
//				//탐색 위치가 바로이전에 방문한 위치면 다음 진행
//				if (nc == bc && nr == br) {
//					continue;
//				}
//				//아니면 사이클 생성 표시 후 종료
//				flag = true;
//				return;
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
//	cin >> N >> M;
//
//	string answer = "No";
//
//	for (int i = 0; i < N; i++) {
//		string s;
//		cin >> s;
//		for (int j = 0; j < s.size(); j++) {
//			map[i][j] = s[j];
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			//방문하지 않았으면
//			if (!visit[i][j]) {
//				solve(i, j, 1, i, j);
//				//사이클이 있으면 "Yes" 출력 후 종료
//				if (flag) {
//					answer = "Yes";
//					cout << answer << "\n";
//					return 0;
//				}
//			}
//		}
//	}
//
//	cout << answer << "\n"; //사이클이 없으면 "No" 출력
//
//	return 0;
//}