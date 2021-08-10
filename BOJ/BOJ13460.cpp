//#include <iostream>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//typedef struct Ball
//{
//	pair <int, int> red;
//	pair <int, int> blue;
//	int count;
//}Ball;
//
//int N, M;
//char map[11][11];
//bool visit[10][10][10][10];
//int dc[] = { -1,0,1,0 };
//int dr[] = { 0,1,0,-1 };
//Ball ball;
//
//int bfs() {
//	queue <Ball > q;
//	ball.count = 0;
//	q.push(ball);
//	visit[ball.red.first][ball.red.second][ball.blue.first][ball.blue.second] = true;
//
//	while (!q.empty()) {
//		int rc = q.front().red.first;
//		int rr = q.front().red.second;
//		int bc = q.front().blue.first;
//		int br = q.front().blue.second;
//		int cnt = q.front().count;
//		q.pop();
//		//이동 횟수가 10qhek 크면 -1 출력
//		if (cnt > 10) {
//			return -1;
//		}
//		//현재 빨간공의 위치가 구멍의 위치이고 빨간공과 파란공의 위치가 서로 다르다면 출력
//		if (map[rc][rr] == 'O' && map[rc][rr] != map[bc][br]) {
//			return cnt;
//		}
//		//사방 탐색
//		for (int i = 0; i < 4; i++) {
//			int nrc = rc;
//			int nrr = rr;
//			int nbc = bc;
//			int	nbr = br;
//			//현재 방향으로 다음 칸이 벽이 아니고 현재 칸이 빈칸이 아니면 빨간 구슬 이동
//			while (map[nrc + dc[i]][nrr + dr[i]] != '#' && map[nrc][nrr] != 'O') {
//				nrc = nrc + dc[i];
//				nrr = nrr + dr[i];
//			}
//			//현재 방향으로 다음 칸이 벽이 아니고 현재 칸이 빈칸이 아니면 파란 구슬 이동
//			while (map[nbc + dc[i]][nbr + dr[i]] != '#' && map[nbc][nbr] != 'O') {
//				nbc = nbc + dc[i];
//				nbr = nbr + dr[i];
//			}
//			//이동한 빨간 구슬과 파란 구슬이 같은 위치라면
//			if (nrc == nbc && nrr == nbr) {
//				//빨간 구슬의 위치가 구멍이면 다음 진행
//				if (map[nrc][nrr] == 'O') {
//					continue;
//				}
//				// 기존위치로부터의 이동 길이가 파란구슬이 빨간구슬보다 크면(파란구슬이 빨간구슬보다 뒤에있었다는 의미)
//				if (abs(nrc - rc) + abs(nrr - rr) < abs(nbc - bc) + abs(nbr - br)) {
//					//파란 구슬의 위치를 현재방향에서 한칸 전칸으로 이동
//					nbc = nbc - dc[i];
//					nbr = nbr - dr[i];
//				}
//				// 기존위치로부터의 이동 길이가 파란구슬이 빨간구슬보다 작으면(파란구슬이 빨간구슬보다 앞에 있었다는 의미)
//				else {
//					//빨간 구슬의 위치를 현재방향에서 한칸 전칸으로 이동
//					nrc = nrc - dc[i];
//					nrr = nrr - dr[i];
//				}
//			}
//			//방문했었더라면 다음 진행
//			if (visit[nrc][nrr][nbc][nbr] == true) {
//				continue;
//			}
//			//방문하지 않았던 곳이라면 큐에 저장하고 방문 표시
//			ball.red.first = nrc;
//			ball.red.second = nrr;
//			ball.blue.first = nbc;
//			ball.blue.second = nbr;
//			ball.count = cnt + 1;
//			q.push(ball);
//			visit[nrc][nrr][nbc][nbr] == true;
//		}
//	}
//	//불가능해도 -1 출력
//	return -1;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> map[i][j];
//			//파란 구슬의 초기 위치 저장하고 빈칸으로 바꿔줌
//			if (map[i][j] == 'B') {
//				ball.blue.first = i;
//				ball.blue.second = j;
//				map[i][j] = '.';
//			}
//			//빨간 구슬의 초기 위치 저장 빈칸으로 바꿔줌
//			else if (map[i][j] == 'R') {
//				ball.red.first = i;
//				ball.red.second = j;
//				map[i][j] = '.';
//			}
//		}
//	}
//
//	cout << bfs() << "\n";
//
//	return 0;
//}