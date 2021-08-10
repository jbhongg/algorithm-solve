//#include<iostream>
//
//using namespace std;
//int map[1000][1000];
//int dc[8] = {-1,-1,0,1,1,1,0,-1};
//int dr[8] = {0,1,1,1,0,-1,-1,-1};
////����Ʈ�� �������� Ž���� �迭
//int kc[8] = {-2,-2,-1,1,2,2,1,-1}; 
//int kr[8] = {-1,1,2,2,1,-1,-2,-2};
//int n, m, answer;
//
//void move(int c, int r, int dir) {
//	//�̵��� �������� ���� ��� �� ����
//	int nc = c + dc[dir]; 
//	int nr = r + dr[dir];
//	while (true) {
//		//�̵��� ��� ���� ���� ����ų� �̵��� ��ġ�� ��ĭ�� �ƴ϶�� ����
//		if (nc < 0 || nc >= n || nr < 0 || nr >= m || map[nc][nr] > 0) {
//			break;
//		}
//		//�ʾȿ� ������ �̵��� ��ġ�� -1�� ǥ��
//		else {
//			map[nc][nr] = -1;
//		}
//		//���� ��� �� ����
//		nc = nc + dc[dir];
//		nr = nr + dr[dir];
//	}
//	//�̵��� ������ ���� ���� �ݴ�� ����
//	dir = dir + 4;
//	//���� �ִ� ��ġ���� �̵��� �������� ���� ��� �� ����
//	nc = c + dc[dir];
//	nr = r + dr[dir];
//	while (true) {
//		//�̵��� ��� ���� ���� ����ų� �̵��� ��ġ�� ��ĭ�� �ƴ϶�� ����
//		if (nc < 0 || nc >= n || nr < 0 || nr >= m || map[nc][nr] > 0) {
//			break;
//		}
//		//�ʾȿ� ������ �̵��� ��ġ�� -1�� ǥ��
//		else {
//			map[nc][nr] = -1;
//		}
//		//���� ��� �� ����
//		nc = nc + dc[dir];
//		nr = nr + dr[dir];
//	}
//}
//
//void knight(int c, int r) {
//	//8�� Ž��(����Ʈ�� ������ �� �ִ� ��)
//	for (int i = 0; i < 8; i++) {
//		//�̵��� ��� �� ����
//		int nc = c + kc[i];
//		int nr = r + kr[i];
//		//�̵��� ��� ���� �ʾȿ� �ְ� ��ĭ�̶�� -1 ǥ��
//		if (nc >= 0 && nc < n && nr >= 0 && nr < m && map[nc][nr] == 0) {
//			map[nc][nr] = -1;
//		}
//	}
//
//}
//
//void queen(int c, int r) {
//	//��� Ž��(8���ε� 4�� �ݴ밡 4���̹Ƿ�)
//	for (int i = 0; i < 4; i++) {
//		//���� ��� �� ������ ���� ������ ������ �Լ� �̵�
//		move(c, r, i);
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int qn, x, y, kn, pn;
//
//
//	cin >> n >> m;
//	cin >> qn;
//	//���� 1�� �ʿ� ǥ��
//	for (int i = 0; i < qn; i++) {
//		cin >> x >> y;
//		map[x - 1][y - 1] = 1;
//	}
//	cin >> kn;
//	//����Ʈ�� 2�� �ʿ� ǥ��
//	for (int i = 0; i < kn; i++) {
//		cin >> x >> y;
//		map[x - 1][y - 1] = 2;
//	}
//	cin >> pn;
//	//���� 3���� �ʿ� ǥ��
//	for (int i = 0; i < pn; i++) {
//		cin >> x >> y;
//		map[x - 1][y - 1] = 3;
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			//���� ������ �Լ� �̵�
//			if (map[i][j] == 1) {
//				queen(i, j);
//			}
//			//����Ʈ�� ������ �Լ� �̵�
//			if (map[i][j] == 2) {
//				knight(i, j);
//			}
//		}
//	}
//
//	//��ĭ�� ���� ����
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (map[i][j] == 0) {
//				answer++;
//			}
//		}
//	}
//
//	cout << answer << "\n";
//
//	return 0;
//}