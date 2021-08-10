//#include<iostream>
//
//using namespace std;
//
//int N, answer = 0;
//bool visit[15][15];
//
//void check(int c, int r) {
//	for (int i = 0; i < N; i++) {
//		visit[c][i] = true;
//		visit[i][r] = true;
//	}
//
//	int n = 1;
//
//	while (true) {
//		if (c + n >= N || r + n >= N) {
//			break;
//		}
//		visit[c + n][r + n] = true;
//		n++;
//		
//	}
//	n = 1;
//	while (true) {
//		if (c - n < 0 || r - n < 0) {
//			break;
//		}
//		visit[c - n][r - n] = true;
//		n++;
//
//	}
//	n = 1;
//	while (true) {
//		if (c + n >= N || r - n < 0) {
//			break;
//		}
//		visit[c + n][r - n] = true;
//		n++;
//
//	}
//	n = 1;
//	while (true) {
//		if (c - n < 0 || r + n >= N) {
//			break;
//		}
//		visit[c - n][r + n] = true;
//		n++;
//
//	}
//
//}
//
//void solve(int k) {
//	bool temp[15][15];
//
//	if (k == N) {
//		answer++;
//		return;
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			temp[i][j] = visit[i][j];
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (!visit[i][j]) {
//				check(i, j);
//				solve(k + 1);
//				for (int i = 0; i < N; i++) {
//					for (int j = 0; j < N; j++) {
//						visit[i][j] = temp[i][j];
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
//	cin >> N;
//
//	solve(0);
//	cout << answer << "\n";
//
//	return 0;
//}