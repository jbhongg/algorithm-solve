//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//
//using namespace std;
//
//int map[20][20];
//vector <pair <int, int>> v;
//vector <pair <int, int>> answer;
//int dc[4] = { -1,0,1,0 };
//int dr[4] = {0,1,0,-1};
//int N, M, result;
//bool visit[20][20];
//
//void init() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			visit[i][j] = false;
//		}
//	}
//}
//
//int bfs(int i, int j) {
//	bool flag = false;
//	int cnt = 1;
//	queue <pair <int, int>> q;
//	q.push(make_pair(i, j));
//	visit[i][j] = true;
//	while (!q.empty()) {
//		int c = q.front().first;
//		int r = q.front().second;
//		q.pop();
//		//4방탐색
//		for (int k = 0; k < 4; k++) {
//			int nc = c + dc[k];
//			int nr = r + dr[k];
//			//맵안에 있고 방문하지 않은 곳이면
//			if (nc >= 0 && nc < N && nr >= 0 && nr < M && visit[nc][nr] == false) {
//				//탐색한 곳에 상대방 돌이 있으면
//				if (map[nc][nr] == 2) {
//					visit[nc][nr] = true; //방문했다고 표시
//					q.push(make_pair(nc, nr)); //큐에 추가
//					cnt++; //돌의 갯수 증가
//				}
//				//탐색한 곳이 빈칸이라면 
//				else if (map[nc][nr] == 0) {
//					flag = true;
//				}
//			}
//		}
//	}
//	//주변에 빈칸이 하나라도 있으면 돌의 갯수 초기화
//	if (flag) {
//		cnt = 0;
//	}
//	return cnt;
//}
//
//int cal() {
//	int count = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			//상대방돌이 있고 방문하지 않은 곳이라면
//			if (map[i][j] == 2 && visit[i][j] == false) {
//				count = count + bfs(i, j); //돌의 갯수를 저장
//			}
//		}
//	}
//	return count;
//}
//
//bool check(int c, int r) {
//	//4방 탐색
//	for (int i = 0; i < 4; i++) {
//		int nc = c + dc[i];
//		int nr = r + dr[i];
//		//맵안에 있고 주변에 상대의 돌이 있으면 true 반환
//		if (nc >= 0 && nc < N && nr >= 0 && nr < M && map[nc][nr] == 2) {
//			return true;
//		}
//	}
//	//주변에 상대의 돌이 없으면 false 반환
//	return false;
//}
//
//
//void solve(int n, int idx) {
//	//돌을 2개 놓으면
//	if (n == 2) {
//		//돌을 놓을 칸에 돌을 놓았다고 처리
//		map[answer.at(0).first][answer.at(0).second] = 1;
//		map[answer.at(1).first][answer.at(1).second] = 1;
//		result = max(result, cal()); //죽인 돌의 갯수 최대 값을 저장
//		init(); //visit 배열 초기화
//		//원상 복귀
//		map[answer.at(0).first][answer.at(0).second] = 0;
//		map[answer.at(1).first][answer.at(1).second] = 0;
//		return;
//	}
//
//	//조합(빈칸들을 저장해놓은 벡터를 탐색)
//	for (int i = idx; i < v.size(); i++) {
//		int c = v.at(i).first;
//		int r = v.at(i).second;
//		if (check(c, r)) {
//			answer.push_back(make_pair(c, r)); //돌을 놓을 칸을 저장
//			solve(n + 1, i + 1); //재귀
//			answer.pop_back(); //원상복귀
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
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> map[i][j];
//			if (map[i][j] == 0) {
//				v.push_back(make_pair(i, j)); //빈칸을 모두 저장
//			}
//		}
//	}
//
//	solve(0,0);
//
//	cout << result << "\n";
//	
//	return 0;
//}