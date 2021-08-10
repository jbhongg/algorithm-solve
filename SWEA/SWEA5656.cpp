//#include<iostream>
//#include<queue>
//#include<algorithm>
//#include<limits.h>
//
//using namespace std;
//
//queue <pair <pair <int, int>, int>> q;
//
//int map[15][12];
//int temp[15][12];
//int ball[4];
//int test_case, T, N, W, H, answer;
//int dc[4] = {-1,0,1,0};
//int dr[4] = {0,1,0,-1};
//bool visit[15][12];
//
//void init_bool() {
//	for (int i = 0; i < H; i++) {
//		for (int j = 0; j < W; j++) {
//			visit[i][j] = false;
//		}
//	}
//}
//
//void init() {
//	for (int i = 0; i < H; i++) {
//		for (int j = 0; j < W; j++) {
//			temp[i][j] = map[i][j];
//		}
//	}
//}
//
//void count() {
//	int count = 0;
//	for (int i = 0; i < H; i++) {
//		for (int j = 0; j < W; j++) {
//			if (temp[i][j] != 0) {
//				count++;
//			}
//		}
//	}
//	answer = min(answer, count);
//}
//
//void move() {
//	for (int j = 0; j < W; j++) {
//		for (int i = H - 1; i > 0; i--) {
//			if (temp[i][j] == 0) {
//				int k = i - 1;
//				while (temp[k][j] == 0) {
//					k--;
//					if (k < 0) {
//						break;
//					}
//				}
//				if (k >= 0) {
//					temp[i][j] = temp[k][j];
//					temp[k][j] = 0;
//				}
//				else {
//					break;
//				}
//			}
//		}
//	}
//}
//
//void bfs() {
//	while (!q.empty()) {
//		int c = q.front().first.first;
//		int r = q.front().first.second;
//		if (q.front().second != 0 && q.front().second != 1) {
//			for (int i = 1; i <= (q.front().second - 1); i++) {
//				for (int j = 0; j <4; j++) {
//					int nc = c + (dc[j]*i);
//					int nr = r + (dr[j]*i);
//					if (nc >= 0 && nc < H && nr >= 0 && nr < W && temp[nc][nr] != 0 && visit[nc][nr] == false) {
//						q.push(make_pair(make_pair(nc, nr),temp[nc][nr]));
//						visit[nc][nr] = true;
//					}
//				}
//			}
//			temp[c][r] = 0;
//			q.pop();
//		}
//		else if (q.front().second == 1) {
//			temp[c][r] = 0;
//			q.pop();
//		}
//	}
//}
//
//void bomb() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < H; j++) {
//			if (temp[j][ball[i]] != 0) {
//				q.push(make_pair(make_pair(j,ball[i]),temp[j][ball[i]]));
//				bfs();
//				move();
//				init_bool();
//				break;
//			}
//		}
//	}
//}
//
//void solve(int k) {
//	if (answer == 0) {
//		return;
//	}
//	if (k == N) {
//		bomb();
//		count();
//		init();
//		return;
//	}
//
//	for (int i = 0; i < W; i++) {
//		ball[k] = i;
//		solve(k + 1);
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> T;
//
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		answer = INT_MAX;
//		cin >> N >> W >> H;
//		for (int i = 0; i < H; i++) {
//			for (int j = 0; j < W; j++) {
//				cin >> map[i][j];
//				temp[i][j] = map[i][j];
//			}
//		}
//
//		solve(0);
//
//		cout << "#" << test_case << " " << answer << '\n';
//	}
//
//	return 0;
//}