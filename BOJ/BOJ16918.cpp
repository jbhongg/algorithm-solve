//#include<iostream>
//
//using namespace std;
//
//char map[200][200];
//int R, C, N;
//int dc[4] = {-1,0,1,0};
//int dr[4] = {0,1,0,-1};
//
//void bomb(char c) {
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			//���� �ð��� ���� ��ź�� ������
//			if (map[i][j] == c) {
//				map[i][j] = '.'; //��ĭ���� ����� �ְ� ��� Ž��
//				for (int k = 0; k < 4; k++) {
//					int nc = i + dc[k];
//					int nr = j + dr[k];
//					//�ʾȿ� �ְ� ���� �ð��� ���� ��ź�� �ƴ϶��(���� �ð��� ���� ��ź�� ��� Ž���� ��Ʈ���� �� ��ġ���� ��� Ž���� �� �� ����)
//					if (nc >= 0 && nc < R && nr >= 0 && nr < C && map[nc][nr] != c) {
//						map[nc][nr] = '.'; //��ĭ���� �������
//					}
//				}
//			}
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> R >> C >> N;
//
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			cin >> map[i][j];
//			//��ó�� ��ź�� 3�ʵڿ� �����Ƿ� 3ǥ��
//			if (map[i][j] == 'O') {
//				map[i][j] = '3';
//			}
//		}
//	}
//
//	for (int k = 2; k <= N; k++) {
//		//¦�� �ð����� ��ź�� ��ġ
//		if (k % 2 == 0) {
//			for (int i = 0; i < R; i++) {
//				for (int j = 0; j < C; j++) {
//					//��ĭ�̸�
//					if (map[i][j] == '.') {
//						map[i][j] = char((k+3) + '0'); //���� �ð����� 3�� �ڿ� ������ ��ź�� ǥ��
//					}
//				}
//			}
//		}
//		//Ȧ�� �ð����� ����
//		else {
//			bomb(char(k + '0')); //���� �ð��� ���ڷ� ������ ��
//		}
//	}
//	//��ĭ�� �ƴѰ�쿡�� ��� ��ź�̹Ƿ� 'O'�� �ٽ� ǥ�� �� ���
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			if (map[i][j] != '.') {
//				map[i][j] = 'O';
//			}
//			cout << map[i][j];
//		}
//		cout << "\n";
//	}
//
//	return 0;
//}