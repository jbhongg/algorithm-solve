//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<utility>
//
//using namespace std;
//
//int N, M;
//int cnt = 0;
//int minn = 64;
//int cctv = 0;
//int office[8][8], temp[8][8];
//vector <pair <pair <int, int>, pair<int, int> > > info;
//
//int reset() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			temp[i][j] = office[i][j];
//		}
//	}
//
//	return 0;
//}
//
//int east(int x, int y) {
//	int b = y;
//	while (y < M - 1) {
//		y++;
//		if (temp[x][y] == 6) {
//			break;
//		}
//		else if (temp[x][y] == 0) {
//			temp[x][y] = -1;
//		}
//	}
//	y = b;
//
//	return 0;
//}
//
//int west(int x, int y) {
//	int b = y;
//	while (y > 0) {
//		y--;
//		if (temp[x][y] == 6) {
//			break;
//		}
//		else if (temp[x][y] == 0) {
//			temp[x][y] = -1;
//		}
//	}
//	y = b;
//
//	return 0;
//}
//
//int south(int x, int y) {
//	int a = x;
//	while (x < N - 1) {
//		x++;
//		if (temp[x][y] == 6) {
//			break;
//		}
//		else if (temp[x][y] == 0) {
//			temp[x][y] = -1;
//		}
//	}
//	x = a;
//
//	return 0;
//}
//
//int north(int x, int y) {
//	int a = x;
//	while (x > 0) {
//		x--;
//		if (temp[x][y] == 6) {
//			break;
//		}
//		else if (temp[x][y] == 0) {
//			temp[x][y] = -1;
//		}
//	}
//	x = a;
//
//	return 0;
//}
//
//int check() {
//	reset();
//	for (int i = 0; i < cctv; i++) {
//		if (info[i].second.first == 1) {
//			if (info[i].second.second == 0) {
//				east(info[i].first.first, info[i].first.second);
//			}
//			else if (info[i].second.second == 1) {
//				west(info[i].first.first, info[i].first.second);
//			}
//			else if (info[i].second.second == 2) {
//				south(info[i].first.first, info[i].first.second);
//			}
//			else if (info[i].second.second == 3) {
//				north(info[i].first.first, info[i].first.second);
//			}
//
//		}
//		else if (info[i].second.first == 2) {
//			if (info[i].second.second == 0 || info[i].second.second == 1) {
//				east(info[i].first.first, info[i].first.second);
//				west(info[i].first.first, info[i].first.second);
//			}
//			else if (info[i].second.second == 2 || info[i].second.second == 3) {
//				south(info[i].first.first, info[i].first.second);
//				north(info[i].first.first, info[i].first.second);
//			}
//
//		}
//		else if (info[i].second.first == 3) {
//			if (info[i].second.second == 0) {
//				east(info[i].first.first, info[i].first.second);
//				north(info[i].first.first, info[i].first.second);
//			}
//			else if (info[i].second.second == 1) {
//				west(info[i].first.first, info[i].first.second);
//				south(info[i].first.first, info[i].first.second);
//			}
//			else if (info[i].second.second == 2) {
//				south(info[i].first.first, info[i].first.second);
//				east(info[i].first.first, info[i].first.second);
//			}
//			else if (info[i].second.second == 3) {
//				north(info[i].first.first, info[i].first.second);
//				west(info[i].first.first, info[i].first.second);
//			}
//
//		}
//		else if (info[i].second.first == 4) {
//			if (info[i].second.second == 0) {
//				east(info[i].first.first, info[i].first.second);
//				west(info[i].first.first, info[i].first.second);
//				north(info[i].first.first, info[i].first.second);
//			}
//			else if (info[i].second.second == 1) {
//				west(info[i].first.first, info[i].first.second);
//				east(info[i].first.first, info[i].first.second);
//				south(info[i].first.first, info[i].first.second);
//			}
//			else if (info[i].second.second == 2) {
//				south(info[i].first.first, info[i].first.second);
//				north(info[i].first.first, info[i].first.second);
//				west(info[i].first.first, info[i].first.second);
//			}
//			else if (info[i].second.second == 3) {
//				south(info[i].first.first, info[i].first.second);
//				north(info[i].first.first, info[i].first.second);
//				east(info[i].first.first, info[i].first.second);
//			}
//
//		}
//		else if (info[i].second.first == 5) {
//			east(info[i].first.first, info[i].first.second);
//			west(info[i].first.first, info[i].first.second);
//			south(info[i].first.first, info[i].first.second);
//			north(info[i].first.first, info[i].first.second);
//		}
//	}
//
//	return 0;
//}
//
//int cal() {
//	int result = 0;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (temp[i][j] == 0) {
//				result++;
//			}
//		}
//	}
//
//	return result;
//}
//
//int solve(int count) {
//	if (count == cctv) {
//		check();
//		minn = min(minn, cal());
//		return 0;
//	}
//
//	info[count].second.second = 0;
//	solve(count + 1);
//
//	info[count].second.second = 1;
//	solve(count + 1);
//
//	info[count].second.second = 2;
//	solve(count + 1);
//
//	info[count].second.second = 3;
//	solve(count + 1);
//
//
//	return 0;
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
//			cin >> office[i][j];
//			if (office[i][j] != 0 && office[i][j] != 6) {
//				info.push_back(make_pair(make_pair(i, j), make_pair(office[i][j], -1)));
//				cctv++;
//			}
//		}
//	}
//
//	solve(0);
//
//	cout << minn << "\n";
//
//	return 0;
//}