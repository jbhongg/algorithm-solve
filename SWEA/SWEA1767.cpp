//#include <iostream>
//#include <vector>
//#include<limits.h>
//
//using namespace std;
//
//int map[12][12];
//vector <pair <pair <int, int>, int> > core;
//int dc[4] = { -1,0,1,0 };
//int dr[4] = { 0,1,0,-1 };
//int N, wn;
//vector <int> sel;
//vector <pair <int, int>> answer;
//
//int core_count() {
//	int count = 0;
//	for (int i = 0; i < core.size(); i++) {
//		if (core.at(i).second == 1) {
//			count++;
//		}
//	}
//
//	return count;
//}
//
//int wire(int c, int r, int dir) {
//	int count = 1;
//	int nc = c;
//	int nr = r;
//	while (true) {
//		nc = nc + dc[dir];
//		nr = nr + dr[dir];
//		//맵안에 있으면
//		if (nc >= 0 && nc < N && nr >= 0 && nr < N) {
//			//빈칸이라면
//			if (map[nc][nr] == 0) {
//				count++; //전선 하나 증가
//			}
//			//빈칸이 아니라면
//			else {
//				count = 0; //전선갯수를 0으로하고 탈출
//				break;
//			}
//		}
//		//맵밖으로 나가면 탈출
//		else {
//			break;
//		}
//	}
//
//	return count;
//}
//
//void solve(int k, int n) {
//	//최대라고 저장된 코어 수가 코어 전체수와 같고 현재 전선의 수가 최소라고 저장된 전선의 수보다 크건 같으면 종료
//	if (answer.front().first == core.size() && n >= answer.front().second) {
//		return;
//	}
//	//코어를 모두 봤으면
//	if (k == core.size()) {
//		int core_n = core_count(); //전원에 연결된 코어 갯수 세기
//		//최대라고 저장된 코어 수와 현재 전원에 연결된 코어 수와 같다면
//		if (answer.front().first == core_n) {
//			//최소라고 저장된 전선의 수보다 현재 전선의 수가 작으면
//			if (answer.front().second > n) {
//				answer.front().second = n; //현재 전선의 수 저장
//			}
//		}
//		//최대라고 저장된 코어 수보다 현재 전원에 연결된 코어 수가 크다면
//		else if (answer.front().first < core_n) {
//			answer.front().first = core_n; //현재 코어의 수 저장
//			answer.front().second = n; //현재 전선의 수 저장
//		}
//		return;
//	}
//	int c = core.at(k).first.first;
//	int r = core.at(k).first.second;
//	//4방 탐색
//	for (int j = 0; j < 4; j++) {
//		int nc = c + dc[j];
//		int nr = r + dr[j];
//		//맵안에 있고 탐색한 칸이 빈칸이면
//		if (nc >= 0 && nc < N && nr >= 0 && nr < N && map[nc][nr] == 0) {
//			int temp = wire(nc, nr, j); //전선을 깔수 있는지 확인
//			//전선을 깔수 있으면
//			if (temp != 0) {
//				core.at(k).second = 1; //현재 코어가 전원이 연결되었다고 표시
//				int tc = nc;
//				int tr = nr;
//				map[tc][tr] = 2; 
//				//맵에 전선을 깜
//				for (int q = 0; q < temp - 1; q++) {
//					tc = tc + dc[j];
//					tr = tr + dr[j];
//					map[tc][tr] = 2;
//				}
//				solve(k + 1, n + temp); 
//				core.at(k).second = 0; //코어 전원 연결해제
//				tc = nc;
//				tr = nr;
//				map[tc][tr] = 0;
//				//전선 회수
//				for (int q = 0; q < temp - 1; q++) {
//					tc = tc + dc[j];
//					tr = tr + dr[j];
//					map[tc][tr] = 0;
//				}
//			}
//			//전선을 깔수 없으면
//			else if (temp == 0 && j == 3) {
//				solve(k + 1, n + temp);
//			}
//		}
//	}
//	
//	
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int T;
//	cin >> T;
//	for (int test_case = 1; test_case <= T; test_case++)
//	{
//		cin >> N;
//		answer.clear();
//		core.clear();
//		answer.push_back(make_pair(-1, INT_MAX));
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				cin >> map[i][j];
//				//맨 가장자리에 있는 코어를 제외하고 코어를 벡터에 모두 저장
//				if (i != 0 && i != N - 1 && j != 0 && j != N - 1 && map[i][j] == 1) {
//					core.push_back(make_pair(make_pair(i, j), 0));
//				}
//			}
//		}
//		solve(0, 0);
//
//		//전선을 하나도 깔수 없을 때 0출력
//		if (answer.front().first == -1) {
//			answer.front().second = 0;
//		}
//
//		cout << "#" << test_case << " " << answer.front().second << "\n";
//	}
//	return 0;
//}