//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int before_map[30][30];
//int after_map[30][30];
//int N, M;
//int dc[4] = {-1,0,1,0};
//int dr[5] = {0,1,0,-1};
//int cnt = 0, temp = 0, temp2 = 0;;
//bool visit[30][30];
//bool flag;
//vector <pair <int, int> > v;
//
//void label(int c, int r, int num) {
//	visit[c][r] = true;
//	v.push_back(make_pair(c, r));
//	for (int i = 0; i < 4; i++) {
//		int nc = c + dc[i];
//		int nr = r + dr[i];
//		if (nc < 0 || nc >= N || nr < 0 || nr >= M || visit[nc][nr] || before_map[nc][nr] != num) {
//			continue;
//		}
//		label(nc, nr, num);
//	}
//}
//
//void check(int c, int r, int before_num, int after_num) {
//	temp2++;
//	for (int i = 0; i < v.size(); i++) {
//		if (after_map[v.at(i).first][v.at(i).second] != after_num) {
//			v.clear();
//			flag = true;
//			return;
//		}
//	}
//	if (before_num == after_num) {
//		temp++;
//	}
//	else {
//		cnt++;
//	}
//	v.clear();
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> before_map[i][j];
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> after_map[i][j];
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (!visit[i][j]) {
//				label(i, j, before_map[i][j]);
//				check(i, j, before_map[i][j], after_map[i][j]);
//				if (cnt == 2 || flag) {
//					cout << "NO" << "\n";
//					return 0;
//				}
//			}
//		}
//	}
//
//	if (cnt == 0 && temp != temp2) {
//		cout << "NO" << "\n";
//	}
//	else {
//		cout << "YES" << "\n";
//	}
//
//	return 0;
//}