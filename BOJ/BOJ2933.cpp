//#include<iostream>
//
//using namespace std;
//
//char map[100][100], temp[100][100];
//int R, C, N;
//int dc[4] = { -1,0,1,0 };
//int dr[4] = { 0,1,0,-1 };
//bool visit[100][100];
//
//void init() {
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			visit[i][j] = false;
//		}
//	}
//}
//
//void back() {
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			map[i][j] = temp[i][j];
//		}
//	}
//}
//
//void cop() {
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			temp[i][j] = map[i][j];
//		}
//	}
//}
//
//void move(int n) {
//	//�󺧸� ��ȣ��ŭ Ž��
//	for (int k = 1; k < n; k++) {
//		bool flag = false;
//		while (!flag) {
//			//�Ʒ������� Ž��
//			for (int i = R - 1; i >= 0; i--) {
//				for (int j = 0; j < C; j++) {
//					//���� ��ġ�� ���� �� ��ȣ���
//					if (map[i][j] == (char)k) {
//						//���� ��ġ���� �ϳ� �Ʒ� ���� �� �ٱ��̸� ���� �� ���� �� Ž��
//						if (i + 1 < 0 || i + 1 >= R) {
//							flag = true; 
//							break;
//						}
//						//���� ��ġ���� �ϳ� �Ʒ� ���� �� �ȿ� ������
//						else {
//							//�Ʒ� ���� ��ĭ�̶��
//							if (map[i + 1][j] == '.') {
//								//���� ���� �Ʒ� ������ �̵�
//								map[i + 1][j] = map[i][j];
//								map[i][j] = '.'; //���� ��ġ�� ��ĭ���� �ٲ���
//							}
//							//�Ʒ� ���� ��ĭ�� �ƴϸ� ���� �� ���� �� Ž��
//							else {
//								flag = true;
//								break;
//							}
//						}
//					}
//
//				}
//				//�̵��� �Ұ����Ͽ� ���� �� Ž�� �����̸�
//				if (flag) {
//					back(); //�� ���󺹱�
//					break;
//				}
//			}
//			//���� ���� ��� �̳׶��� �̵��� �����ϸ�
//			if (!flag) {
//				cop(); //temp �迭�� ���� �� ����
//			}
//		}
//
//	}
//}
//
//void dfs(int c, int r, int num) {
//	//4��Ž��
//	for (int i = 0; i < 4; i++) {
//		int nc = c + dc[i];
//		int nr = r + dr[i];
//		//Ž���� ��ġ�� �� �ȿ� �ְ� �湮���� �ʾҴ� ���̰� �̳׶��̶��
//		if (nc >= 0 && nc < R && nr >= 0 && nr < C && map[nc][nr] != '.' && visit[nc][nr] == false) {
//			visit[c][r] = true;     //�湮�ߴٰ� ǥ��
//			map[c][r] = (char)num;  //�ش� ��ġ�� ���� �󺧸� ��ȣ �󺧸�
//			temp[c][r] = (char)num;
//			dfs(nc, nr, num);
//		}
//	}
//	visit[c][r] = true;    //���� ��ġ�� �湮�ߴٰ� ǥ��
//	map[c][r] = (char)num; //�ش� ��ġ�� ���� �󺧸� ��ȣ �󺧸�
//	temp[c][r] = (char)num;
//
//}
//
//void label() {
//	int num = 1; //�󺧸� ���� ��ȣ
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			//�̳׶��� �߰��߰� �󺧸� ���� ���� ���̶��
//			if (map[i][j] != '.' && visit[i][j] == false) {
//				dfs(i, j, num++);
//			}
//		}
//	}
//	move(num);
//}
//
//void bomb(int dir, int h) {
//	//������ ���
//	if (dir == 1) {
//		for (int i = 0; i < C; i++) {
//			//�̳׶��� �߰��ϸ�
//			if (map[R - h][i] != '.') {
//				map[R - h][i] = '.'; //�̳׶��� ��ĭ���� �������
//				temp[R - h][i] = '.';
//				break;
//			}
//		}
//		label();
//	}
//	//�������� ���
//	else if (dir == 2) {
//		for (int i = C-1; i >= 0; i--) {
//			//�̳׶��� �߰��ϸ�
//			if (map[R - h][i] != '.') {
//				map[R - h][i] = '.'; //�̳׶��� ��ĭ���� �������
//				temp[R - h][i] = '.';
//				break;
//			}
//		}
//		label();
//	}
// }
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> R >> C;
//
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			cin >> map[i][j];
//			temp[i][j] = map[i][j];
//		}
//	}
//
//	cin >> N;
//
//	for (int i = 1; i <= N; i++) {
//		int h;
//		cin >> h;
//		init(); //visit �迭 �ʱ�ȭ
//		if (i % 2 == 1) {
//			bomb(1, h); //���ʿ��� ���븦 ������ ���
//		}
//		else {
//			bomb(2, h); //�����ʿ��� ���븦 ������ ���
//		}
//
//	}
//
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			//��ĭ�� �ƴ϶�� �̳׶��̹Ƿ�
//			if (map[i][j] != '.') {
//				map[i][j] = 'x'; //�̳׶� ǥ�ø� x�� �ٽ� �ٲ���
//			}
//			cout << map[i][j];
//		}
//		cout << "\n";
//	}
//	
//	return 0;
//}