//#include<iostream>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//
//int N, M;
//int answer, safe, cnt;
//int map[8][8];
//int temp[8][8];
//int dc[4] = { -1,0,1,0 };
//int dr[4] = { 0,1,0,-1 };
//bool flag;
//
//void init() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			temp[i][j] = map[i][j];
//		}
//	}
//}
//
//void solve() {
//	safe = 0;
//	queue <pair<int, int>> q;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			//바이러스면 큐에 저장
//			if (temp[i][j] == 2) {
//				q.push(make_pair(i, j));
//			}
//			//빈칸의 수 세기
//			if (temp[i][j] == 0) {
//				safe++;
//			}
//		}
//	}
//
//	while (!q.empty())
//	{
//		int c = q.front().first;
//		int r = q.front().second;
//		q.pop();
//		//4방 탐색
//		for (int k = 0; k < 4; k++) {
//			int nc = c + dc[k];
//			int nr = r + dr[k];
//			//탐색한 위치가 맵 안에 있고 빈칸이라면
//			if (nc >= 0 && nc < N && nr >= 0 && nr < M && temp[nc][nr] == 0) {
//				temp[nc][nr] = 2;  //탐색 위치에 바이러스 확산
//				q.push(make_pair(nc, nr)); //큐에 현재 위치 추가
//				safe--; //0의 갯수 하나 감소
//			}
//		}
//	}
//}
//
//void wall(int cnt) {
//	//벽을 다 세웠으면
//	if (cnt == 3) {
//		init(); //temp배열 초기화
//		solve();
//		answer = max(safe, answer); //최댓값 저장
//		return;
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			//빈칸이면
//			if (map[i][j] == 0) {
//				//벽을 세움
//				map[i][j] = 1;
//				wall(cnt+1); //재귀
//				//원상 복귀
//				map[i][j] = 0;
//			}
//		}
//	}
//}
//
//int main() {
//
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	wall(0);
//	cout << answer << "\n";
//	return 0;
//}