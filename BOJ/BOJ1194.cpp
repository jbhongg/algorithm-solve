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
//		//���� ��ġ�� �ⱸ�̸� ����
//		if (map[c][r] == '1') {
//			return cnt;
//		}
//		//��� Ž��
//		for (int i = 0; i < 4; i++) {
//			int nc = c + dc[i];
//			int nr = r + dr[i];
//			//Ž���� ��ġ�� �ʾȿ� �ְ� ���� �ƴϰ� �湮���� ���� ���̶��
//			if (nc >= 0 && nc < N && nr >= 0 && nr < M && map[nc][nr] != '#' && !visit[key][nc][nr]) {
//				//Ž���� ��ġ�� 'a'Ű�� ������
//				if (map[nc][nr] == 'a') {
//					int nkey = key | 1; //���� ������ �ִ� Ű�� or ����(���� ������ �ִ� Ű �ֽ�ȭ)
//					q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, nkey))); //ť�� ����
//					visit[nkey][nc][nr] = true; //�湮 ǥ��
//				}
//				//Ž���� ��ġ�� 'b'Ű�� ������
//				else if (map[nc][nr] == 'b') {
//					int nkey = key | (1 << 1); //���� ������ �ִ� Ű�� or ����(���� ������ �ִ� Ű �ֽ�ȭ)
//					q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, nkey))); //ť�� ����
//					visit[nkey][nc][nr] = true;
//				}
//				//Ž���� ��ġ�� 'c'Ű�� ������
//				else if (map[nc][nr] == 'c') {
//					int nkey = key | (1 << 2); //���� ������ �ִ� Ű�� or ����(���� ������ �ִ� Ű �ֽ�ȭ)
//					q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, nkey))); //ť�� ����
//					visit[nkey][nc][nr] = true; //�湮 ǥ��
//				}
//				//Ž���� ��ġ�� 'd'Ű�� ������
//				else if (map[nc][nr] == 'd') {
//					int nkey = key | (1 << 3); //���� ������ �ִ� Ű�� or ����(���� ������ �ִ� Ű �ֽ�ȭ)
//					q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, nkey))); //ť�� ����
//					visit[nkey][nc][nr] = true; //�湮 ǥ��
//				} 
//				//Ž���� ��ġ�� 'e'Ű�� ������
//				else if (map[nc][nr] == 'e') {
//					int nkey = key | (1 << 4); //���� ������ �ִ� Ű�� or ����(���� ������ �ִ� Ű �ֽ�ȭ)
//					q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, nkey))); //ť�� ����
//					visit[nkey][nc][nr] = true; //�湮 ǥ��
//				}
//				//Ž���� ��ġ�� 'f'Ű�� ������
//				else if (map[nc][nr] == 'f') {
//					int nkey = key | (1 << 5); //���� ������ �ִ� Ű�� or ����(���� ������ �ִ� Ű �ֽ�ȭ)
//					q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, nkey))); //ť�� ����
//					visit[nkey][nc][nr] = true; //�湮 ǥ��
//				}
//				//Ž���� ��ġ�� 'A'���� ������
//				else if (map[nc][nr] == 'A') {
//					//���� ������ �ִ� Ű�� and ������ �� ���� true�̸�(�ش繮�� Ű�� ������ ������)
//					if (key & 1) {
//						q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, key))); //ť�� ����
//						visit[key][nc][nr] = true; //�湮 ǥ��
//					}
//				}
//				//Ž���� ��ġ�� 'B'���� ������
//				else if (map[nc][nr] == 'B') {
//					//���� ������ �ִ� Ű�� and ������ �� ���� true�̸�(�ش繮�� Ű�� ������ ������)
//					if (key & (1 << 1)) {
//						q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, key))); //ť�� ����
//						visit[key][nc][nr] = true; //�湮 ǥ��
//					}
//				}
//				//Ž���� ��ġ�� 'C'���� ������
//				else if (map[nc][nr] == 'C') {
//					//���� ������ �ִ� Ű�� and ������ �� ���� true�̸�(�ش繮�� Ű�� ������ ������)
//					if (key & (1 << 2)) {
//						q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, key))); //ť�� ����
//						visit[key][nc][nr] = true; //�湮 ǥ��
//					}
//				}
//				//Ž���� ��ġ�� 'D'���� ������
//				else if (map[nc][nr] == 'D') {
//					//���� ������ �ִ� Ű�� and ������ �� ���� true�̸�(�ش繮�� Ű�� ������ ������)
//					if (key & (1 << 3)) {
//						q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, key))); //ť�� ����
//						visit[key][nc][nr] = true; //�湮 ǥ��
//					}
//				}
//				//Ž���� ��ġ�� 'E'���� ������
//				else if (map[nc][nr] == 'E') {
//					//���� ������ �ִ� Ű�� and ������ �� ���� true�̸�(�ش繮�� Ű�� ������ ������)
//					if (key & (1 << 4)) {
//						q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, key))); //ť�� ����
//						visit[key][nc][nr] = true; //�湮 ǥ��
//					}
//				}
//				//Ž���� ��ġ�� 'F'���� ������
//				else if (map[nc][nr] == 'F') {
//					//���� ������ �ִ� Ű�� and ������ �� ���� true�̸�(�ش繮�� Ű�� ������ ������)
//					if (key & (1 << 5)) {
//						q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, key))); //ť�� ����
//						visit[key][nc][nr] = true; //�湮 ǥ��
//					}
//				}
//				//Ž���� ��ġ�� ��ĭ�̰ų� ��� ��ġ�� ���
//				else {
//					q.push(make_pair(make_pair(nc, nr), make_pair(cnt + 1, key))); //ť�� ����
//					visit[key][nc][nr] = true; //�湮 ǥ��
//				}
//			}
//		}
//	}
//
//	//�ⱸ�� �������� ���ϴ� ��� -1 return
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
//			//���� ��ġ ť�� ����
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