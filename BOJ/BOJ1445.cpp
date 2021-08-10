//#include<iostream>
//#include<queue>
//#include<limits.h>
//
//using namespace std;
//
//int N, M;
//char map[50][50];
//int dc[4] = {-1,0,1,0};
//int dr[4] = {0,1,0,-1};
//priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>> > pq;
//pair <int, int> p[50][50];
//
//void solve() {
//	while (!pq.empty()) {
//		int g = pq.top().first.first;
//		int x = pq.top().first.second;
//		int c = pq.top().second.first;
//		int r = pq.top().second.second;
//		pq.pop();
//		//4방 탐색
//		for (int i = 0; i < 4; i++) {
//			int nc = c + dc[i];
//			int nr = r + dr[i];
//			//탐색 위치가 맵안에 있으면
//			if (nc >= 0 && nr >= 0 && nc < N && nr < M) {
//				//탐색 위치가 쓰레기라면
//				if (map[nc][nr] == 'g') {
//					//탐색위치의 쓰레기값보다 현재 위치를 거쳐 간 쓰레기 값이 작으면 
//					if (p[nc][nr].first > g + 1) {
//						p[nc][nr].first = g + 1; //탐색위치의 쓰레기값을  현재 위치를 거쳐 간 쓰레기 값으로 바꿔서 저장
//						p[nc][nr].second = x; //탐색위치의 쓰레기 주변 값을 현재 위치를 거쳐 간 쓰레기 주변 값으로 바꿔서 저장
//						pq.push(make_pair(make_pair(g+1, x), make_pair(nc, nr))); //큐에 저장
//					}
//					//탐색위치의 쓰레기값과 현재 위치를 거쳐 간 쓰레기 값이 같으면
//					else if (p[nc][nr].first == g + 1) {
//						//탐색위치의 쓰레기 주변값보다 현재 위치를 거쳐 간 쓰레기 주변값이 작으면
//						if (p[nc][nr].second > x) {
//							p[nc][nr].first = g + 1; //탐색위치의 쓰레기값을  현재 위치를 거쳐 간 쓰레기 값으로 바꿔서 저장
//							p[nc][nr].second = x; //탐색위치의 쓰레기 주변 값을 현재 위치를 거쳐 간 쓰레기 주변 값으로 바꿔서 저장
//							pq.push(make_pair(make_pair(g + 1, x), make_pair(nc, nr))); //큐에 저장
//						}
//					}
//				}
//				//탐색 위치가 쓰레기 주변이라면
//				else if (map[nc][nr] == 'X') {
//					//탐색위치의 쓰레기값보다 현재 위치를 거쳐 간 쓰레기 값이 작으면 
//					if (p[nc][nr].first > g) {
//						p[nc][nr].first = g; //탐색위치의 쓰레기값을  현재 위치를 거쳐 간 쓰레기 값으로 바꿔서 저장
//						p[nc][nr].second = x+1; //탐색위치의 쓰레기 주변 값을 현재 위치를 거쳐 간 쓰레기 주변 값으로 바꿔서 저장
//						pq.push(make_pair(make_pair(g, x+1), make_pair(nc, nr))); //큐에 저장
//					}
//					//탐색위치의 쓰레기값과 현재 위치를 거쳐 간 쓰레기 값이 같으면
//					else if (p[nc][nr].first == g) {
//						//탐색위치의 쓰레기 주변값보다 현재 위치를 거쳐 간 쓰레기 주변값이 작으면
//						if (p[nc][nr].second > x+1) {
//							p[nc][nr].first = g; //탐색위치의 쓰레기값을  현재 위치를 거쳐 간 쓰레기 값으로 바꿔서 저장
//							p[nc][nr].second = x+1; //탐색위치의 쓰레기 주변 값을 현재 위치를 거쳐 간 쓰레기 주변 값으로 바꿔서 저장
//							pq.push(make_pair(make_pair(g, x+1), make_pair(nc, nr))); //큐에 저장
//						}
//					}
//				}
//				//탐색 위치가 쓰레기도 아니고 쓰레기 주변도 아니라면
//				else{
//					//탐색위치의 쓰레기값보다 현재 위치를 거쳐 간 쓰레기 값이 작으면 
//					if (p[nc][nr].first > g) {
//						p[nc][nr].first = g; //탐색위치의 쓰레기값을  현재 위치를 거쳐 간 쓰레기 값으로 바꿔서 저장
//						p[nc][nr].second = x; //탐색위치의 쓰레기 주변 값을 현재 위치를 거쳐 간 쓰레기 주변 값으로 바꿔서 저장
//						pq.push(make_pair(make_pair(g, x), make_pair(nc, nr))); //큐에 저장
//					}
//					//탐색위치의 쓰레기값과 현재 위치를 거쳐 간 쓰레기 값이 같으면
//					else if (p[nc][nr].first == g) {
//						//탐색위치의 쓰레기 주변값보다 현재 위치를 거쳐 간 쓰레기 주변값이 작으면
//						if (p[nc][nr].second > x) {
//							p[nc][nr].first = g; //탐색위치의 쓰레기값을  현재 위치를 거쳐 간 쓰레기 값으로 바꿔서 저장
//							p[nc][nr].second = x; //탐색위치의 쓰레기 주변 값을 현재 위치를 거쳐 간 쓰레기 주변 값으로 바꿔서 저장
//							pq.push(make_pair(make_pair(g, x), make_pair(nc, nr))); // 큐에 저장
//						}
//					}
//				}
//			}
//		}
//
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	cin >> N >> M;
//	int e1 = 0, e2 = 0;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			//맵의 값이 쓰레기이면
//			if (map[i][j] == 'g') {
//				//4방 탐색
//				for (int k = 0; k < 4; k++) {
//					//탐색한 위치가 맵안에 있고 빈칸이라면
//					if (i + dc[k] >= 0 && i + dc[k] < N && j + dr[k] >= 0 && j + dr[k] < M && map[i + dc[k]][j + dr[k]] == '.') {
//						map[i + dc[k]][j + dr[k]] = 'X'; //X표시(쓰레기 옆을 표시)
//					}
//				}
//			}
//			//시작 위치라면
//			else if (map[i][j] == 'S') {
//				pq.push(make_pair(make_pair(0, 0), make_pair(i, j))); //큐에 저장
//				//지나친 쓰레기의 갯수와 지나친 쓰레기 주변의 갯수를 0으로 저장
//				p[i][j].first = 0; 
//				p[i][j].second = 0;
//			}
//			//도착 지점 저장
//			else if (map[i][j] == 'F') {
//				e1 = i;
//				e2 = j;
//			}
//			//시작위치가 아니면
//			if (map[i][j] != 'S') {
//				//지나친 쓰레기의 갯수와 지나친 쓰레기 주변의 갯수를 최댓값으로 저장
//				p[i][j].first = INT_MAX;
//				p[i][j].second = INT_MAX;
//			}
//		}
//	}
//
//	solve();
//
//	cout << p[e1][e2].first << " " << p[e1][e2].second << "\n";
//	
//	return 0;
//}