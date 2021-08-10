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
//		//�̵� Ƚ���� 10qhek ũ�� -1 ���
//		if (cnt > 10) {
//			return -1;
//		}
//		//���� �������� ��ġ�� ������ ��ġ�̰� �������� �Ķ����� ��ġ�� ���� �ٸ��ٸ� ���
//		if (map[rc][rr] == 'O' && map[rc][rr] != map[bc][br]) {
//			return cnt;
//		}
//		//��� Ž��
//		for (int i = 0; i < 4; i++) {
//			int nrc = rc;
//			int nrr = rr;
//			int nbc = bc;
//			int	nbr = br;
//			//���� �������� ���� ĭ�� ���� �ƴϰ� ���� ĭ�� ��ĭ�� �ƴϸ� ���� ���� �̵�
//			while (map[nrc + dc[i]][nrr + dr[i]] != '#' && map[nrc][nrr] != 'O') {
//				nrc = nrc + dc[i];
//				nrr = nrr + dr[i];
//			}
//			//���� �������� ���� ĭ�� ���� �ƴϰ� ���� ĭ�� ��ĭ�� �ƴϸ� �Ķ� ���� �̵�
//			while (map[nbc + dc[i]][nbr + dr[i]] != '#' && map[nbc][nbr] != 'O') {
//				nbc = nbc + dc[i];
//				nbr = nbr + dr[i];
//			}
//			//�̵��� ���� ������ �Ķ� ������ ���� ��ġ���
//			if (nrc == nbc && nrr == nbr) {
//				//���� ������ ��ġ�� �����̸� ���� ����
//				if (map[nrc][nrr] == 'O') {
//					continue;
//				}
//				// ������ġ�κ����� �̵� ���̰� �Ķ������� ������������ ũ��(�Ķ������� ������������ �ڿ��־��ٴ� �ǹ�)
//				if (abs(nrc - rc) + abs(nrr - rr) < abs(nbc - bc) + abs(nbr - br)) {
//					//�Ķ� ������ ��ġ�� ������⿡�� ��ĭ ��ĭ���� �̵�
//					nbc = nbc - dc[i];
//					nbr = nbr - dr[i];
//				}
//				// ������ġ�κ����� �̵� ���̰� �Ķ������� ������������ ������(�Ķ������� ������������ �տ� �־��ٴ� �ǹ�)
//				else {
//					//���� ������ ��ġ�� ������⿡�� ��ĭ ��ĭ���� �̵�
//					nrc = nrc - dc[i];
//					nrr = nrr - dr[i];
//				}
//			}
//			//�湮�߾������ ���� ����
//			if (visit[nrc][nrr][nbc][nbr] == true) {
//				continue;
//			}
//			//�湮���� �ʾҴ� ���̶�� ť�� �����ϰ� �湮 ǥ��
//			ball.red.first = nrc;
//			ball.red.second = nrr;
//			ball.blue.first = nbc;
//			ball.blue.second = nbr;
//			ball.count = cnt + 1;
//			q.push(ball);
//			visit[nrc][nrr][nbc][nbr] == true;
//		}
//	}
//	//�Ұ����ص� -1 ���
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
//			//�Ķ� ������ �ʱ� ��ġ �����ϰ� ��ĭ���� �ٲ���
//			if (map[i][j] == 'B') {
//				ball.blue.first = i;
//				ball.blue.second = j;
//				map[i][j] = '.';
//			}
//			//���� ������ �ʱ� ��ġ ���� ��ĭ���� �ٲ���
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