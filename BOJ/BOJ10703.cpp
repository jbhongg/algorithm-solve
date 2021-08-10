//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int R, S, air = 0;
//	int meteor = -1;
//	int minn = 1000000;
//	string s;
//
//	cin >> R >> S;
//
//	vector<string> map; //맵을 입력받기위한 변수
//
//	// 맵을 입력받음
//	for (int i = 0; i < R; i++) {
//		string s;
//		cin >> s;
//		map.push_back(s);
//	}
//
//	//맵을 세로로 탐색 
//	for (int i = 0; i < S; i++) {
//		for (int j = 0; j < R; j++) {
//			//가장 아래있는 유성의 위치를 탐색 후 저장
//			if (map[j][i] == 'X' && map[j + 1][i] == '.') {
//				meteor = j;
//			}
//			// 땅 바로 위에 있는 공기의 위치 저장(땅이 없는 경우 마지막 인덱스의 위치 저장)
//			else if (map[j][i] == '.' && j == R - 1 || (map[j][i] == '.' && map[j + 1][i] == '#')) {
//				air = j;
//				break;
//			}
//		}
//		// 유성과 땅의 거리 최솟값을 저장 후 유성의 위치 초기화
//		if (meteor != -1) {
//			minn = min(minn, (air - meteor));
//			meteor = -1;
//		}
//	}
//
//	// 유성들의 위치를 이동(이동한 유성을 탐색하지 않도록 아래서부터 탐색)
//	for (int i = R - 1; i >= 0; i--) {
//		for (int j = 0; j < S; j++) {
//			if (map[i][j] == 'X') {
//				map[i][j] = '.';
//				map[i + minn][j] = 'X';
//			}
//		}
//	}
//
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < S; j++) {
//			cout << map[i][j];
//		}
//		cout << endl;
//	}
//	return 0;
//}