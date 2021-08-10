//#include<iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//char map[50][50];
//queue <pair <pair <int, int>, pair <int, int> > >  q;
//int dc[4] = {-1,0,1,0};
//int dr[4] = {0,1,0,-1};
//int N, M;
//bool visit[128][50][50]; 
//
//int solve() {
//	while (!q.empty())
//	{
//		int c = q.front().first.first;
//		int r = q.front().first.second;
//		int cnt = q.front().second.first;
//		int key = q.front().second.second;
//		q.pop();
//		//현재 위치가 출구이면 종료
//		if (map[c][r] == '1') {
//			return cnt;
//		}
//		//사방 탐색
//		for (int i = 0; i < 4; i++) {
//			int nc = c + dc[i];
//			int nr = r + dr[i];
//			//탐색한 위치가 맵안에 있고 벽이 아니고 방문하지 않은 곳이라면
//			if (nc >= 0 && nc < N && nr >= 0 && nr < M && map[nc][nr] != '#' && !visit[key][nc][nr]) {
//				//탐색한 위치에 'a'키가 있으면
//				if (map[nc][nr] == 'a') {
//					int nkey = key | 1; //현재 가지고 있는 키와 or 연산(현재 가지고 있는 키 최신화)
//					q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, nkey))); //큐에 저장
//					visit[nkey][nc][nr] = true; //방문 표시
//				}
//				//탐색한 위치에 'b'키가 있으면
//				else if (map[nc][nr] == 'b') {
//					int nkey = key | (1 << 1); //현재 가지고 있는 키와 or 연산(현재 가지고 있는 키 최신화)
//					q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, nkey))); //큐에 저장
//					visit[nkey][nc][nr] = true;
//				}
//				//탐색한 위치에 'c'키가 있으면
//				else if (map[nc][nr] == 'c') {
//					int nkey = key | (1 << 2); //현재 가지고 있는 키와 or 연산(현재 가지고 있는 키 최신화)
//					q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, nkey))); //큐에 저장
//					visit[nkey][nc][nr] = true; //방문 표시
//				}
//				//탐색한 위치에 'd'키가 있으면
//				else if (map[nc][nr] == 'd') {
//					int nkey = key | (1 << 3); //현재 가지고 있는 키와 or 연산(현재 가지고 있는 키 최신화)
//					q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, nkey))); //큐에 저장
//					visit[nkey][nc][nr] = true; //방문 표시
//				} 
//				//탐색한 위치에 'e'키가 있으면
//				else if (map[nc][nr] == 'e') {
//					int nkey = key | (1 << 4); //현재 가지고 있는 키와 or 연산(현재 가지고 있는 키 최신화)
//					q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, nkey))); //큐에 저장
//					visit[nkey][nc][nr] = true; //방문 표시
//				}
//				//탐색한 위치에 'f'키가 있으면
//				else if (map[nc][nr] == 'f') {
//					int nkey = key | (1 << 5); //현재 가지고 있는 키와 or 연산(현재 가지고 있는 키 최신화)
//					q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, nkey))); //큐에 저장
//					visit[nkey][nc][nr] = true; //방문 표시
//				}
//				//탐색한 위치에 'A'문이 있으면
//				else if (map[nc][nr] == 'A') {
//					//현재 가지고 있는 키와 and 연산을 한 값이 true이면(해당문의 키를 가지고 있으면)
//					if (key & 1) {
//						q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, key))); //큐에 저장
//						visit[key][nc][nr] = true; //방문 표시
//					}
//				}
//				//탐색한 위치에 'B'문이 있으면
//				else if (map[nc][nr] == 'B') {
//					//현재 가지고 있는 키와 and 연산을 한 값이 true이면(해당문의 키를 가지고 있으면)
//					if (key & (1 << 1)) {
//						q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, key))); //큐에 저장
//						visit[key][nc][nr] = true; //방문 표시
//					}
//				}
//				//탐색한 위치에 'C'문이 있으면
//				else if (map[nc][nr] == 'C') {
//					//현재 가지고 있는 키와 and 연산을 한 값이 true이면(해당문의 키를 가지고 있으면)
//					if (key & (1 << 2)) {
//						q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, key))); //큐에 저장
//						visit[key][nc][nr] = true; //방문 표시
//					}
//				}
//				//탐색한 위치에 'D'문이 있으면
//				else if (map[nc][nr] == 'D') {
//					//현재 가지고 있는 키와 and 연산을 한 값이 true이면(해당문의 키를 가지고 있으면)
//					if (key & (1 << 3)) {
//						q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, key))); //큐에 저장
//						visit[key][nc][nr] = true; //방문 표시
//					}
//				}
//				//탐색한 위치에 'E'문이 있으면
//				else if (map[nc][nr] == 'E') {
//					//현재 가지고 있는 키와 and 연산을 한 값이 true이면(해당문의 키를 가지고 있으면)
//					if (key & (1 << 4)) {
//						q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, key))); //큐에 저장
//						visit[key][nc][nr] = true; //방문 표시
//					}
//				}
//				//탐색한 위치에 'F'문이 있으면
//				else if (map[nc][nr] == 'F') {
//					//현재 가지고 있는 키와 and 연산을 한 값이 true이면(해당문의 키를 가지고 있으면)
//					if (key & (1 << 5)) {
//						q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, key))); //큐에 저장
//						visit[key][nc][nr] = true; //방문 표시
//					}
//				}
//				//탐색한 위치가 빈칸이거나 출발 위치인 경우
//				else {
//					q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, key))); //큐에 저장
//					visit[key][nc][nr] = true; //방문 표시
//				}
//			}
//		}
//	}
//
//	//출구에 도달하지 못하는 경우 -1 return
//	return -1;
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
//			//시작 위치 큐에 저장
//			if (map[i][j] == '0') {
//				q.push(make_pair(make_pair(i, j), make_pair(0,0)));
//				visit[0][i][j] = true;
//				map[i][j] = '.';
//			}
//		}
//	}
//	cout << solve() << "\n";
//
//	return 0;
//}