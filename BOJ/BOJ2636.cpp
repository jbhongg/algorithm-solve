//#include<iostream>
//
//using namespace std;
//
//int map[100][100];
//int dc[4] = {-1,0,1,0};
//int dr[4] = {0,1,0,-1};
//int n, m, cnt, time, total;
//
//void check(int c, int r) {
//	//��� Ž��
//	for (int i = 0; i < 4; i++) {
//		int nc = c + dc[i];
//		int nr = r + dr[i];
//		//�̵��� ��ġ�� �ʾȿ� �ְ� ������
//		if (nc >= 0 && nc < n && nr >= 0 && nr < m && map[nc][nr] == -1) {
//			cnt++; //��� ġ���̹Ƿ� ���� ����
//			map[c][r] = 0; //���� ��ġ�� 0���� ǥ��(ġ� ����) �� ����
//			return;
//		}
//	}
//}
//
//void label(int c, int r) {
//	//���� ��ġ�� -1�� ǥ��(ġ� ���� �� �ִ� ������ ���� ǥ��)
//	map[c][r] = -1;
//	//��� Ž��
//	for (int i = 0; i < 4; i++) {
//		int nc = c + dc[i];
//		int nr = r + dr[i];
//		//�̵��� ��ġ�� �ʾȿ� �ְ� ������ ���
//		if (nc >= 0 && nc < n && nr >= 0 && nr < m && map[nc][nr] == 0) {
//			label(nc, nr);
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> n >> m;
//	
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> map[i][j];
//			//�ʱ� ġ�� ���� ���� ����
//			if (map[i][j] == 1) {
//				total++;
//			}
//		}
//	}
//	label(0,0); //�ʱ� �󺧸�(����)
//	while (true) {
//		cnt = 0; //���� ġ� �������� ���� �ʱ�ȭ
//		//���� ġ�� Ž��
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				if (map[i][j] == 1) {
//					check(i,j); //���� ġ� ���� ġ�������� �Ǵ��ϱ� ���� �Լ�
//				}
//			}
//		}
//		//���� ġ� ��� ���� �� ġ� ���� �� �ִ� ���⸦ Ž��
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				//���⸦ ������
//				if (map[i][j] == 0) {
//					//��� Ž��
//					for (int k = 0; k < 4; k++) {
//						int nc = i + dc[k];
//						int nr = j + dr[k];
//						//�̵��� ��ġ�� �ʾȿ� �ְ� ġ� ���� �� �ִ� ������
//						if (nc >= 0 && nc < n && nr >= 0 && nr < m && map[nc][nr] == -1) {
//							label(i,j); //���� ��ġ �󺧸�
//						}
//					}
//				}
//			}
//		}
//		time++; //�ð� ����
//		//���� ġ�� �������� ���� ġ����� ������ 0�̶��(ġ� ��� ��Ҵٴ� ���� �ǹ�) ����
//		if ((total - cnt) == 0) {
//			break;
//		}
//		total = total - cnt; //�ƴϸ� ���� ġ�� �� ����
//	}
//
//	cout << time << "\n" << cnt << "\n";
//
//	return 0;
//}