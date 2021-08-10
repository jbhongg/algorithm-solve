//#include<iostream>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//
//int N, x;
//int Block[20][20];
//int mem[10];
//
//bool check(int temp[20][20]) {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (temp[i][j] != Block[i][j]) {
//				return false;
//			}
//		}
//			
//	}
//	return true;
//}
//
//void merge(int type) {
//	queue<int> q;
//	int val, col, row;
//
//	switch (type)
//	{
//	case 0:
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				if (Block[j][i] != 0) {
//					q.push(Block[j][i]);
//					Block[j][i] = 0;
//				}
//			}
//			col = 0;
//			while (!q.empty()) {
//				val = q.front();
//				q.pop();
//				if (Block[col][i] == 0) {
//					Block[col][i] = val;
//				}
//				else if (Block[col][i] == val) {
//					Block[col][i] = val * 2;
//					col++;
//				}
//				else {
//					col++;
//					Block[col][i] = val;
//				}
//			}
//		}
//		break;
//
//	case 1:
//		for (int i = 0; i < N; i++) {
//			for (int j = N - 1; j >= 0; j--) {
//				if (Block[j][i] != 0) {
//					q.push(Block[j][i]);
//					Block[j][i] = 0;
//				}
//			}
//			col = N - 1;
//			while (!q.empty()) {
//				val = q.front();
//				q.pop();
//				if (Block[col][i] == 0) {
//					Block[col][i] = val;
//				}
//				else if (Block[col][i] == val) {
//					Block[col][i] = val * 2;
//					col--;
//				}
//				else {
//					col--;
//					Block[col][i] = val;
//				}
//			}
//		}
//		break;
//
//	case 2:
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				if (Block[i][j] != 0) {
//					q.push(Block[i][j]);
//					Block[i][j] = 0;
//				}
//			}
//			row = 0;
//			while (!q.empty()) {
//				val = q.front();
//				q.pop();
//				if (Block[i][row] == 0) {
//					Block[i][row] = val;
//				}
//				else if (Block[i][row] == val) {
//					Block[i][row] = val * 2;
//					row++;
//				}
//				else {
//					row++;
//					Block[i][row] = val;
//				}
//			}
//		}
//		break;
//
//	case 3:
//		for (int i = 0; i < N; i++) {
//			for (int j = N - 1; j >= 0; j--) {
//				if (Block[i][j] != 0) {
//					q.push(Block[i][j]);
//					Block[i][j] = 0;
//				}
//			}
//			row = N - 1;
//			while (!q.empty()) {
//				val = q.front();
//				q.pop();
//				if (Block[i][row] == 0) {
//					Block[i][row] = val;
//				}
//				else if (Block[i][row] == val) {
//					Block[i][row] = val * 2;
//					row--;
//				}
//				else {
//					row--;
//					Block[i][row] = val;
//				}
//			}
//		}
//		break;
//	}
//}
//
//void solve(int cnt) {
//	int temp[20][20];
//	int m = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			m = max(m, Block[i][j]);
//		}
//	}
//
//	if (cnt != 0 && m <= mem[cnt-1]) {
//		return;
//	}
//
//	if (cnt == 10) {
//		x = max(x, m);
//		int temp = x;
//		for (int i = 9; i >= 0; i--) {
//			mem[i] = temp;
//			temp = temp / 2;
//		}
//		return;
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			temp[i][j] = Block[i][j];
//		}
//	}
//
//	for (int k = 0; k < 4; k++) {
//		merge(k);
//		if (check(temp)) {
//			continue;
//		}
//		solve(cnt + 1);
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				Block[i][j] = temp[i][j];
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
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> Block[i][j];
//			x = max(x, Block[i][j]);
//		}
//	}
//	solve(0);
//
//	cout << x << "\n";
//
//	return 0;
//}